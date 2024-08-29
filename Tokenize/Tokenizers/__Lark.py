from typing import Tuple
from lark import Lark
from Tokenize import Token, Tokenizer


class LarkTokenizer(Tokenizer):
    def __init__(self, larkStr: str, tokenSep: str = ''):
        self.__lexer = Lark(larkStr)
        self.__tokenSep = tokenSep

    def tokenize(self, sentence: str) -> Tuple[Token, ...]:
        tokens = self.__lexer.lex(sentence)
        return tuple(Token(token.type, token.value) for token in tokens)

    def instantiate(self, tokens):
        """
        将tokens实例化为对应的字符串
        """
        return self.__tokenSep.join(map(lambda token: self.instantiateToken(token), tokens))


class MarkTokenizer(LarkTokenizer):
    # 针对Mark将其Type设置为Value
    def tokenize(self, sentence: str) -> Tuple[Token, ...]:
        tokens = super().tokenize(sentence)
        return tuple([Token(token.value(), token.value()) if token.type() == 'MARK' else token for token in tokens])