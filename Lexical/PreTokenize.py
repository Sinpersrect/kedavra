from typing import Tuple, Iterable, Collection, List, Dict, Set

from lark import Lark

from Tokenize import Token

larkStr = r"""
start: program
program: token*
token: DOUBLE_QUOTE_STRING | SINGLE_QUOTE_STRING | NUM | IDENT | MARK
DOUBLE_QUOTE_STRING: /"[^"]*"/
SINGLE_QUOTE_STRING: /'[^']*'/
NUM: /[0-9]+/
IDENT: /[_a-zA-Z][_a-zA-Z0-9]*/
MARK: /./
"""


class PreTokenizer:
    lexer = Lark(larkStr)

    @staticmethod
    def tokenize(sentence: str) -> Tuple[Token, ...]:
        return tuple((Token(token.value, token.value) for token in PreTokenizer.lexer.lex(sentence)))

    @staticmethod
    def tokenizeAll(sentences: Collection[str]) -> List[Tuple[Token, ...]]:
        ret = []
        for sentence in sentences:
            ret.append(PreTokenizer.tokenize(sentence))
        return ret

    @staticmethod
    def getBasicType(tokenValue: str) -> str:
        tokens = list(PreTokenizer.lexer.lex(tokenValue))
        if len(tokens) > 1:
            return 'MARK'
        return tokens[0].type
