from abc import abstractmethod
from typing import Sequence

from Tokenize import Token


class TokenInstantiator:
    @abstractmethod
    def instantiate(self, tokens: Sequence[Token]):
        pass


class DefaultTokenInstantiator(TokenInstantiator):
    def instantiate(self, tokens: Sequence[Token]):
        return ''.join([i.value() if i.value() is not None else i.type() for i in tokens])


class SSTokenInstantiator(TokenInstantiator):
    def instantiate(self, tokens: Sequence[Token]):
        return ' '.join([i.value() if i.value() is not None else i.type() for i in tokens])
