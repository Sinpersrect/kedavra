from typing import Tuple

from DataTypes import Grammar, Clause, Symbol
from Instantiate.SymbolIns import RandomizedSymbolInstantiator
from Tool import str1


class SetChecker:
    def __init__(self, grammar: Grammar):
        self._grammar = grammar
        self._si = RandomizedSymbolInstantiator(grammar)
        self._subsetCache = {}

    def isReachable(self, symbols1: Tuple[Symbol], symbols2: Tuple[Symbol]) -> bool:
        """
        此处的Reachable指的是symbols1作为一个非终结符，可以到达symbols2
        :param symbols1:
        :param symbols2:
        :return:
        """
        # 通过clause1能否到达clause2
        if len(symbols1) > 1:
            return False
        symbol = symbols1[0]
        if symbol.isTerminal():
            return False
        return symbols2 in {i.getSymbols() for i in self._grammar.getAllReachableProds(symbol.getValue())}

    def isDirectReachable(self, clause1: Clause, clause2: Clause) -> bool:
        # 通过clause1能否到达clause2
        if not clause1.isSingleNt():
            return False
        if not clause2.isProd():
            return False
        nt = clause1.getValueNt()
        return clause2.getProd() in self._grammar.getAllReachableProds(nt)

    def isSubset(self, symbols1: Tuple[Symbol], symbols2: Tuple[Symbol]) -> bool:
        if len(symbols1) == 0 and len(symbols2) == 0:
            return True
        # 这里我们认为一个非空的符号集和一个空的符号集不能是subset关系.
        if len(symbols1) == 0 or len(symbols2) == 0:
            return False
        if len(symbols1) > 0 and len(symbols2) > 0 and symbols1[0] == symbols2[0]:
            return self.isSubset(symbols1[1:], symbols2[1:])
        if len(symbols1) > 0 and len(symbols2) > 0 and symbols1[-1] == symbols2[-1]:
            return self.isSubset(symbols1[:-1], symbols2[:-1])
        key = (symbols1, symbols2)
        if key in self._subsetCache:
            return self._subsetCache[key]
        # 一个简单的思路就是,为clause2构造一个Grammar,然后再构造oracle,然后对clause1大量采样。
        if self.isReachable(symbols2, symbols1):
            self._subsetCache[key] = True
            return True
        if self.isReachable(symbols1, symbols2):
            self._subsetCache[key] = False
            return False
        subGrammar = self._grammar.fork(symbols2)
        oracle = subGrammar.getOracle()

        for i in range(20):
            randomGen = self._si.instantiate(symbols1)
            if not oracle.parse(randomGen):
                self._subsetCache[key] = False
                return False
        self._subsetCache[key] = True
        return True

    def isIntersection(self, clause1: Clause, clause2: Clause) -> bool:
        pass
