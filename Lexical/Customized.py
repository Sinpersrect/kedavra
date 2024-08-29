from typing import Collection, Tuple, Iterable

from Instantiate.Ins import DefaultTokenInstantiator
from Tokenize import Tokenizer, Token


class CustomizedTokenizer(Tokenizer):
    def tokenize(self, sentence: str) -> Tuple[Token, ...]:
        pass

    def __init__(self, data, spaceSensitive: bool):
        self.__data = data
        self.__ss = spaceSensitive
        self.__ti = DefaultTokenInstantiator()

    def tokenizeAll(self, sentences: Collection[str]) -> Tuple[Tuple[Token, ...], ...]:
        return self.__data

    def instantiate(self, tokens: Iterable[Token]) -> str:
        sep = ' '
        if self.__ss:
            sep = ''
        return sep.join([i.value() for i in tokens])
