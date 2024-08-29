from typing import Tuple

from Tokenize import Token
from Tokenize.Tokenizers.__Lark import LarkTokenizer, MarkTokenizer

jsonTokenizerLarkStr = r"""
%import common.WS
%ignore WS
start: program
program: token*
token: DOUBLE_QUOTE_STRING | SINGLE_QUOTE_STRING | NUM | IDENT | MARK
DOUBLE_QUOTE_STRING: /"[^"]*"/
SINGLE_QUOTE_STRING: /'[^']*'/
NUM: /-?[0-9]+(\.[0-9]+)?/
IDENT: /[_a-zA-Z][_a-zA-Z0-9]*/
MARK: /\./ | /[^_\s\d\.'"]/
%ignore /#.*/
"""


class JsonTokenizer(MarkTokenizer):
    def __init__(self):
        super().__init__(jsonTokenizerLarkStr, '')


whileTokenizerLarkStr = r"""
start: program
program: token*
token: MARK
MARK: " " | "then" | "do" | "else" | "skip" | "if" | "true" | "false" | "L" | "n" | "while" | /\./ | /[^_\s\d\.'"]/
"""


class WhileTokenizer(MarkTokenizer):
    def __init__(self):
        super().__init__(whileTokenizerLarkStr, '')


lispTokenizerLarkStr = r"""
start: program
program: token*
token: IDENT | MARK
IDENT: /[_a-zA-Z][_a-zA-Z0-9]*/
MARK: " " |  /\./ | /[^_\s\d\.'"]/
"""


class LispTokenizer(MarkTokenizer):
    def __init__(self):
        super().__init__(lispTokenizerLarkStr, '')


xmlTokenizerLarkStr = r"""
start: program
program: token*
token: a | b | c | d | e | IDENT | DOUBLE_QUOTE_STRING | MARK
a: "a"
b: "b"
c: "c"
d: "d"
e: "e"
IDENT: /[_a-zA-Z][_a-zA-Z0-9]*/
MARK: " " |  /\./ | /[^_\s\d\.'"]/
DOUBLE_QUOTE_STRING: /"[^"]*"/
"""


class XmlTokenizer(MarkTokenizer):
    def __init__(self):
        super().__init__(xmlTokenizerLarkStr, '')


turtleTokenizerLarkStr = r"""
start: program
program: token*
token: c | fill | rep | NUM | MARK | IDENT | DIR
c: "c"
fill: "fill"
DIR: /[lrbf][0-9]/
IDENT: /[A-Z][a-z]+/
rep: "repeat"
NUM: /\d+/ | /-?\d+\.\d+/
MARK: /\./ | /[^_\s\d\.'"]/ | " "
"""


class TurtleTokenizer(MarkTokenizer):
    def __init__(self):
        super().__init__(turtleTokenizerLarkStr, '')


nodejsTokenizerLarkStr = r"""
%import common.WS
%ignore WS
start: program
program: token*
token: CMP | OP | OPA | cont | ret | throw | STAR | NUM | IDENT | SINGLE_QUOTE_STRING | DOUBLE_QUOTE_STRING | MARK
ret: "ret"
throw: "throw"
CMP: "==" | "<<"
OP: "+" | "-" | "%"
cont: "continue" | "break"
STAR: "=>"
OPA: "+=" | "%=" | "/=" | "|=" 
NUM: /\d+/ | /-?\d+\.\d+/
IDENT: /[_a-zA-Z][_a-zA-Z0-9]*/
DOUBLE_QUOTE_STRING: /"[^"]*"/
SINGLE_QUOTE_STRING: /'[^']*'/
MARK: /./
%ignore /#.*/
"""


class NodejsTokenizer(MarkTokenizer):
    def __init__(self):
        super().__init__(nodejsTokenizerLarkStr, ' ')