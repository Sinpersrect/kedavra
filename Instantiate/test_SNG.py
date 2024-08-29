from typing import Tuple
from Instantiate.SymbolIns import LevelSymbolInstantiator, RandomizedSymbolInstantiator, StaticSymbolInstantiator
from Instantiate.SyntaxNodeGrow import LevelSNG, RandomizedSNG, StaticSNG
from Tokenize import Token
from DataTypes import Grammar,Prod,Rule,Symbol,loadGrammar,loadProd
from Instantiate.Tree import SyntaxNode

def test_SNG():
    grammar = Grammar('n0',[Rule('n0',[
        Prod('n0',[Symbol(Token('a'))]),
        Prod('n0',[Symbol(Token('b')),Symbol('n0')]),
        ])])
    rsng = RandomizedSNG(grammar)
    ssng = StaticSNG(grammar)
    for _ in range(10):
        tokens = ssng.grow(SyntaxNode(Symbol(grammar.getStart()))).toTokens()
        assert grammar.getOracle().parse(tokens)
        tokens = rsng.grow(SyntaxNode(Symbol(grammar.getStart()))).toTokens()
        assert grammar.getOracle().parse(tokens)

def test_LSNG():
    prod1 = Prod('n0',[Symbol(Token('a'))])
    prod2 = Prod('n0',[Symbol(Token('b')),Symbol('n0')])
    grammar = Grammar('n0',[Rule('n0',[
        prod1,prod2
        ])])
    lsng = LevelSNG(grammar)
    assert len(lsng.grow(SyntaxNode(Symbol(grammar.getStart())))) == 2
    node1 = SyntaxNode(Symbol(grammar.getStart()))
    node1.produce(prod2)
    assert len(lsng.grow(node1)) == 1

    grammar = loadGrammar("""
start:n0                                                                                                                           
n0: "IDENT" "<" "NUM" ";"                                                                                                          
  | ";"                                                                                                                            
  | "IDENT" "=" n2 ";"                                                                                                             
  | n2 ";"                                                                                                                         
n1: "NUM"                                                                                                                          
  | "IDENT"                                                                                                                        
n2: n2 "+" n2                                                                                                                      
  | n1  
""")
    lsng = LevelSNG(grammar)
    assert len(lsng.grow(SyntaxNode(Symbol(grammar.getStart())))) == 4
    node1 = SyntaxNode(Symbol('n2'))
    node1.produce(loadProd(' n2: n2 "+" n2   '))
    assert len(lsng.grow(node1)) == 1
    lsng1 = LevelSNG(grammar,2)
    print()
    for i in lsng1.grow(node1):
        print(i)
        print('======')
    assert len(lsng1.grow(node1)) == 9
    