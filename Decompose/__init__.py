from abc import abstractmethod
from Tokenize import Token
from typing import Collection, Tuple
from Oracle.Tokenized import TokenizedOracle
from Tool import str1


class DataDecomposer:
    def __init__(self, oracle: TokenizedOracle):
        self._oracle = oracle

    @abstractmethod
    def decompose(self, tokens: Tuple[Token]) -> Collection[Tuple[Token]]:
        pass

    def getOracle(self) -> TokenizedOracle:
        return self._oracle


class NaiveDataDecomposer(DataDecomposer):
    def __reduceTokens(self, tokens: Tuple[Token], l: int, r: int) -> Tuple[int, int]:
        l0, r0 = l, r
        while l < r0:
            reduced = tokens[:l] + tokens[r:]
            if self._oracle.parse(reduced):
                return l, r
            r = r - 1
            if l >= r:
                l = l + 1
                r = r0
        return -1, -1

    def __reduceReserved(self, tokens: Tuple[Token], reservedIndex: int) -> Tuple[Token]:
        updated = True
        while updated:
            updated = False
            l, r = self.__reduceTokens(tokens, 0, reservedIndex)
            if l != -1:
                tokens = tokens[:l] + tokens[r:]
                reservedIndex -= r - l
                updated = True
            l, r = self.__reduceTokens(tokens, reservedIndex + 1, len(tokens))
            if l != -1:
                tokens = tokens[:l] + tokens[r:]
                updated = True
        return tokens

    def decompose(self, tokens: Tuple[Token,...]) -> Collection[Tuple[Token,...]]:
        result = set()
        maskTokenType = set()
        for index in range(len(tokens)):
            if tokens[index].type() in maskTokenType:
                continue
            reduced = self.__reduceReserved(tokens, index)
            if len(reduced) == len(tokens):
                result.add(reduced)
                continue
            for token in reduced:
                maskTokenType.add(token.type())
            # print(reduced)
            result = result.union(self.decompose(reduced))
        return result


class BetterDataDecomposer(NaiveDataDecomposer):
    def __reduceReserved1(self, tokens: Tuple[Token], reservedIndex: int) -> Tuple[Token,...]:
        for l in range(reservedIndex, -1, -1):
            for r in range(reservedIndex + 1, len(tokens) + 1):
                for l1 in range(0, l):
                    for r1 in range(len(tokens) + 1, r, -1):
                        newTokens = tokens[:l1] + tokens[l:r] + tokens[r1:]
                        if self.getOracle().parse(newTokens):
                            return newTokens
        return tokens

    def decompose(self, tokens: Tuple[Token]) -> Collection[Tuple[Token,...]]:
        naiveResult = super().decompose(tokens)
        result = set()
        for tokens in naiveResult:
            for index in range(len(tokens)):
                result.add(self.__reduceReserved1(tokens, index))
        return result


class ChunkedDataDecomposer(BetterDataDecomposer):
    def decompose(self, tokens: Tuple[Token]) -> Collection[Tuple[Token]]:
        ret = []
        for i in range(len(tokens)):
            for j in range(i + 1, len(tokens) + 1):
                if self._oracle.parse(tokens[i:j]):
                    print(str1(tokens[i:j]))
                    ret.append(tokens[i:j])
        return ret



