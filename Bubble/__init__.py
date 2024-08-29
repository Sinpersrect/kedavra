import itertools
import queue
from typing import Collection, Tuple

from DataTypes import Clause, loadClause, ColoredGrammar, Prod, Grammar, Symbol
from SetCheck import SetChecker
from Tool import str1


def simplifyValues(grammar: Grammar, values: Collection[Tuple[Symbol]]):
    sc = SetChecker(grammar)
    toRemove = set()
    for i, j in itertools.permutations(values, 2):
        if i == j:
            continue
        if sc.isSubset(i, j):
            toRemove.add(i)
    return set(values).difference(toRemove)


class BubbleRecord:
    def __init__(self, bubble, grammarBefore, grammarAfter, nt):
        self.bubble = bubble
        self.grammarBefore = grammarBefore
        self.grammarAfter = grammarAfter
        self.nt = nt



class Bubble:
    def __init__(self, clauses: Collection[Clause]):
        self._clauses = frozenset(clauses)

    def __str__(self):
        return '\n'.join(map(str, self._clauses))

    def __hash__(self):
        return hash(self._clauses)

    def __eq__(self, other):
        return isinstance(other, Bubble) and self._clauses == other._clauses

    def __iter__(self):
        for clause in self._clauses:
            yield clause

    def apply(self, grammar: ColoredGrammar) -> BubbleRecord:
        """
        有两个阶段
        1. 找到所有有完整refer的非终结符nts
        2. 如果有,那么从其中选取一个,其他的非终结符的所有prod添加进values里面
        3. 如果没，构造一个新的非终结符
        """
        # 目前的BubbleApply算法具有较大问题
        grammarBefore = grammar.copy()
        grammar = grammar.copy()
        clauses = set(self)
        # 染色
        colors = {grammar.attachColor(clause) for clause in clauses}
        clauses = {grammar.refreshClause(clause) for clause in clauses}
        # 寻找具有完整refer的nts
        allNts = {clause.getValueNt() for clause in self if clause.isSingleNt()
                  and not clause.getValueNt() == grammar.getStart()}  # 出发符号此处不可以,因为使用有一个refer我们得不到.
        fullReferNts = set()
        for nt in allNts:
            if clauses.issuperset(grammar.getRefers(nt)):
                fullReferNts.add(nt)
        prods = {clause.getProd() for clause in self if clause.isProd()}
        for nt in grammar.getNts():
            if prods.issuperset(grammar.getProds(nt)):
                fullReferNts.add(nt)
        # 构造or选取一个非终结符作为最终装值的非终结符
        if len(fullReferNts) != 0:
            finalNt = next(iter(fullReferNts))
        else:
            finalNt = grammar.newNt()
        # 如果fullReferNts非空,我们需要将其中除了finalNt之外的所有值都取出来,构造values
        # 注意,此处不可能有某个clause可以到达另一个clause
        values = set()
        for clause in clauses:
            if clause.isSingleNt():
                nt = clause.getValueNt()
                if nt == finalNt:
                    continue
                if nt not in fullReferNts:
                    values.add(clause.getValue())
                    continue
                for prod in grammar.getProds(nt):
                    values.add(prod.getSymbols())
                continue
            values.add(clause.getValue())
        # 化简values
        values = simplifyValues(grammar, values)
        if len(values) == 1:
            value = next(iter(values))
            if not grammar.findNt(finalNt) and len(value) == 1 and not value[0].isTerminal():
                finalNt = value[0].getValue()
                values = set()
        # 添加产生式
        for value in values:
            grammar.addProd(Prod(finalNt, value))
        # 删除其他非终结符
        for nt in fullReferNts.difference({finalNt}):
            grammar.removeRule(nt)
        updatedClauses = set()
        for color in colors:
            for clause in grammar.getColoredClauses(color):
                if clause.isProd() and clause.getProd().getNt() == finalNt:
                    continue
                updatedClauses.add(clause)
        # 替换clause
        grammar.replaceClauses(updatedClauses, (Symbol(finalNt),))
        # 二义性消除.
        toRemove = set()
        setChecker = SetChecker(grammar)
        for nt in grammar.getNts():
            for prod1, prod2 in itertools.permutations(grammar.getProds(nt), 2):
                if setChecker.isSubset(prod1.getSymbols(), prod2.getSymbols()):
                    toRemove.add(prod1)
        for prod in toRemove:
            grammar.removeProd(prod)
        # 判断是否有仅有单nt prod的nt
        updated = True
        while updated:
            updated = False
            for nt in grammar.getNts():
                prods = list(grammar.getProds(nt))
                if len(prods) > 1:
                    continue
                prod = prods[0]
                if not prod.isSingleNt():
                    continue
                updated = True
                targetNt = prod.getValueNt()
                grammar.removeRule(nt)
                grammar.replaceClauses(grammar.getRefers(nt), (Symbol(targetNt),))
                if nt == grammar.getStart():
                    grammar.setStart(targetNt)
        # 判断是否有某个非终结符只有一个refer,且它的那个refer是单nt prod
        updated = True
        while updated:
            updated = False
            for nt in grammar.getNts():
                if grammar.getStart() == nt:
                    continue
                if len(grammar.getRefers(nt)) != 1:
                    continue
                refer = next(iter(grammar.getRefers(nt)))
                if refer.isProd() and refer.isSingleNt():
                    prods = list(grammar.getProds(nt))
                    grammar.removeRule(nt)
                    grammar.removeProd(refer.getProd())
                    referNt = refer.getNt()
                    newProds = [Prod(referNt, prod.getSymbols()) for prod in prods]
                    for newProd in newProds:
                        grammar.addProd(newProd)
                    updated = True
                    break
        # 判断穷举可达的所有nt,删除不可达的nt
        ntQ = queue.Queue()
        ntQ.put(grammar.getStart())
        visited = {grammar.getStart()}
        while not ntQ.empty():
            nt = ntQ.get()
            for prod in grammar.getProds(nt):
                for symbol in prod:
                    if symbol.isTerminal():
                        continue
                    newNt = symbol.getValue()
                    if newNt in visited:
                        continue
                    visited.add(newNt)
                    ntQ.put(newNt)
        for nt in grammar.getNts().difference(visited):
            grammar.removeRule(nt)
        return BubbleRecord(self, grammarBefore, grammar, finalNt)


def loadBubble(string: str) -> Bubble:
    clauses = list(map(loadClause, string.strip().split('\n')))
    return Bubble(clauses)

