from DataTypes import Context, Grammar,Prod,Symbol
from Instantiate.ContextIns import RandomizedContextInstantiator
from Tokenize import Token


def test_RCI():
    grammar = Grammar('n0',[])
    prod = Prod('n0',[Symbol(Token('a')),Symbol('n1'),Symbol(Token('c'))])
    grammar.addProd(prod)
    prod = Prod('n1',[Symbol(Token('a')),Symbol(Token('b')),Symbol(Token('a'))])
    grammar.addProd(prod)
    rci = RandomizedContextInstantiator(grammar)
    assert rci.instantiate('n1') == Context((Symbol(Token('a')),),(Symbol(Token('c')),))
    assert rci.instantiate(prod.newClause(1,2)) == Context((Symbol(Token('a')),Symbol(Token('a'))),
                                                           (Symbol(Token('a')),Symbol(Token('c')),))