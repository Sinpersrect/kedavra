import functools
import itertools
from typing import Collection, Tuple, Dict, Set, List, FrozenSet

from tqdm import tqdm

from DataTypes.Graph.__UndirectedGraph import UndirectedGraph
from DataTypes.__DisjointSet import DisjointSet
from Lexical.Index import SeqIndexSet, SeqIndex
from Instantiate.Ins import DefaultTokenInstantiator, SSTokenInstantiator
from Lexical.Name import NameAllocator
from Lexical.PreTokenize import PreTokenizer
from Oracle.Raw import RawOracle
from Tokenize import Token


def getTTVM(data: Collection[Tuple[Token, ...]]) -> Dict[str, Set[str]]:
    """
    获取TTVM(TokenTypeValueMap)
    :param data:
    :return:
    """
    ttvm = {}
    for tokens in data:
        for token in tokens:
            if token.type() not in ttvm:
                ttvm[token.type()] = set()
            ttvm[token.type()].add(token.value())
    return ttvm


def isSpaceSensitive(data: Collection[Tuple[Token, ...]], oracle: RawOracle):
    dti = DefaultTokenInstantiator()
    for tokens in data:
        for i, token in enumerate(tokens):
            if token.value() != ' ':
                continue
            if oracle.parse(dti.instantiate(tokens[:i] + (token,) + tokens[i:])):
                return False
    return True


def processNotSS(data: Collection[Tuple[Token, ...]], oracle: RawOracle) -> List[Tuple[Token, ...]]:
    """
    处理对Space不敏感的情况，主要做两件事。
    1. 通过插入Space来判断是否为一个Token
    :param data:
    :param oracle:
    :return:
    """
    newTokenizedData = []
    dti = DefaultTokenInstantiator()
    for tokens in data:
        tokens: Tuple[Token, ...]
        # 遍历tokens
        # 假设从i出发,我们往其后面添加空格，如果非法，则合并i+1对应的token
        # 至于token type,如果往后面添加空格后合法，那么我们将其保留原样，否则我们分配一个新的tokenType
        newTokens = []
        index = 0
        while index < len(tokens):
            if tokens[index].value() == ' ':
                index += 1
                continue
            if index == len(tokens) - 1:
                newTokens.append(tokens[index])
                break
            right = index + 1
            while right < len(tokens) and tokens[right].value() != ' ':
                insertSpaceTokens = tokens[:right] + (Token(' ', ' '),) + tokens[right:]
                insertSpace = dti.instantiate(insertSpaceTokens)
                if oracle.parse(insertSpace):
                    break
                right += 1
            newTokenValue = ''.join([token.value() for token in tokens[index:right] if token.value() != ' '])
            newTokenType = tokens[index].type()
            if right > index:
                newTokenType = newTokenValue
            newTokens.append(Token(newTokenType, newTokenValue))
            index = right
        newTokenizedData.append(tuple(newTokens))
    return newTokenizedData


def getIndexes(data, tokenTypes: Collection[str]) -> SeqIndexSet:
    tokenTypes = set(tokenTypes)
    indexes = []
    for tokens in data:
        for index, token in enumerate(tokens):
            if token.type() in tokenTypes:
                indexes.append(SeqIndex(tokens, index))
    return SeqIndexSet(indexes)


class TokenClassifier:
    def __init__(self, data: Collection[Tuple[Token, ...]], oracle: RawOracle):
        self.__spaceSensitive = isSpaceSensitive(data, oracle)
        self.__oracle = oracle
        self.__data = data
        self.__ti = DefaultTokenInstantiator()
        self.__mergeCache = {}
        if not self.__spaceSensitive:
            self.__data = processNotSS(data, oracle)
            self.__ti = SSTokenInstantiator()
        # 初始化并查集
        self.__dj = DisjointSet()
        for t in getTTVM(self.__data):
            self.__dj.getParent(t)

    def getInstantiator(self):
        return self.__ti

    def isSpaceSensitive(self):
        return self.__spaceSensitive

    def merge(self, tokenTypes: Collection[str]):
        functools.reduce(self.__dj.merge, tokenTypes)

    def isMergeable(self, tokenTypes: Collection[str]):
        key = frozenset(tokenTypes)
        if key in self.__mergeCache:
            return self.__mergeCache[key]
        for cachedKey in self.__mergeCache:
            if key.issuperset(cachedKey) and not self.__mergeCache[cachedKey]:
                self.__mergeCache[key] = False
                return False
        indexes = getIndexes(self.__data, tokenTypes)
        ttvm = getTTVM(self.__data)
        values = functools.reduce(lambda x, y: x.union(y), [ttvm[i] for i in tokenTypes])
        seqs = indexes.getMultiMaskSeqs([Token(value, value) for value in values])
        # 使用位置轮换的方法可以同时检验多个
        for seq in seqs:
            if not self.__oracle.parse(self.__ti.instantiate(seq)):
                self.__mergeCache[key] = False
                return False
        self.__mergeCache[key] = True
        return True

    def getTokenizedData(self):
        na = NameAllocator()
        sets = self.__dj.getSets()
        setsNameMap = {s: na.name() for s in sets if len(s) > 1}
        data = []
        for tokens in self.__data:
            newTokens = []
            for token in tokens:
                for s in sets:
                    if token.type() in s:
                        newTokens.append(Token(setsNameMap.get(s, token.type()), token.value()))
                        break
            data.append(tuple(newTokens))
        return data

def groupCliques(cliques: Set[FrozenSet]):
    finalGroup = {}
    allocated = set()
    fullSet = functools.reduce(lambda x, y: x.union(y), cliques)
    for k in fullSet:
        maxScore = 0
        maxClique = None
        for clique in cliques:
            if k not in clique:
                continue
            score = len(clique.difference(allocated).union(finalGroup.get(clique, set())))
            if score > maxScore:
                maxScore = score
                maxClique = clique
        if maxClique not in finalGroup:
            finalGroup[maxClique] = set()
        finalGroup[maxClique].add(k)
        allocated.add(k)
    return {frozenset(i) for i in finalGroup.values() if len(i) > 0}


def mergeAll(tokenizedData: Collection[Tuple[Token, ...]], oracle: RawOracle) -> TokenClassifier:
    tc = TokenClassifier(tokenizedData, oracle)
    ttvm = getTTVM(tc.getTokenizedData())
    # 初始化无向图
    graph = UndirectedGraph()
    for k in ttvm.keys():
        graph.addNode(k)
    # 按照PreTokenizer的分类
    for groupKey, values in itertools.groupby(sorted(ttvm.keys()), key=PreTokenizer.getBasicType):
        # 使用DFS搜索，从每个节点出发，维护一个集合
        cache = {}
        good = set()
        values = set(values)

        def dfs(c, ks, visited):
            for v in values.difference(ks).difference(visited):
                visited.add(v)
                cache[frozenset([c, v])] = tc.isMergeable([c, v])
                if cache[frozenset([c, v])]:
                    dfs(v, ks.union({v}), visited)
                    return
            if tc.isMergeable(ks):
                for i in ks:
                    good.add(i)
                for i, j in itertools.combinations(ks, 2):
                    cache[frozenset([i, j])] = True

        for k in values:
            if k in good:
                continue
            dfs(k, {k}, {k})
        for k1, k2 in tqdm(list(itertools.combinations(values, 2))):
            if frozenset([k1, k2]) in cache:
                mergeable = cache[frozenset([k1, k2])]
            else:
                mergeable = tc.isMergeable([k1, k2])
            if mergeable:
                graph.addEdge(k1, k2)
    cliques = graph.getMaximalCliques(True)

    graph = UndirectedGraph()
    group = groupCliques(cliques)
    for k in group:
        graph.addNode(k)
    for k1, k2 in itertools.combinations(group, 2):
        if tc.isMergeable(k1.union(k2)):
            graph.addEdge(k1, k2, True)
    cliques = graph.getMaximalCliques(True)
    for clique in cliques:
        t = functools.reduce(lambda x, y: x.union(y), clique)
        tc.merge(t)
    return tc
