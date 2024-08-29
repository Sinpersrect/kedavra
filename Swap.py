from abc import abstractmethod
from typing import Tuple

from DataTypes import Grammar, Clause
from Instantiate.ContextIns import ContextInstantiator
from Instantiate.SymbolIns import SymbolInstantiator
from Oracle.Tokenized import TokenizedOracle
from Tokenize import Token


class SwapRecord:
    def __init__(self, clause1, clause2, positive, negative, swappable):
        self.clause1 = clause1
        self.clause2 = clause2
        self.positive = positive
        self.negative = negative
        self.swappable = swappable


class SwapChecker:
    def __init__(self, grammar: Grammar, oracle: TokenizedOracle, si: SymbolInstantiator, ci: ContextInstantiator):
        self._grammar = grammar
        self._oracle = oracle
        self._si = si
        self._ci = ci

    @abstractmethod
    def check(self, clause1: Clause, clause2: Clause) -> SwapRecord:
        pass


class NaiveSwapChecker(SwapChecker):
    def __getValues(self, clause: Clause):
        if not clause.isSingleNt():
            return [self._si.instantiate(clause.getValue())]
        values = []
        for prod in self._grammar.getReachableProds(clause.getValueNt()):
            values.append(self._si.instantiate(prod.getSymbols()))
        return values

    def check(self, clause1: Clause, clause2: Clause):
        # 构造上下文
        context1 = self._si.instantiateContext(self._ci.instantiate(clause1))
        context2 = self._si.instantiateContext(self._ci.instantiate(clause2))
        # 构造值

        values1 = self.__getValues(clause1)
        values2 = self.__getValues(clause2)
        # 构造句子
        # 构造swap record
        positive, negative = [], []
        for value1 in values1:
            sentence2 = context2.assembly(value1)
            parse2 = self._oracle.parse(sentence2)
            if parse2:
                positive.append(sentence2)
            else:
                negative.append(sentence2)
                return SwapRecord(clause1, clause2, tuple(positive), tuple(negative), len(negative) == 0)

        for value2 in values2:
            sentence1 = context1.assembly(value2)
            parse1 = self._oracle.parse(sentence1)
            if parse1:
                positive.append(sentence1)
            else:
                negative.append(sentence1)
                return SwapRecord(clause1, clause2, tuple(positive), tuple(negative), len(negative) == 0)

        return SwapRecord(clause1, clause2, tuple(positive), tuple(negative), len(negative) == 0)
