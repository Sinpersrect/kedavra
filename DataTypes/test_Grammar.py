from Tokenize import Token
from DataTypes.__Grammar import Grammar, Prod, Rule, Symbol, SymbolType
from DataTypes.__loadGrammar import loadGrammar, loadProd, loadRules, loadClause
from DataTypes.__Colored import ColoredGrammar


def testProdStr():
    prod = Prod('n0', [Symbol(Token('a')), Symbol(Token('b')), Symbol(Token('c'))])
    assert str(prod) == 'n0: "a" "b" "c"'
    prod = Prod('n0', [Symbol('a'), Symbol(Token('b')), Symbol(Token('c'))])
    assert str(prod) == 'n0: a "b" "c"'
    prod = Prod('n0', [Symbol('a', SymbolType.Rep1), Symbol(Token('b'), SymbolType.Opt), Symbol(Token('c'))])
    assert str(prod) == 'n0: a+ "b"? "c"'
    prod = Prod('n0', [Symbol('a'), Symbol('b'), Symbol('c', SymbolType.Rep0)])
    assert str(prod) == 'n0: a b c*'


def testSymbol():
    symbol1 = Symbol('a')
    symbol2 = Symbol('b')
    symbol3 = Symbol('a')
    symbol4 = Symbol('a', SymbolType.Rep0)
    assert symbol1 != symbol2
    assert symbol1 == symbol3
    assert symbol1 != symbol4
    assert hash(symbol1) == hash(symbol3)


def testProd():
    symbol1 = Symbol('a')
    symbol2 = Symbol('b')
    prod1 = Prod('n0', [symbol1, symbol2])
    prod2 = Prod('n0', [symbol1, symbol2])
    prod3 = Prod('n1', [symbol1, symbol2])
    prod4 = Prod('n0', [symbol1, symbol1])
    assert prod1 == prod2
    assert prod1 != prod3
    assert prod1 != prod4


def testGrammar():
    # findNt
    grammar = Grammar('n0', [])
    assert grammar.findNt('n0')
    # findProd
    prod = Prod('n0', [Symbol(Token('a')), Symbol(Token('a'))])
    assert not grammar.findProd(prod)
    grammar.addProd(prod)
    assert grammar.findProd(prod)
    # getNts
    assert grammar.getNts() == frozenset({'n0'})
    # getRule
    assert grammar.getRule('n0') == Rule('n0', [prod])
    # getStart
    assert grammar.getStart() == 'n0'
    # oracle
    assert grammar.getOracle().parse((Token('a'), Token('a')))
    assert not grammar.getOracle().parse((Token('a'), Token('a'), Token('a')))
    # removeProd
    grammar.removeProd(prod)
    assert not grammar.findProd(prod)


def testGrammarLoad():
    g1 = loadGrammar("""start:n0
n0: "if" "(" "IDENT" ")" "{" "}" "else" ";"
  | "{" "IDENT" ";" "}"
  | "IDENT" "=" "IDENT" ";"
  | "IDENT" "<" "IDENT" ";"
  | ";"
  | "IDENT" ";"
  | "NUM" ";"
  | "NUM" "-" "IDENT" ";"
  | "IDENT" "+" "NUM" ";"
  | "while" "(" "IDENT" ")" ";"
  | "(" "IDENT" ")" ";"
  | "if" "(" "IDENT" ")" ";"
  | "{" "}"
  | "do" ";" "while" "(" "IDENT" ")" ";" """)
    g2 = loadGrammar(str(g1))
    assert g1 == g2


def testMergeClause_Simple():
    g1 = loadGrammar("""start:n0
n0: "if" "(" "IDENT" ")" "{" "}" "else" ";"
  | "{" "IDENT" ";" "}"
  | "IDENT" "=" "IDENT" ";"
  | "IDENT" "<" "IDENT" ";"
  | ";"
  | "IDENT" ";"
  | "NUM" ";"
  | "NUM" "-" "IDENT" ";"
  | "IDENT" "+" "NUM" ";"
  | "while" "(" "IDENT" ")" ";"
  | "(" "IDENT" ")" ";"
  | "if" "(" "IDENT" ")" ";"
  | "{" "}"
  | "do" ";" "while" "(" "IDENT" ")" ";" """)
    prod1 = loadProd("""n0: "if" "(" "IDENT" ")" "{" "}" "else" ";" """)
    prod2 = loadProd("""n0: "NUM" ";" """)
    clause1 = prod1.newClause(2, 3)
    clause2 = prod2.newClause(0, 1)
    coloredGrammar = ColoredGrammar(g1)
    g2 = loadGrammar("""start:n0
n0: "if" "(" n1 ")" "{" "}" "else" ";"
  | "{" "IDENT" ";" "}"
  | "IDENT" "=" "IDENT" ";"
  | "IDENT" "<" "IDENT" ";"
  | ";"
  | "IDENT" ";"
  | n1 ";"
  | "NUM" "-" "IDENT" ";"
  | "IDENT" "+" "NUM" ";"
  | "while" "(" "IDENT" ")" ";"
  | "(" "IDENT" ")" ";"
  | "if" "(" "IDENT" ")" ";"
  | "{" "}"
  | "do" ";" "while" "(" "IDENT" ")" ";"
n1: "IDENT" | "NUM"
     """)
    coloredGrammar.mergeClauses([clause1, clause2])
    assert coloredGrammar == g2


def testReplaceClause():
    grammar = loadGrammar("""start:n0
n0: "if" "(" "IDENT" ")" "{" "}" "else" ";"
  | "{" "IDENT" ";" "}"
  | "IDENT" "=" "IDENT" ";"
  | "IDENT" "<" "IDENT" ";"
  | ";"
  | "IDENT" ";"
  | "NUM" ";"
  | "NUM" "-" "IDENT" ";"
  | "IDENT" "+" "NUM" ";"
  | "while" "(" "IDENT" ")" ";"
  | "(" "IDENT" ")" ";"
  | "if" "(" "IDENT" ")" ";"
  | "{" "}"
  | "do" ";" "while" "(" "IDENT" ")" ";" """)
    prod1 = loadProd("""n0: "IDENT" "<" "IDENT" ";" """)
    clause1 = prod1.newClause(0, 1)
    grammar.replaceClause(clause1, (Symbol('n0'),))
    assert grammar.findProd(loadProd("""n0: n0 "<" "IDENT" ";" """))


def test_Iter():
    prod1 = loadProd("""n0: "if" "(" "IDENT" ")" "{" "}" "else" ";" """)
    symbols = tuple(prod1)
    assert symbols == prod1.getSymbols()

    clause1 = prod1.newClause(2, 5)
    assert tuple(clause1) == clause1.getValue()

    rule = loadRules("""start:n0
n0: "if" "(" "IDENT" ")" "{" "}" "else" ";"
  | "{" "IDENT" ";" "}"
  | "IDENT" "=" "IDENT" ";"
  | "IDENT" "<" "IDENT" ";"
  | ";"
  | "IDENT" ";"
  | "NUM" ";"
  | "NUM" "-" "IDENT" ";"
  | "IDENT" "+" "NUM" ";"
  | "while" "(" "IDENT" ")" ";"
  | "(" "IDENT" ")" ";"
  | "if" "(" "IDENT" ")" ";"
  | "{" "}"
  | "do" ";" "while" "(" "IDENT" ")" ";" """)[0]
    assert set(rule) == set(rule.getProds())

    grammar = loadGrammar("""start:n0
n0: "if" "(" "IDENT" ")" "{" "}" "else" ";"
  | "{" "IDENT" ";" "}"
  | "IDENT" "=" "IDENT" ";"
  | "IDENT" "<" "IDENT" ";"
  | ";"
  | n1 ";"
n1: "NUM" ";"
  | "NUM" "-" "IDENT" ";"
  | "IDENT" "+" "NUM" ";"
  | "while" "(" "IDENT" ")" ";"
  | "(" "IDENT" ")" ";"
  | "if" "(" "IDENT" ")" ";"
  | "{" "}"
  | "do" ";" "while" "(" "IDENT" ")" ";" """)
    assert set(grammar) == set(grammar.getRules())


def test_Clause():
    grammar = loadGrammar("""start:n0
n0:  "{" "IDENT" ";" "}" """)
    assert len(list(grammar.clauses())) == 10


def test_refers():
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
    prod1 = loadProd(""" n0:"IDENT" "<" n1 ";" """)
    prod2 = loadProd(""" n0:n1 ";" """)
    prod3 = loadProd(""" n1:"if" "(" n1 ")" ";" """)
    clause1 = prod1.newClause(2, 3)
    clause2 = prod2.newClause(0, 1)
    clause3 = prod3.newClause(2, 3)
    assert set(grammar.getRefers('n1')) == {clause1, clause2, clause3}


def test_copy():
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
    copied = grammar.copy()
    assert copied == grammar
    grammar.removeRule('n1')
    assert copied != grammar


def testLoadClause():
    s = 'n0: s "a" s'
    assert loadClause(s) == loadProd('n0:"a"').newClause()
    s = 'n0: s "a" s n0'
    assert loadClause(s) == loadProd('n0:"a" n0').newClause(0, 1)
    s = 'n0: s s "a" n0'
    assert loadClause(s) == loadProd('n0:"a" n0').newClause(0, 0)


def testReachableProds():
    grammar = loadGrammar("""
    start:n0
n0: "IDENT" "-" "NUM" ";"
  | n2 ";"
  | ";"
n1: n1 "+" n1
  | "IDENT"
  | "NUM"
n2: n1
  | "IDENT" "=" n2
""")
    assert grammar.getReachableProds('n2') == {
        loadProd('n2: "IDENT" "=" n2'),
        loadProd('n1: n1 "+" n1'),
        loadProd('n1: "IDENT" '),
        loadProd('n1: "NUM" '),
    }
