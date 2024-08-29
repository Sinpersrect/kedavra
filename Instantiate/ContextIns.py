from abc import abstractmethod
from typing import Union

from DataTypes import Clause, Context, Grammar


class ContextInstantiator:
    def __init__(self, grammar: Grammar) -> None:
        self._grammar = grammar

    @abstractmethod
    def instantiate(self, clauseOrNt: Union[str, Clause]) -> Context:
        pass


class RandomizedContextInstantiator(ContextInstantiator):
    def __initContextTable(self):
        updated = True
        while updated:
            updated = False
            for nt in tuple(self.__ctbl.keys()):
                for prod in self._grammar.getRule(nt).getProds():
                    for i, symbol in enumerate(prod.getSymbols()):
                        if symbol.isTerminal():
                            continue
                        if symbol.getValue() in self.__ctbl:
                            continue
                        self.__ctbl[symbol.getValue()] = self.instantiate(prod.newClause(i, i + 1))
                        updated = True

    def __init__(self, grammar: Grammar) -> None:
        super().__init__(grammar)
        self.__ctbl = {grammar.getStart(): Context((), ())}
        self.__initContextTable()

    def instantiate(self, clauseOrNt: Union[str, Clause]) -> Context:
        if isinstance(clauseOrNt, str):
            if clauseOrNt not in self.__ctbl:
                raise Exception('%s\n\n not found %s' % (str(self._grammar), clauseOrNt))
            return self.__ctbl[clauseOrNt]
        if clauseOrNt.getNt() not in self.__ctbl:
            raise Exception('%s not found\n\n the grammar is %s' % (str(clauseOrNt.getNt()), str(self._grammar)))
        context = self.__ctbl[clauseOrNt.getNt()]
        prefix, suffix = context.getPrefix(), context.getSuffix()
        prefix1, suffix1 = clauseOrNt.getPrefix(), clauseOrNt.getSuffix()
        return Context(prefix + prefix1, suffix1 + suffix)
