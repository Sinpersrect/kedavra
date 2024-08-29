from typing import Tuple, Collection
from Tokenize import Token
from Tokenize.Tokenizers.__General import GeneralTokenizer


class KeywordTokenizer(GeneralTokenizer):
    def __init__(self, keywords: Collection[str]):
        super().__init__()
        self.__keywords = set(keywords)

    def tokenize(self, sentence: str) -> Tuple[Token, ...]:
        # 此处我们直接使用手动的方式。
        tokens = super().tokenize(sentence)
        newTokenizedSentence = []
        for token in tokens:
            if token.type() != "IDENT":
                newTokenizedSentence.append(token)
                continue
            if token.value() in self.__keywords:
                newTokenizedSentence.append(Token(token.value(), token.value()))
            else:
                newTokenizedSentence.append(token)
        return tuple(newTokenizedSentence)
