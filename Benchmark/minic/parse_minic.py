import lark
parser = lark.Lark("""
start:n2
n2: decl*
decl: var_decl | func_decl
var_decl: type idents ";"
type: "int" | "float" | "bool" | "char"
idents: IDENT "," idents | IDENT
func_decl: rtype IDENT "(" args? ")" "{" n0* "}"
rtype: type | "void"
args:  type IDENT "," args | type IDENT
n0: "do" n0 "while" "(" n4 ")" ";"
  | "{" n1
  | n4 ";"
  | "if" "(" n4 ")" n0 "else" n0
  | "if" "(" n4 ")" n0
  | "{" "}"
  | ";"
  | "while" "(" n4 ")" n0
  | var_decl
params: n4 "," params | n4
n1: "}"
  | n0 n1
n3: "(" n4 ")"
  | NUM
  | n3 "+" n3
  | n3 "-" n3
  | IDENT
  | IDENT "(" params? ")"
n4: n3
  | IDENT "=" n4
  | n3 "<" n3
IDENT: /[a-zA-Z]/
NUM: /[0-9]+/
%ignore /\s+/
""")
import sys
parser.parse(open(sys.argv[1]).read())