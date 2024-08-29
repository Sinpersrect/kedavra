from typing import Collection, Dict, Iterable, Set, Tuple, TypeVar, Union
from DataTypes.__Grammar import Clause, Grammar, Prod, Rule, Symbol, SymbolType
from Tokenize import Token
import itertools

T = TypeVar('T', bound=Union[str, Token])


class ColoredSymbol(Symbol[T]):
    def __init__(self, value: T, colors: Collection[int], symbolType: SymbolType = SymbolType.Default) -> None:
        super().__init__(value, symbolType)
        self.__colors = tuple(colors)

    def getColors(self) -> Tuple[int,...]:
        return self.__colors


def createColoredSymbol(symbol: Symbol, colors: Collection[int]) -> ColoredSymbol:
    return ColoredSymbol(symbol.getValue(), colors, symbol.getType())


def getSymbolColors(symbol: Symbol) -> Tuple[int,...]:
    if isinstance(symbol, ColoredSymbol):
        return symbol.getColors()
    return ()


def getClauseColors(clause: Clause):
    colors = set()
    for symbol in clause.getValue():
        colors = colors.union(getSymbolColors(symbol))
    return colors


def mergeSymbolColor(symbol1, symbol2):
    return createColoredSymbol(symbol1, getSymbolColors(symbol1) + getSymbolColors(symbol2))


def mergeSymbolsColor(symbols1, symbols2):
    ret = []
    for i in range(len(symbols1)):
        ret.append(mergeSymbolColor(symbols1[i], symbols2[i]))
    return tuple(ret)


def buildSymbols(clause: Clause, subClauses: Collection[Clause], symbols: Tuple[Symbol]) -> Tuple[Symbol]:
    jtbl: Dict[int, Clause] = {}
    for subClause in subClauses:
        jtbl[subClause.getLeft()] = subClause
    ret = []
    index = clause.getLeft()
    while index < clause.getRight():
        if index in jtbl:
            subClause = jtbl[index]
            index = subClause.getRight()
            colors = getClauseColors(subClause)
            symbols = [ColoredSymbol(symbol.getValue(), colors.union(getSymbolColors(symbol)), symbol.getType()) for
                       symbol in symbols]
            ret += symbols
        else:
            ret.append(clause.getProd().getSymbols()[index])
            index += 1
    return tuple(ret)


def getMaximalSubClauses(clause: Clause, clauses: Iterable[Clause]) -> Collection[Clause]:
    subClauses = set()
    for other in clauses:
        if other == clause:
            continue
        if other.isSub(clause):
            toRemove = []
            maximal = True
            for subClause in subClauses:
                if subClause.isSub(other):
                    toRemove.append(subClause)
                elif other.isSub(subClause):
                    maximal = False
            if len(toRemove) != 0 or maximal:
                subClauses = subClauses.difference(toRemove)
                subClauses.add(other)
    return subClauses


class ColoredGrammar(Grammar[T]):
    def __init__(self, grammar: Grammar[T]) -> None:
        super().__init__(grammar._start, grammar._rules.values())

    def copy(self):
        ret = ColoredGrammar(super().copy())
        return ret

    def refreshProd(self, prod: Prod[T]):
        for other in self.getProds(prod.getNt()):
            if other == prod:
                return other
        raise Exception()

    def __mergeProdColor(self, prod1: Prod[T], prod2: Prod[T]) -> Prod[T]:
        return Prod(prod1.getNt(), mergeSymbolsColor(prod1.getSymbols(), prod2.getSymbols()))

    def addProd(self, prod: Prod[T]) -> None:
        if not self.findNt(prod.getNt()):
            self.addRule(Rule(prod.getNt(), []))
        if self.findProd(prod):
            oldProd = self.refreshProd(prod)
            prod = self.__mergeProdColor(prod, oldProd)
            self.removeProd(oldProd)
        self._rules[prod.getNt()].addProd(prod)

    def attachColor(self, clause: Clause[T]) -> int:
        import time
        color = int(time.time() * 1e9)
        newSymbols = clause.getPrefix() + tuple(
            createColoredSymbol(symbol, [color]) for symbol in clause.getValue()) + \
                     clause.getSuffix()
        newProd = Prod(clause.getNt(), newSymbols)
        self.addProd(newProd)
        return color

    def getColoredClauses(self, color: int) -> Set[Clause]:
        coloredClauses = set()
        for prod in self.getProds():
            index = 0
            while index < len(prod):
                if color not in getSymbolColors(prod.getSymbols()[index]):
                    index += 1
                    continue
                right = index + 1
                while right < len(prod) and color in getSymbolColors(prod.getSymbols()[right]):
                    right += 1
                coloredClauses.add(prod.newClause(index, right))
                index = right
        return coloredClauses

    def clearColor(self,clause: Clause,color: int) -> None:
        clause = self.refreshClause(clause)
        newSymbols = []
        for symbol in clause.getValue():
            symbol:ColoredSymbol
            colors = set(symbol.getColors())
            colors.remove(color)
            newSymbols.append(ColoredSymbol(symbol.getValue(), colors,symbol.getType()))
        self.removeProd(clause.getProd())
        self.addProd(Prod(clause.getNt(),clause.getPrefix()+tuple(newSymbols)+ clause.getSuffix()))

    def refreshClause(self, clause: Clause[T]) -> Clause[T]:
        return self.refreshProd(clause.getProd()).newClause(clause.getLeft(), clause.getRight())

    def replaceClause(self, clause: Clause[T], symbols: Tuple[Symbol]):
        # 此处考虑一个混色策略：如果一个clause被其他symbols所替代，那么其他symbols将继承它的所有颜色。
        clause = self.refreshClause(clause)
        colors = getClauseColors(clause)
        symbols = tuple(
            ColoredSymbol(symbol.getValue(), colors.union(getSymbolColors(symbol)), symbol.getType()) for symbol in
            symbols)
        super().replaceClause(clause, symbols)

    def replaceClauses(self, clauses: Collection[Clause[T]], symbols: Tuple[Symbol]):
        for prod, group in itertools.groupby(sorted(clauses), key=lambda x: x.getProd()):
            # TODO 此处可以化简一下，表示为将Clause替换为nt。
            self.replaceProd(prod, Prod(prod.getNt(), buildSymbols(prod.newClause(), list(group), symbols)))

    def mergeClauses(self, clauses: Collection[Clause]) -> Tuple[str, Dict]:
        clauses = {self.refreshClause(clause) for clause in clauses}
        maskClauses = set()
        nt = self.newNt()
        prodClauseDict = {}
        for clause in sorted(clauses, key=len):
            # 找到最大的几个subClause
            msc = getMaximalSubClauses(clause, clauses)
            maskClauses = maskClauses.union(msc)
            newProd = Prod(nt, buildSymbols(clause, msc, (Symbol(nt),)))
            self.addProd(newProd)
            prodClauseDict[newProd] = clause
        self.replaceClauses(clauses.difference(maskClauses), (Symbol(nt),))
        return nt, prodClauseDict
