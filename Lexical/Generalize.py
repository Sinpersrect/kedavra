from typing import Collection

from DataTypes import Grammar, loadGrammar
from DataTypes.__Grammar import T, Rule, Prod, Symbol, Clause, SymbolType
from Instantiate.ContextIns import RandomizedContextInstantiator
from Instantiate.SymbolIns import RandomizedSymbolInstantiator
from Lexical.Index import SeqIndexSet
from Instantiate.Ins import TokenInstantiator, DefaultTokenInstantiator
from Oracle.Raw import RawOracle, LarkOracle
from Tokenize import Token


class IndexesOracle(RawOracle):
    def __init__(self, si: SeqIndexSet, oracle: RawOracle, ti: TokenInstantiator):
        self.__si = si
        self.__oracle = oracle
        self.__ti = ti
        assert len(self.__si.getSeqs(None)) > 0

    def parse(self, sentence: str) -> bool:
        for seq in self.__si.getMultiMaskSeqs([Token(sentence, sentence)]):
            if not self.__oracle.parse(self.__ti.instantiate(seq)):
                return False
        return True

    # 此处可以升级，我们可以同时判断多个值


class CharsetGrammar(Grammar):
    def __init__(self, start: T, rules: Collection[Rule[T]]):
        super().__init__(start, rules)
        self.__charsetMap = {}

    def addCharset(self, charset) -> str:
        nt = self.newNt()
        for k, v in self.__charsetMap.items():
            if charset == v:
                return k
        for v in charset:
            self.addProd(Prod(nt, (Symbol(Token(v)),)))
        self.__charsetMap[nt] = charset
        return nt


def generalizeCharset(charsetGrammar: CharsetGrammar, clause: Clause, charset, oracle: RawOracle,
                      ti: TokenInstantiator):
    ci = RandomizedContextInstantiator(charsetGrammar)
    si = RandomizedSymbolInstantiator(charsetGrammar)
    context = ci.instantiate(clause)
    chars = {clause.getValue()[0].getValue().value()}
    for char in charset:
        if char == clause.getValue()[0].getValue().value():
            continue
        sc = context.assembly([Symbol(Token(char, char))])
        toValidate = ti.instantiate(si.instantiate(sc))
        if oracle.parse(toValidate):
            chars.add(char)
    if len(chars) == 1:
        return clause.getProd()
    nt = charsetGrammar.addCharset(chars)
    return charsetGrammar.replaceClause(clause, (Symbol(nt),))


def generalizeRep(grammar: Grammar, clause: Clause, oracle: RawOracle,
                  ti: TokenInstantiator):
    ci = RandomizedContextInstantiator(grammar)
    si = RandomizedSymbolInstantiator(grammar)
    if clause.isSingleNt():
        values = [i.getSymbols() for i in grammar.getProds(clause.getValueNt())]
    else:
        values = [clause.getValue()]
    for value in values:
        context = ci.instantiate(clause)
        sc = context.assembly(value * 17)
        toValidate = ti.instantiate(si.instantiate(sc))
        if not oracle.parse(toValidate):
            return clause.getProd()
    return grammar.replaceClause(clause, (Symbol(clause.getValue()[0].getValue(), SymbolType.Rep1),))


def createCharset(x):
    start, _, end = x
    ret = ''
    for i in range(ord(start), ord(end) + 1):
        ret += chr(i)
    return ret


def processProd(grammar: Grammar, prod: Prod):
    symbols = []
    for symbol in prod.getSymbols():
        if not symbol.isTerminal():
            symbols.append(symbol)
            continue
        if len(symbols) == 0 or not symbols[-1].isTerminal() or symbol.getType() != SymbolType.Default:
            symbols.append(symbol)
            continue
        newValue = symbols[-1].getValue().value() + symbol.getValue().value()
        symbols[-1] = Symbol(Token(newValue, newValue))
    newProd = Prod(prod.getNt(), symbols)
    grammar.replaceProd(prod, newProd)


def escape(c):
    if c in {'"'}:
        return '\\' + c
    return c


def processGrammarForNum(grammar: Grammar):
    oracle = LarkOracle(str(grammar))
    # 检测是否只有数字[且包含所有数字]
    terminals = set()
    for prod in grammar.getProds():
        for symbol in prod.getSymbols():
            if not symbol.isTerminal():
                continue
            terminals.add(symbol.getValue().value())
    if terminals != set('1234567890'):
        return grammar
    if oracle.parse('0123456789'):
        return loadGrammar("""
        start:n0
        n0: n1+
        n1: "5"
          | "0"
          | "8"
          | "6"
          | "7"
          | "1"
          | "3"
          | "4"
          | "2"
          | "9"
        """)
    if oracle.parse('123456789'):
        return loadGrammar("""
        start:n0
        n0: n2 n1* | "0"
        n1: "5"
          | "0"
          | "8"
          | "6"
          | "7"
          | "1"
          | "3"
          | "4"
          | "2"
          | "9"
        n2: "5"
          | "8"
          | "6"
          | "7"
          | "1"
          | "3"
          | "4"
          | "2"
          | "9"
        """)
    return grammar

