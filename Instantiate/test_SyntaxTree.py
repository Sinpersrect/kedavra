import pytest
from Instantiate.Tree import StaticSyntaxNode, SyntaxNode
from DataTypes import Context, Prod, Rule, Symbol,Grammar,ColoredGrammar,loadGrammar,loadProd
from Tokenize import Token

def test_SyntaxNode():
    sn = SyntaxNode(Symbol('n0'),)
    sn.produce(loadProd('n0: "a" n1 "c" '))
    sn.getChildren()[1].produce(loadProd('n1: "b" '))
    assert sn.toTokens() == (Token('a','a'), Token('b','b'), Token('c','c'))

    sn = SyntaxNode(Symbol(Token('n0')),)
    assert sn.toTokens() == (Token('n0','n0'),)

    sn = SyntaxNode(Symbol('n0'),)
    with pytest.raises(Exception):
        sn.toTokens()

def test_SyntaxNodeEq():
    sn = SyntaxNode(Symbol('n0'),)
    sn.produce(loadProd('n0: "a" n0 "c" '))
    assert sn.getChildren()[1] == SyntaxNode(Symbol('n0'),)

def test_StaticSyntaxNode():
    sn = SyntaxNode(Symbol('n0'),)
    prod = loadProd('n0: "a" n0 "c" ')
    sn.produce(prod)
    ssn = StaticSyntaxNode(sn)
    assert ssn == sn
    with pytest.raises(Exception):
        ssn.getChildren()[1].produce(prod)