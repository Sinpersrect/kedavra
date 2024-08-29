from typing import Tuple

from Env import InferEnv
from Instantiate.SymbolIns import LevelSymbolInstantiator, RandomizedSymbolInstantiator, StaticSymbolInstantiator
from Tokenize import Token
from DataTypes import Grammar,Prod,Rule,Symbol,loadGrammar,loadProd


def testSSI():
    grammar = Grammar('n0',[Rule('n0',[
        Prod('n0',[Symbol(Token('a'))]),
        Prod('n0',[Symbol(Token('b')),Symbol('n0')]),
        ])])
    for _ in range(10):
        tokens = StaticSymbolInstantiator(grammar).instantiate([Symbol(grammar.getStart())])
        assert grammar.getOracle().parse(tokens)
        tokens = RandomizedSymbolInstantiator(grammar).instantiate([Symbol(grammar.getStart())])
        assert grammar.getOracle().parse(tokens)

def testLSI():
    grammar = loadGrammar("""
    start:n0
    n0: ";"
    | n2 ";"
    n2: n2 "=" n1
    | n1
    n1: n1 "-" n1
    | "(" n1 ")"
    | "NUM"
    | n1 "+" n1
    | n1 "<" n1
    | "IDENT"
    """)
    lsi = LevelSymbolInstantiator(StaticSymbolInstantiator(grammar),1)
    assert len(lsi.instantiate(Symbol('n0'))) == 2
    lsi = LevelSymbolInstantiator(StaticSymbolInstantiator(grammar),2)
    assert len(lsi.instantiate(Symbol('n0'))) == 8

def symbols2tokens(symbols:Tuple[Symbol]):
    return tuple(i.getValue() for i in symbols)

def testContext():
    grammar = loadGrammar("""start:n0
n0: "if" "(" "IDENT" ")" "{" "}" "else" ";"
  | "{" "IDENT" ";" "}"
  | "IDENT" "=" "IDENT" ";"
  | "IDENT" "<" n1 ";"
  | ";"
  | n1 ";"
n1: "NUM" ";"
  | "NUM" "-" "IDENT" ";"
  | "IDENT" "+" "NUM" ";"
  | "while" "(" "IDENT" ")" ";"
  | "(" "IDENT" ")" ";"
  | "if" "(" n1 ")" ";"
  | "{" "}"
  | "do" ";" "while" "(" "IDENT" ")" ";" """)
    env = InferEnv(grammar.getOracle())
    session = env.createSession(grammar,loadProd('n0: "if" "(" "IDENT" ")" "{" "}" "else" ";"'))
    tc = StaticSymbolInstantiator(grammar).instantiateContext(session.getContext('n1'))
    assert grammar.getOracle().parse(tc.assembly([Token("NUM"),Token(";")]))