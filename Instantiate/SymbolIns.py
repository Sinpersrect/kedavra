from abc import abstractmethod
from Instantiate.SyntaxNodeGrow import LevelSNG, RandomizedSNG, StaticSNG, ArvadaSNG, SyntaxNodeGrower
from Instantiate.Tree import SyntaxNode
from Tokenize import Token, TokenizedContext
from typing import List, Sequence, Tuple
from DataTypes import Symbol, Grammar, Context
import random
from itertools import product, chain


class SymbolInstantiator:
    def __init__(self, grammar: Grammar) -> None:
        self._grammar = grammar
        self._tmpUsage = None

    @abstractmethod
    def instantiateSymbol(self, symbol: Symbol) -> Tuple[Token]:
        pass

    def instantiate(self, symbols: Sequence[Symbol]) -> Tuple[Token]:
        ret = ()
        for symbol in symbols:
            ret = ret + self.instantiateSymbol(symbol)
        return ret

    def instantiateContext(self, context: Context) -> TokenizedContext:
        tokenizedPrefix = self.instantiate(context.getPrefix())
        tokenizedSuffix = self.instantiate(context.getSuffix())
        return TokenizedContext(tokenizedPrefix, tokenizedSuffix)

    def getGrammar(self) -> Grammar:
        return self._grammar


class StaticSymbolInstantiator(SymbolInstantiator):
    def __init__(self, grammar: Grammar) -> None:
        super().__init__(grammar)
        self.__ssng = StaticSNG(grammar)

    def instantiateSymbol(self, symbol: Symbol) -> Tuple[Token]:
        return self.__ssng.grow(SyntaxNode(symbol)).toTokens()


class SngSymbolInstantiator(SymbolInstantiator):
    def __init__(self, sng: SyntaxNodeGrower) -> None:
        super().__init__(sng.getGrammar())
        self.__sng = sng

    def instantiateSymbol(self, symbol: Symbol) -> Tuple[Token]:
        while True:
            try:
                return self.__sng.grow(SyntaxNode(symbol)).toTokens()
            except RecursionError:
                continue


class RandomizedSymbolInstantiator(SngSymbolInstantiator):
    def __init__(self, grammar: Grammar) -> None:
        super().__init__(RandomizedSNG(grammar))


class ArvadaSymbolInstantiator(SngSymbolInstantiator):
    def __init__(self, grammar: Grammar) -> None:
        super().__init__(ArvadaSNG(grammar, 4))
        # 之前的论文是用的5,因为它们是从start出发，而我们从start产生的那个非终结符出发，所以此处需要减少1


class LevelSymbolInstantiator:
    def __init__(self, si: SymbolInstantiator, maxLevel: int = 1) -> None:
        self.__lsng = LevelSNG(si.getGrammar(), maxLevel)

    def instantiate(self, symbol: Symbol) -> List[Tuple[Token]]:
        ret = []
        for node in self.__lsng.grow(SyntaxNode(symbol)):
            ret.append(node.toTokens())
        return ret


