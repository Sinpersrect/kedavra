"""
将语法组合起来
"""
from typing import Dict, Tuple, Iterable, Collection

from lark import Lark

from DataTypes import Grammar, Prod, SymbolType, Rule, Symbol, ColoredGrammar
from Instantiate.SymbolIns import RandomizedSymbolInstantiator
from Lexical.Generalize import createCharset
from Tokenize import Tokenizer, Token


def isSingle(grammar: Grammar):
    if len(list(grammar.getProds())) != 1:
        return False
    symbols = next(iter(grammar.getProds())).getSymbols()
    for symbol in symbols:
        if symbol.getType() != SymbolType.Default:
            return False
    return True


def translate(symbols: Tuple[Symbol], ntMap):
    ret = []
    for symbol in symbols:
        if symbol.isTerminal():
            ret.append(symbol)
        else:
            ret.append(Symbol(ntMap[symbol.getValue()], symbol.getType()))
    return ret


class MyTokenizer(Tokenizer):
    def tokenize(self, sentence: str) -> Tuple[Token, ...]:
        if not self.__ss:
            sentence = sentence.replace(' ', '')
        ret = []
        for i in self.__lexer.parse(sentence).children:
            for j in i.children:
                for k in j.children:
                    value = sentence[k.meta.start_pos:k.meta.end_pos]
                    t = str(k.data)
                    if t == 'other':
                        ret.append(Token(value, value))
                    else:
                        ret.append(Token(t, value))
        return tuple(ret)

    def instantiateToken(self, token: Token) -> str:
        if token.type() not in self.__lexicalDict:
            return token.type()
        grammar = self.__lexicalDict[token.type()]
        si = RandomizedSymbolInstantiator(grammar)
        return ''.join([i.type() for i in si.instantiate([Symbol(grammar.getStart())])])

    def instantiate(self, tokens: Iterable[Token]) -> str:
        sep = ' '
        if self.__ss:
            sep = ''
        return sep.join([self.instantiateToken(i) for i in tokens])

    def __init__(self, lexicalDict: Dict[str, Grammar], spaceSensitive: bool):
        self.__lexicalDict = lexicalDict
        self.__ss = spaceSensitive
        newGrammar = Grammar('n0', [])
        newGrammar.addProd(Prod('n0', [Symbol('token', SymbolType.Rep1)]))
        newGrammar.addProd(Prod('token', [Symbol('other')]))
        containsOther = False
        for key, value in lexicalDict.items():
            if isSingle(value):
                newGrammar.addProd(Prod('other', next(iter(value.getProds())).getSymbols()))
                containsOther = True
                continue
            ntMap = {}
            for nt in value.getNts():
                if nt == value.getStart():
                    newNt = key
                else:
                    newNt = newGrammar.newNt()
                newGrammar.addRule(Rule(newNt, []))
                ntMap[nt] = newNt
            for prod in value.getProds():
                newGrammar.addProd(Prod(ntMap[prod.getNt()], translate(prod.getSymbols(), ntMap)))
            newGrammar.addProd(Prod('token', (Symbol(key),)))
        if not containsOther:
            newGrammar.removeProd(Prod('token', [Symbol('other')]))
        self.__grammar = newGrammar
        self.__lexer = Lark(str(newGrammar), propagate_positions=True, parser='cyk')


def combineGrammar(mainGrammar: Grammar, lexicalDict: Dict[str, Grammar]):
    mainGrammar = ColoredGrammar(mainGrammar).copy()
    for key, value in lexicalDict.items():
        if isSingle(value):
            continue
        token = Token(key, key)
        refers = mainGrammar.getRefers(token)
        mainGrammar.replaceClauses(refers, (Symbol(key),))
        ntMap = {}
        for nt in value.getNts():
            if nt == value.getStart():
                newNt = key
            else:
                newNt = mainGrammar.newNt()
            mainGrammar.addRule(Rule(newNt, []))
            ntMap[nt] = newNt
        for prod in value.getProds():
            mainGrammar.addProd(Prod(ntMap[prod.getNt()], translate(prod.getSymbols(), ntMap)))
    return mainGrammar


if __name__ == '__main__':
    lexer = Lark("""
start:n0
n0: token+
token: other
  | t0
  | t2
  | t1
other: "do"
  | "="
  | "("
  | "<"
  | ")"
  | ";"
  | "while"
  | "{"
  | "if"
  | "}"
  | "else"
n1: "i"
  | "d"
  | "x"
  | "u"
  | "c"
  | "e"
  | "f"
  | "a"
  | "j"
  | "p"
  | "m"
  | "y"
  | "b"
  | "k"
  | "t"
  | "h"
  | "o"
  | "q"
  | "z"
  | "g"
  | "v"
  | "n"
  | "w"
  | "l"
  | "r"
  | "s"
t0: n1
n2: "-"
  | "+"
t2: n2
n3: "5"
  | "9"
  | "4"
  | "1"
  | "8"
  | "0"
  | "7"
  | "2"
  | "6"
  | "3"
t1: n3+
    """, propagate_positions=True, parser='cyk')
    s = '1230456'
    for i in lexer.parse(s).children:
        for j in i.children:
            for k in j.children:
                value = s[k.meta.start_pos:k.meta.end_pos]
                t = str(k.data)
                print(t, value)

