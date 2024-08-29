import itertools
from abc import abstractmethod
from typing import Optional

from Bubble import Bubble
from Bubble.Sample import BubbleSampler
from DataTypes.Graph.__UndirectedGraph import UndirectedGraph
from Env import BubbleSession, InferSession
from Sample import NtSampler
from SetCheck import SetChecker
from Tool import str1


class BubbleFilter:
    def __init__(self, bubbleSession: BubbleSession):
        self._bubbleSession = bubbleSession

    @abstractmethod
    def getBubble(self) -> Optional[Bubble]:
        pass


def getSubBubble(inferSession: InferSession, bubble: Bubble):
    values = {clause.getValue() for clause in bubble if not inferSession.isLackGen(clause.getProd())}
    # 值->clauses的映射
    valueMap = {value: set() for value in values}
    for clause in bubble:
        if clause.getValue() not in valueMap:
            continue
        valueMap[clause.getValue()].add(clause)
    # 构造无向图
    graph = UndirectedGraph()
    for value in values:
        graph.addNode(value)
    setChecker = SetChecker(inferSession.getGrammar())
    for value1, value2 in itertools.permutations(values, 2):
        if setChecker.isSubset(value1, value2):
            graph.addEdge(value1, value2, True)
    # 构造第二个图
    fGraph = UndirectedGraph()
    for clause in bubble:
        fGraph.addNode(clause)
    for clause1, clause2 in itertools.combinations(bubble, 2):
        if not inferSession.isLackGen(clause1.getProd()) and not inferSession.isLackGen(clause2.getProd()):
            if graph.findEdge(clause1.getValue(), clause2.getValue()):
                fGraph.addEdge(clause1, clause2, True)
                continue
        if setChecker.isDirectReachable(clause1, clause2) or setChecker.isDirectReachable(clause2, clause1):
            fGraph.addEdge(clause1, clause2)
            continue
        if not inferSession.isSwappable(clause1, clause2):
            fGraph.addEdge(clause1, clause2)
    # 计算极大独立集
    miss = fGraph.getMISs()
    bubbles = [Bubble(mis) for mis in miss]

    # 过滤一下，排除所有prod都是良好泛化的
    def valid(b: Bubble):
        for clause in b:
            if inferSession.isLackGen(clause.getProd()):
                return True
        return False

    bubbles = list(filter(valid, bubbles))

    for i in range(len(bubbles)):
        for j in range(i + 1, len(bubbles)):
            rev = False
            for clause1 in bubbles[i]:
                for clause2 in bubbles[j]:
                    if not inferSession.isLackGen(clause1.getProd()) and not inferSession.isLackGen(clause2.getProd()):
                        if setChecker.isSubset(clause1.getValue(), clause2.getValue()):
                            rev = True
                            break
                if rev:
                    break
            if rev:
                bubbles[i], bubbles[j] = bubbles[j], bubbles[i]
    return bubbles
  


def reduceBubble(bubble: Bubble, bubbleSession: BubbleSession) -> Bubble:
    score = bubbleSession.getGenScore(bubble)
    clauses = set(bubble)
    if len(clauses) == 0:
        return Bubble(clauses)
    for clause in bubble:
        if clause not in clauses:
            continue
        newClauses = clauses.difference({clause})
        if bubbleSession.getGenScore(Bubble(newClauses)) < score:
            continue
        clauses = newClauses
    return Bubble(clauses)


def filterBubble(bubble: Bubble, bubbleSession: BubbleSession) -> Bubble:
    genScore = bubbleSession.getGenScore(bubble)
    if not bubbleSession.isOverGeneralized(bubble):
        if genScore > 0:
            return reduceBubble(bubble,bubbleSession)
        return Bubble(set())
    if genScore == 0:
        return Bubble(set())
    basicScore = bubbleSession.getGenScore(bubble)
    clauses = set(bubble)
    for clause in bubble:
        newBubble = Bubble(clauses.difference({clause}))
        if bubbleSession.getGenScore(newBubble) < basicScore:
            continue
        clauses.remove(clause)
    visited = {frozenset()}

    # 搜索clauses的子集，找出无过度泛化时，最高泛化分数
    def search(current: set):
        maxScore = 0
        optimalClauses = set()
        for clause in clauses:
            if clause in current:
                continue
            newCurrent = current.union({clause})
            if frozenset(newCurrent) in visited:
                continue
            if bubbleSession.isOverGeneralized(Bubble(newCurrent)):
                continue
            score = bubbleSession.getGenScore(Bubble(newCurrent))
            if score > maxScore:
                maxScore = score
                optimalClauses = newCurrent
            visited.add(frozenset(newCurrent))
            score, newOpt = search(newCurrent)
            if score > maxScore:
                maxScore = score
                optimalClauses = newOpt
            if maxScore == 1:
                break
        return maxScore, optimalClauses

    score, clauses = search(set())
    return reduceBubble(Bubble(clauses),bubbleSession)


class NaiveBubbleFilter(BubbleFilter):
    def __init__(self, bubbleSession: BubbleSession):
        super().__init__(bubbleSession)

    def getBubble(self) -> Optional[Bubble]:
        # 在为BubbleSession构造Sample时，我们先分解，再对分解后的各个Bubble构造Sample.
        subBubbles = getSubBubble(self._bubbleSession.getInferSession(), self._bubbleSession.getBubble())
        # TODO 如果subBubble的每个prod都是良好泛化的，那么就可以直接跳过了

        # 采样
        # TODO 这段代码应该分离出来
        samples = set()
        oracles = []
        for subBubble in subBubbles:
            grammar = self._bubbleSession.getInferSession().getGrammar().copy()
            sampler = BubbleSampler(grammar, subBubble)
            for sample in sampler.sample():
                invalid = False
                for oracle in oracles:
                    if oracle.parse(sample):
                        invalid = True
                        break
                if not invalid or not self._bubbleSession.getInferSession().getGoldenOracle().parse(sample):
                    samples.add(sample)
            oracles.append(sampler.getGrammar().getOracle())
        self._bubbleSession.setBenchmark(samples)
        subBubbleScore = {}
        # 先计算各个bubble的分数.
        for subBubble in subBubbles:
            subBubbleScore[subBubble] = self._bubbleSession.getGenScore(subBubble)
        maxScore = 0
        optBubble = None
        for subBubble in subBubbles:
            # 如果当前subBubble的分数已经低于maxScore,那么我们直接跳过即可，因为它再过滤也不能超过maxScore
            if subBubbleScore[subBubble] <= maxScore:
                # TODO 检查，之前我们并没有跳过，这里可能导致性能下降严重
                continue
            filteredBubble = filterBubble(subBubble, self._bubbleSession)  # 2024-05-05 23:40:06]
            score = self._bubbleSession.getGenScore(filteredBubble)
            if score > maxScore:
                optBubble = filteredBubble
                maxScore = score
            if maxScore == 1:
                break
        return optBubble


class BubblePreFilter(BubbleFilter):
    def __init__(self, bubbleSession: BubbleSession):
        super().__init__(bubbleSession)

    def getBubble(self) -> Optional[Bubble]:
        # Bubble预过滤
        toRemove = set()
        clauses = set(self._bubbleSession.getBubble())
        for clause in clauses:
            diff = False
            for other in clauses:
                if clause.getValue() == other.getValue():
                    continue
                if self._bubbleSession.getInferSession().isSwappable(clause, other):
                    diff = True
                    break
            if not diff:
                toRemove.add(clause)
        return Bubble(clauses.difference(toRemove))
