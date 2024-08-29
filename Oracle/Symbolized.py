from typing import Tuple

from DataTypes import Symbol
from Instantiate.SymbolIns import SymbolInstantiator
from Oracle.Tokenized import TokenizedOracle


class SymbolizedOracle:
    def __init__(self, tokenizedOracle: TokenizedOracle, si: SymbolInstantiator):
        self.__oracle = tokenizedOracle
        self.__si = si

    def parse(self, symbols: Tuple[Symbol,...]) -> bool:
        return self.__oracle.parse(self.__si.instantiate(symbols))
