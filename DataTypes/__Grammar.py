import queue
from enum import Enum
from typing import Collection, FrozenSet, Generic, Iterable, List, Optional, Sequence, Set, Tuple, \
    TypeVar, Union

from colored import bg, attr

from Config import getClauseColor, getShowRepr
from Oracle.Raw import LarkOracle
from Oracle.Tokenized import TokenizedOracle
from Tokenize import Token
from Tokenize.Tokenizers import DefaultTokenizer


class SymbolType(Enum):
    Default = 0
    Rep0 = 1
    Rep1 = 2
    Opt = 3
    def __repr__(self):
        return 'SymbolType.%s' % self.name


T = TypeVar('T', bound=Union[str, Token])


class Symbol(Generic[T]):
    def __init__(self, value: T, symbolType: SymbolType = SymbolType.Default) -> None:
        self.__value = value
        self.__type = symbolType
        self.__isTerminal = isinstance(value, Token)

    def __repr__(self) -> str:
        return "Symbol(%s,%s)" % (repr(self.getValue()), repr(self.getType()))

    def getValue(self) -> T:
        return self.__value

    def isTerminal(self) -> bool:
        return self.__isTerminal

    def getType(self) -> SymbolType:
        return self.__type

    def __hash__(self) -> int:
        return hash((self.__value, self.__type))

    def __lt__(self, other) -> bool:
        return isinstance(other, Symbol) and str(self) < str(other)

    def __str__(self) -> str:
        value = str(self.getValue()).replace("\\","\\\\").replace('"', '\\"')
        if self.__isTerminal:
            value = '"%s"' % value
        if self.getType() == SymbolType.Default:
            return value
        elif self.getType() == SymbolType.Opt:
            return "%s?" % value
        elif self.getType() == SymbolType.Rep0:
            return "%s*" % value
        elif self.getType() == SymbolType.Rep1:
            return "%s+" % value
        raise Exception()

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, Symbol):
            return False
        return self.getType() == other.getType() and self.getValue() == other.getValue()


def symbols2str(symbols: Sequence[Symbol[T]]):
    return ' '.join(map(str, symbols))


def tokens2symbols(tokens: Iterable[Token]) -> Tuple[Symbol, ...]:
    return tuple(Symbol(token) for token in tokens)


class Context(Generic[T]):
    def __init__(self, prefix: Sequence[Symbol[T]], suffix: Sequence[Symbol[T]]) -> None:
        self.__prefix = tuple(prefix)
        self.__suffix = tuple(suffix)

    def getPrefix(self):
        return self.__prefix

    def getSuffix(self):
        return self.__suffix

    def assembly(self, symbols: Iterable[Symbol[T]]) -> Tuple[Symbol, ...]:
        return self.__prefix + tuple(symbols) + self.__suffix

    def __str__(self) -> str:
        return symbols2str(self.getPrefix()) + bg('blue') + ' ' + attr('reset') + symbols2str(self.getSuffix())

    def __eq__(self, other: object) -> bool:
        return isinstance(other,
                          Context) and self.getPrefix() == other.getPrefix() and self.getSuffix() == other.getSuffix()


class Prod(Generic[T]):
    def __init__(self, nt: T, symbols: Sequence[Symbol[T]]) -> None:
        self.__nt = nt
        self.__symbols = tuple(symbols)

    def isTerminalProd(self) -> bool:
        for symbol in self.__symbols:
            if not symbol.isTerminal():
                return False
        return True

    def isSingleNt(self):
        return self.newClause().isSingleNt()

    def getValueNt(self) -> T:
        assert self.isSingleNt()
        return self[0].getValue()

    def getNt(self) -> T:
        return self.__nt

    def getSymbols(self) -> Tuple[Symbol[T], ...]:
        return self.__symbols

    def __iter__(self):
        for symbol in self.getSymbols():
            yield symbol

    def newClause(self, left: int = None, right: int = None) -> "Clause[T]":
        if left is None:
            left = 0
        if right is None:
            right = len(self)
        return Clause(self, left, right)

    def __repr__(self) -> str:
        return "Prod(%s,%s)" % (repr(self.getNt()), repr(self.getSymbols()))

    def clauses(self):
        for i in range(len(self)):
            for j in range(i + 1, len(self) + 1):
                yield self.newClause(i, j)

    def __hash__(self) -> int:
        return hash((self.__nt, self.__symbols))

    def __lt__(self, other) -> bool:
        return isinstance(other, Prod) and (self.__nt, self.__symbols) < (other.__nt, other.__symbols)

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, Prod):
            return False
        return (self.__nt, self.__symbols) == (other.__nt, other.__symbols)

    def __str__(self) -> str:
        return '%s: %s' % (str(self.__nt), symbols2str(self.__symbols))

    def __len__(self) -> int:
        return len(self.__symbols)

    def __getitem__(self, index) -> Symbol[T]:
        return self.__symbols[index]


class Clause(Generic[T]):
    def __init__(self, prod: Prod[T], left: int, right: int) -> None:
        self.__prod = prod
        self.__left = left
        self.__right = right

    def isSingleNt(self) -> bool:
        """
        判断当前clause是否仅为一个非终结符.
        :return:
        """
        return len(self) == 1 and not next(iter(self)).isTerminal()

    def getValueNt(self) -> T:
        assert self.isSingleNt()
        return self.getValue()[0].getValue()

    def isProd(self) -> bool:
        return len(self) == len(self.__prod)

    def __repr__(self) -> str:
        return "Clause(%s,%s,%s)" % (repr(self.__prod), repr(self.__left), repr(self.__right))

    def isSub(self, other: "Clause[T]") -> bool:
        return self.__prod == other.__prod and self.__left >= other.__left and self.__right <= other.__right

    def __lt__(self, other):
        return isinstance(other, Clause) and (self.__prod, self.__left, self.__right) < (
            other.__prod, other.__left, other.__right)

    def __len__(self) -> int:
        return self.getRight() - self.getLeft()

    def getNt(self) -> str:
        return self.__prod.getNt()

    def getProd(self):
        return self.__prod

    def getLeft(self) -> int:
        return self.__left

    def getRight(self) -> int:
        return self.__right

    def getPrefix(self) -> Tuple[Symbol, ...]:
        return self.__prod.getSymbols()[:self.getLeft()]

    def getSuffix(self) -> Tuple[Symbol, ...]:
        return self.__prod.getSymbols()[self.getRight():]

    def getValue(self) -> Tuple[Symbol[T], ...]:
        return self.__prod.getSymbols()[self.getLeft():self.getRight()]

    def __iter__(self):
        for symbol in self.getValue():
            yield symbol

    def __str__(self) -> str:
        ret = "%s:" % self.getProd().getNt()
        if self.getLeft() == self.getRight():
            p, s = ' '.join(map(str, self.getPrefix())), ' '.join(map(str, self.getSuffix()))
            return ret + (' ' if self.getLeft() != 0 else '') + p + bg(getClauseColor()) + ' ' + attr('reset') + s
        for index, symbol in enumerate(self.__prod):
            if index == self.getRight():
                if not getShowRepr():
                    ret += attr('reset')
                else:
                    ret += ' s '
            ret += ' '
            if index == self.getLeft():
                if not getShowRepr():
                    ret += bg(getClauseColor())
                else:
                    ret += ' s '
            ret += str(symbol)
        if len(self.__prod) == self.getRight():
            if not getShowRepr():
                ret += attr('reset')
            else:
                ret += ' s '
        return ret

    def __hash__(self) -> int:
        return hash((self.__prod, self.__left, self.__right))

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, Clause):
            return False
        return (self.__prod, self.__left, self.__right) == (other.__prod, other.__left, other.__right)


class Rule(Generic[T]):
    def __init__(self, nt: T, body: Collection[Prod[T]]) -> None:
        self.__nt = nt
        self.__body = set()
        self.__order = {}
        for i in body:
            self.addProd(i)

    def __repr__(self):
        return "Rule({}, {})".format(repr(self.__nt), repr(self.__body))

    def __len__(self) -> int:
        return len(self.__body)

    def getNt(self) -> T:
        return self.__nt

    def __str__(self) -> str:
        if len(self.__body) == 0:
            return '%s: ' % str(self.__nt)
        iterator = iter(sorted(self.__body,key=lambda x:self.__order[x]))
        ret = str(next(iterator))
        for prod in iterator:
            ret += '\n  | %s' % symbols2str(prod.getSymbols())
        return ret

    def addProd(self, prod: Prod[T]) -> None:
        self.__body.add(prod)
        self.__order[prod] = len(self.__order)

    def removeProd(self, prod: Prod[T]) -> None:
        self.__body.remove(prod)

    def findProd(self, prod: Prod[T]) -> bool:
        return prod in self.__body

    def getProds(self) -> Tuple[Prod[T], ...]:
        return tuple(self.__body)

    def __iter__(self):
        for prod in self.getProds():
            yield prod

    def __eq__(self, other: object) -> bool:
        return isinstance(other, Rule) and (self.__nt, self.__body) == (other.__nt, other.__body)

    def __hash__(self) -> int:
        return hash((self.__nt, frozenset(self.__body)))


class Grammar(Generic[T]):
    def __init__(self, start: T, rules: Collection[Rule[T]]) -> None:
        self._start = start
        self._rules = {rule.getNt(): rule for rule in rules}
        if start not in self._rules:
            self._rules[start] = Rule(start, [])

    def __repr__(self):
        return "Grammar(%s,%s)" % (repr(self._start),repr(list(self._rules.values())))

    def setStart(self, start: T):
        self._start = start

    def copy(self):
        import copy
        return Grammar(self._start, copy.deepcopy(self.getRules()))

    def getStart(self) -> T:
        return self._start

    def __iter__(self):
        for rule in self.getRules():
            yield rule

    def getRule(self, nt: T) -> Rule[T]:
        if nt not in self._rules:
            raise Exception("Rule of {0} not found\n\n{1}".format(repr(nt), str(self)))
        return self._rules[nt]

    def getRules(self) -> Tuple[Rule[T], ...]:
        return tuple(self._rules.values())

    def getRefers(self, symbolValue: T) -> List[Clause]:
        refers = []
        for prod in self.getProds():
            for i, symbol in enumerate(prod):
                if symbol.getValue() == symbolValue:
                    refers.append(prod.newClause(i, i + 1))
        return refers

    def getReachableRefers(self, nt: T) -> List[Clause]:
        """
        统计所有的可以到达的refer,包括 n1 -> n2
        我们会找n1的所有refer
        :param nt:
        :return:
        """
        ntQ = queue.Queue()
        ntQ.put(nt)
        result = []
        while not ntQ.empty():
            nt = ntQ.get()
            refers = self.getRefers(nt)
            for refer in refers:
                if refer.getProd().isSingleNt():
                    ntQ.put(refer.getNt())
                else:
                    result.append(refer)
        return result

    def __str__(self) -> str:
        return '\n'.join(['start:%s' % self.getStart()] + [str(rule) for rule in self._rules.values()])

    def getNts(self) -> FrozenSet[T]:
        return frozenset(self._rules.keys())

    def addRule(self, rule: Rule[T]) -> None:
        self._rules[rule.getNt()] = rule

    def addProd(self, prod: Prod[T]) -> None:
        if not self.findNt(prod.getNt()):
            self.addRule(Rule(prod.getNt(), []))
        self._rules[prod.getNt()].addProd(prod)

    def replaceClause(self, clause: Clause[T], symbols: Tuple[Symbol]):
        assert self.findProd(clause.getProd())
        newProd = Prod(clause.getNt(), clause.getPrefix() + symbols + clause.getSuffix())
        self.replaceProd(clause.getProd(), newProd)
        return newProd

    def getProds(self, nt: Optional[str] = None):
        nts = [nt]
        if nt is None:
            nts = self.getNts()
        for nt in nts:
            for prod in self.getRule(nt).getProds():
                yield prod

    def removeRule(self, nt: T) -> None:
        self._rules.pop(nt)

    def removeProd(self, prod: Prod[T]) -> None:
        self._rules[prod.getNt()].removeProd(prod)

    def findNt(self, nt: T) -> bool:
        return nt in self._rules

    def findProd(self, prod: Prod[T]) -> bool:
        return self.findNt(prod.getNt()) and self._rules[prod.getNt()].findProd(prod)

    def replaceProd(self, prod: Prod[T], newProd: Prod[T]):
        self.removeProd(prod)
        self.addProd(newProd)

    def getOracle(self) -> TokenizedOracle:
        class GrammarTokenizer(DefaultTokenizer):
            def instantiateToken(self, token: Token) -> str:
                return token.type()

        return TokenizedOracle(LarkOracle(str(self)), GrammarTokenizer())

    def clauses(self):
        for prod in self.getProds():
            for clause in prod.clauses():
                yield clause

    def newNt(self, prefix: str = 'n') -> str:
        index = 0
        while True:
            nt = "%s%d" % (prefix, index)
            if self.findNt(nt):
                index += 1
                continue
            return nt

    def __eq__(self, other: object) -> bool:
        return isinstance(other, Grammar) and (other._start, other._rules) == (self._start, self._rules)

    def __hash__(self) -> int:
        return hash(str(self))

    def isReachable(self, nt: str, symbols: Tuple[Symbol]):
        if symbols in {i.getSymbols() for i in self.getProds(nt)}:
            return True
        for ntProd in self.getProds(nt):
            if ntProd.isSingleNt() and self.isReachable(ntProd.getSymbols()[0].getValue(), symbols):
                return True
        return False

    def getReachableProds(self, nt: str) -> Set[Prod]:
        """
        获取可以到达的非终结符的产生式，不包括单nt产生式
        :param nt:
        :return:
        """
        q = queue.Queue()
        q.put(nt)
        prods = set()
        visited = {nt}
        while not q.empty():
            nt = q.get()
            for prod in self.getProds(nt):
                if prod.isSingleNt():
                    if prod.getValueNt() in visited:
                        continue
                    q.put(prod.getValueNt())
                    visited.add(prod.getValueNt())
                else:
                    prods.add(prod)
        return prods

    def getAllReachableProds(self, nt: str) -> Set[Prod]:
        """
        获取可以到达的所有产生式,包括单nt产生式
        :param nt:
        :return:
        """
        q = queue.Queue()
        q.put(nt)
        prods = set()
        visited = {nt}
        while not q.empty():
            nt = q.get()
            for prod in self.getProds(nt):
                prods.add(prod)
                if prod.isSingleNt():
                    if prod.getValueNt() in visited:
                        continue
                    q.put(prod.getValueNt())
                    visited.add(prod.getValueNt())
        return prods

    def getReachableNts(self, nt: str) -> Set[str]:
        q = queue.Queue()
        q.put(nt)
        nts = set()
        while not q.empty():
            nt = q.get()
            for prod in self.getProds(nt):
                if prod.isSingleNt():
                    nts.add(prod.getValueNt())
                    q.put(prod.getValueNt())
        return nts

    def fork(self, symbols: Tuple[Symbol]) -> "Grammar":
        import queue
        start = self.newNt()
        rules = []
        ntQueue = queue.Queue()
        visited = set()
        # 构造出发语法
        rules.append(Rule(start, [Prod(start, symbols)]))
        for symbol in symbols:
            if symbol.isTerminal():
                continue
            ntQueue.put(symbol.getValue())
            visited.add(symbol.getValue())
        while not ntQueue.empty():
            nt = ntQueue.get()
            rules.append(self.getRule(nt))
            for prod in self.getProds(nt):
                for symbol in prod:
                    if symbol.isTerminal():
                        continue
                    if symbol.getValue() in visited:
                        continue
                    ntQueue.put(symbol.getValue())
                    visited.add(symbol.getValue())
        return Grammar(start, rules)