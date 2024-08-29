from typing import Iterable, Tuple
from Tokenize import Tokenizer, Token

"""
默认Tokenizer,把每一个字符当做一个Token.
Token的Key和Value相同
"""


class DefaultTokenizer(Tokenizer):

    def tokenize(self, sentence) -> Tuple[Token, ...]:
        return tuple(Token(i, i) for i in sentence)

    def instantiate(self, tokens: Iterable[Token]) -> str:
        return ''.join(map(lambda x: self.instantiateToken(x), tokens))
