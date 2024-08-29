from abc import abstractmethod
from itertools import product
from typing import List, Set, Tuple
from DataTypes import Grammar
from Instantiate.Tree import SyntaxNode
import queue
import random


class SyntaxNodeGrower:
    def __init__(self, grammar: Grammar) -> None:
        self._grammar = grammar

    @abstractmethod
    def grow(self, node: SyntaxNode) -> SyntaxNode:
        pass

    def getGrammar(self):
        return self._grammar


class StaticSNG(SyntaxNodeGrower):
    def __updateActionTable(self):
        for nt in self._grammar.getNts().difference(self.__action.keys()):
            for prod in self._grammar.getProds(nt):
                hasAction = True
                for symbol in prod:
                    if symbol.isTerminal():
                        continue
                    if symbol.getValue() not in self.__action:
                        hasAction = False
                        break
                if hasAction:
                    self.__action[nt] = prod
                    break

    def __initActionTable(self):
        while len(self.__action) < len(self._grammar.getNts()):
            self.__updateActionTable()

    def __init__(self, grammar: Grammar) -> None:
        super().__init__(grammar)
        self.__action = {}
        self.__initActionTable()

    def grow(self, node: SyntaxNode) -> SyntaxNode:
        if node.isTerminal():
            return node
        root = node
        growQueue = queue.Queue()
        growQueue.put(node)
        while not growQueue.empty():
            node = growQueue.get()
            node.produce(self.__action[node.getSymbol().getValue()])
            for child in node.getChildren():
                if not child.isTerminal():
                    growQueue.put(child)
        return root





class RandomizedSNG(SyntaxNodeGrower):
    def __init__(self, grammar: Grammar, maxDepth=20, maxProdUse=3) -> None:
        super().__init__(grammar)
        self.__terminateSNG = StaticSNG(grammar)
        self.__maxDepth = maxDepth
        self.__maxProdUse = maxProdUse

    def __grow(self, node: SyntaxNode, depth=0):
        if node.isTerminal():
            return node
        if depth >= self.__maxDepth:
            return self.__terminateSNG.grow(node)
        forbiddenProds = [prod for prod in self.__prodUsage.keys() if self.__prodUsage[prod] >= self.__maxProdUse]
        prods = list(set(self._grammar.getProds(node.getSymbol().getValue())).difference(forbiddenProds))
        if len(prods) == 0:
            return self.__terminateSNG.grow(node)
        randomProd = random.choice(prods)
        if randomProd not in self.__prodUsage:
            self.__prodUsage[randomProd] = 0
        self.__prodUsage[randomProd] += 1
        node.produce(randomProd)
        for child in node.getChildren():
            self.__grow(child, depth + 1)
        return node

    def grow(self, node: SyntaxNode) -> SyntaxNode:
        self.__prodUsage = {}
        return self.__grow(node)


class LevelSNG:
    def __init__(self, grammar: Grammar, maxLevel=1) -> None:
        self._grammar = grammar
        self.__terminateSNG = StaticSNG(grammar)
        self.__maxLevel = maxLevel

    def __permutate(self, node: SyntaxNode, childGrowsList: List[List[SyntaxNode]]):
        ret = []
        for i in [list(combination) for combination in product(*childGrowsList)]:
            nodeCopied = node.copy()
            nodeCopied.setChildren(i)
            ret.append(nodeCopied)
        return ret

    def __grow(self, node: SyntaxNode, level=0, mask: Set = set()) -> List[SyntaxNode]:
        # 此处我们添加一个：如果node是部分已生长的，我们不会试图去改变。
        if node.isTerminal():
            return [node]
        if level >= self.__maxLevel:
            return [self.__terminateSNG.grow(node)]
        ret = []
        prods = self._grammar.getProds(node.getSymbol().getValue())
        if node.getProd() is not None:
            prods = [node.getProd()]
        for prod in prods:
            # 避免递归：s -> n0 -> s
            if prod in mask:
                continue
            nextLevel = level + 1
            # 单nt的prod不增加level
            if prod.isSingleNt():
                mask.add(prod)
                nextLevel = level
            nodeCopied = node.copy()
            if nodeCopied.getProd() is None:
                nodeCopied.produce(prod)
            childGrowsList = []
            for child in nodeCopied.getChildren():
                childGrows = self.__grow(child, nextLevel)
                childGrowsList.append(childGrows)
            ret += self.__permutate(nodeCopied, childGrowsList)
            if prod.isSingleNt():
                mask.remove(prod)
        return ret

    def grow(self, node: SyntaxNode) -> Tuple[SyntaxNode, ...]:
        # 为了避免n0 -> n1 -> n2 .. nk导致的深度损失从而无法测试到较深层次
        # 我们增加了优化：当产生式为单nt时，不增加深度，但是为了避免递归，我们添加__mask来避免
        return tuple(self.__grow(node))


class ArvadaSNG(SyntaxNodeGrower):
    def __init__(self, grammar: Grammar, maxDepth) -> None:
        super().__init__(grammar)
        self.__maxDepth = maxDepth

    def __grow(self, node: SyntaxNode, depth=0):
        if node.isTerminal():
            return node
        prods = list(self._grammar.getProds(node.getSymbol().getValue()))
        if depth >= self.__maxDepth:
            terminalProds = [prod for prod in prods if prod.isTerminalProd()]
            if len(terminalProds) > 0:
                prods = terminalProds
        randomProd = random.choice(prods)
        node.produce(randomProd)
        children = list(node.getChildren())
        for child in children:
            self.__grow(child, depth + 1)
        return node

    def grow(self, node: SyntaxNode) -> SyntaxNode:
        return self.__grow(node)


class ProdLimitSNG(SyntaxNodeGrower):
    def __init__(self, grammar: Grammar, maxProdUsageRate=10) -> None:
        super().__init__(grammar)
        self.__maxProdUsage = int(maxProdUsageRate * len(list(grammar.getProds())))
        self.__terminateSNG = StaticSNG(grammar)

    def __grow(self, node: SyntaxNode):
        if node.isTerminal():
            return node
        if self.__prodUsage >= self.__maxProdUsage:
            return self.__terminateSNG.grow(node)
        prods = list(self._grammar.getProds(node.getSymbol().getValue()))
        randomProd = random.choice(prods)
        node.produce(randomProd)
        self.__prodUsage += 1
        children = list(node.getChildren())
        random.shuffle(children)
        for child in children:
            self.__grow(child)
        return node

    def grow(self, node: SyntaxNode) -> SyntaxNode:
        self.__prodUsage = 0
        return self.__grow(node)


class PerProdLimitSNG(SyntaxNodeGrower):
    def __init__(self, grammar: Grammar, maxProdUse=10) -> None:
        super().__init__(grammar)
        self.__terminateSNG = StaticSNG(grammar)
        self.__maxProdUse = maxProdUse

    def __grow(self, node: SyntaxNode):
        if node.isTerminal():
            return node
        forbiddenProds = [prod for prod in self.__prodUsage.keys() if self.__prodUsage[prod] >= self.__maxProdUse]
        prods = list(set(self._grammar.getProds(node.getSymbol().getValue())).difference(forbiddenProds))
        if len(prods) == 0:
            return self.__terminateSNG.grow(node)
        randomProd = random.choice(prods)
        if randomProd not in self.__prodUsage:
            self.__prodUsage[randomProd] = 0
        self.__prodUsage[randomProd] += 1
        node.produce(randomProd)
        for child in node.getChildren():
            self.__grow(child)
        return node

    def grow(self, node: SyntaxNode) -> SyntaxNode:
        self.__prodUsage = {}
        return self.__grow(node)



