from Consts import SEP
from DataTypes import loadGrammar, loadProd, loadClause

grammar = loadGrammar("""
start:n0
n0: "do" n0 "while" "(" n4 ")" ";"
  | "{" n1
  | n4 ";"
  | "if" "(" n4 ")" n0 "else" n0
  | "if" "(" n4 ")" n0
  | "{" "}"
  | ";"
  | "while" "(" n4 ")" n0
n1: "}"
  | n0 n1
n3: "(" n4 ")"
  | "NUM"
  | n3 "+" n3
  | n3 "-" n3
  | "IDENT"
n4: n3
  | "IDENT" "=" n4
  | n3 "<" n3
""")
print('grammar:')
print(grammar)
print(SEP)
print(loadProd(' n0: "do" n0 "while" "(" n4 ")" ";" '))
print(SEP)
print(loadClause(' n3: s "(" n4 s ")" '))
