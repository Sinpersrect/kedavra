from abc import abstractmethod
from typing import Collection, Iterable, Sequence, Tuple


class Token:
    def __init__(self, ttype, value=None) -> None:
        self.__type = ttype
        self.__value = value

    def type(self):
        return self.__type

    def value(self):
        return self.__value

    def __str__(self):
        return self.type()

    def __lt__(self, other):
        return isinstance(other, Token) and self.__type < other.__type

    def __repr__(self):
        return 'Token(%s,%s)' % (repr(self.type()), repr(self.value()))

    def __hash__(self) -> int:
        return hash(self.__type)

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, Token):
            return False
        return self.__type == other.__type

class TokenizedContext:
    def __init__(self, prefix: Sequence[Token], suffix: Sequence[Token]) -> None:
        self.__prefix = tuple(prefix)
        self.__suffix = tuple(suffix)

    def assembly(self, value: Sequence[Token]) -> Tuple[Token, ...]:
        return self.__prefix + tuple(value) + self.__suffix


class Tokenizer:
    @abstractmethod
    def tokenize(self, sentence: str) -> Tuple[Token,...]:
        pass

    def tokenizeAll(self, sentences: Collection[str]) -> Tuple[Tuple[Token, ...], ...]:
        ret = []
        for sentence in sentences:
            ret.append(self.tokenize(sentence))
        return tuple(ret)

    @abstractmethod
    def instantiate(self, tokens: Iterable[Token]) -> str:
        pass

    def instantiateToken(self, token: Token) -> str:
        if token.value() is None:
            return token.type()
        return token.value()
