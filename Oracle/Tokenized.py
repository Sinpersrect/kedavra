from typing import Tuple, Dict, Union, Optional

from Instantiate.Ins import TokenInstantiator
from Statistics import counter
from Tokenize import Tokenizer, Token
from Oracle import Raw


class TokenizedOracle:
    def __init__(self, rawOracle: Raw, tokenInstantiatorOrTokenizer: Union[Tokenizer, TokenInstantiator]):
        if isinstance(tokenInstantiatorOrTokenizer, TokenInstantiator):
            self.__ti: Optional[TokenInstantiator] = tokenInstantiatorOrTokenizer
            self.__tokenizer = None
        else:
            self.__tokenizer = tokenInstantiatorOrTokenizer
            self.__ti = None

        self.__oracle = rawOracle
        self.__cache = {}
        self.__statistics = {'calls': 0, 'real_calls': 0, 'call_time': 0}

    def __ins(self, tokens: Tuple[Token, ...]) -> str:
        if self.__ti is not None:
            return self.__ti.instantiate(tokens)
        return self.__tokenizer.instantiate(tokens)

    @counter('TokenizedOracle')
    def parse(self, tokens: Tuple[Token, ...]) -> bool:
        import time
        start = time.time()
        self.__statistics['calls'] += 1
        if tokens not in self.__cache:
            self.__statistics['real_calls'] += 1
            self.__cache[tokens] = self.__oracle.parse(self.__ins(tokens))
        self.__statistics['call_time'] += time.time() - start
        return self.__cache[tokens]

    def getTokenizer(self) -> Tokenizer:
        return self.__tokenizer

    def getStatistics(self) -> Dict:
        return self.__statistics
