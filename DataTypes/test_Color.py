from DataTypes.__Colored import ColoredGrammar, getMaximalSubClauses
from DataTypes.__Grammar import Prod, Symbol
from DataTypes.__loadGrammar import loadGrammar, loadProd


def testColor_Simple():
    # 着色后没有修改语法。
    grammar = ColoredGrammar(loadGrammar("""start:n0
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
  | "do" ";" "while" "(" "IDENT" ")" ";" """))
    prod1 = loadProd("""n0: "IDENT" "<" "IDENT" ";" """)
    color1 = grammar.attachColor(prod1.newClause())
    color2 = grammar.attachColor(prod1.newClause(0, 2))
    color3 = grammar.attachColor(prod1.newClause(1, 3))
    prod1 = grammar.refreshProd(prod1)
    assert grammar.getColoredClauses(color1) == {prod1.newClause()}
    assert grammar.getColoredClauses(color2) == {prod1.newClause(0, 2)}
    assert grammar.getColoredClauses(color3) == {prod1.newClause(1, 3)}
    # 修改语法
    grammar.replaceClause(prod1.newClause(0, 1), (Symbol('n0'),))
    newProd = Prod('n0', prod1.newClause(0, 1).getValue())
    prod2 = loadProd("""n0: n0 "<" "IDENT" ";" """)
    grammar.addProd(newProd)
    assert grammar.getColoredClauses(color1) == {newProd.newClause(), prod2.newClause()}
    assert grammar.getColoredClauses(color2) == {newProd.newClause(), prod2.newClause(0, 2)}
    assert grammar.getColoredClauses(color3) == {prod2.newClause(1, 3)}


def testColor_Simple1():
    grammar = ColoredGrammar(loadGrammar("""start:n0
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
  | "do" ";" "while" "(" "IDENT" ")" ";" """))
    prod1 = loadProd("""n0: "IDENT" "<" "IDENT" ";" """)
    prod2 = loadProd("""n0: "do" ";" "while" "(" "IDENT" ")" ";" """)
    clause1 = prod1.newClause(0, 3)
    clause2 = prod2.newClause(4, 5)
    color1 = grammar.attachColor(prod1.newClause())
    color2 = grammar.attachColor(prod2.newClause())
    color3 = grammar.attachColor(prod1.newClause(2, 4))
    grammar.mergeClauses([clause1, clause2])
    prod3 = loadProd("""n0: "do" ";" "while" "(" n1 ")" ";" """)
    prod4 = loadProd("""n0: n1 ";" """)
    prod5 = loadProd("""n1: "IDENT" """)
    prod6 = loadProd("""n1: "IDENT" "<" "IDENT" """)
    assert grammar.getColoredClauses(color1) == {prod4.newClause(), prod6.newClause()}
    assert grammar.getColoredClauses(color2) == {prod3.newClause(), prod5.newClause()}
    assert grammar.getColoredClauses(color3) == {prod4.newClause(), prod6.newClause(2, 3)}


def test_getMaximalSubClauses():
    prod = loadProd("""n0: "do" ";" "while" "(" n1 ")" ";" """)
    for clause in prod.clauses():
        for msc in getMaximalSubClauses(clause, prod.clauses()):
            assert len(msc) == len(clause) - 1


def test_copy():
    grammar = ColoredGrammar(loadGrammar("""start:n0
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
  | "do" ";" "while" "(" "IDENT" ")" ";" """))
    prod1 = loadProd("""n0: "IDENT" "<" "IDENT" ";" """)
    prod2 = loadProd("""n0: "do" ";" "while" "(" "IDENT" ")" ";" """)
    color1 = grammar.attachColor(prod1.newClause())
    color2 = grammar.attachColor(prod2.newClause())
    copied = grammar.copy()
    color3 = copied.attachColor(prod1.newClause(2, 4))
    assert copied == grammar
    assert grammar.getColoredClauses(color1) == {prod1.newClause()}
    assert grammar.getColoredClauses(color2) == {prod2.newClause()}
    assert copied.getColoredClauses(color1) == {prod1.newClause()}
    assert copied.getColoredClauses(color2) == {prod2.newClause()}
    assert grammar.getColoredClauses(color3) == set()
    assert copied.getColoredClauses(color3) == {prod1.newClause(2, 4)}


def test_clearColor():
    grammar = ColoredGrammar(loadGrammar("""start:n0
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
      | "do" ";" "while" "(" "IDENT" ")" ";" """))
    prod1 = loadProd("""n0: "IDENT" "<" "IDENT" ";" """)
    prod2 = loadProd("""n0: "do" ";" "while" "(" "IDENT" ")" ";" """)
    color1 = grammar.attachColor(prod1.newClause())
    color2 = grammar.attachColor(prod2.newClause())
    assert grammar.getColoredClauses(color1) == {prod1.newClause()}
    assert grammar.getColoredClauses(color2) == {prod2.newClause()}
    grammar.clearColor(prod1.newClause(), color1)
    assert grammar.getColoredClauses(color1) == set()
    grammar.clearColor(prod2.newClause(0, 1), color2)
    assert grammar.getColoredClauses(color2) == {prod2.newClause(1, len(prod2))}
