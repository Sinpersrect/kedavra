from typing import Tuple
from Tokenize import Token
from Tokenize.Tokenizers.__Lark import LarkTokenizer, MarkTokenizer

generalTokenizerLarkStr = """%import common.WS
%ignore WS
start: program
program: token*
token: DOUBLE_QUOTE_STRING | SINGLE_QUOTE_STRING | NUM | IDENT | MARK
DOUBLE_QUOTE_STRING: /"[^"]*"/
SINGLE_QUOTE_STRING: /'[^']*'/
NUM: /[0-9]+(\.[0-9]+)?/
IDENT: /[_a-zA-Z][_a-zA-Z0-9]*/
MARK: /\./ | /[^_\s\d\.'"]/
%ignore /#.*/"""


class GeneralTokenizer(MarkTokenizer):
    def __init__(self):
        super().__init__(generalTokenizerLarkStr, ' ')

    def instantiateToken(self, token: Token) -> str:
        if token.value() is None:
            if token.type() == 'IDENT':
                return 'a'
            if token.type() == 'NUM':
                return '0'
            return token.type()
        return token.value()
