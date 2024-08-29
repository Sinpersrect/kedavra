from abc import abstractmethod
from typing import Collection, Tuple

from Bubble import BubbleRecord, Bubble
from DataTypes import Grammar, ColoredGrammar
from Oracle.Tokenized import TokenizedOracle
from Sample import NtSampler
from Tokenize import Token
from Tool import str1


class BenchmarkGenerator:
    @abstractmethod
    def generate(self):
        pass


class GrammarEvaluator:
    def __init__(self, benchmark: Collection[Tuple[Token]]):
        self.__benchmark = benchmark

    def evaluate(self, grammarOracle: TokenizedOracle):
        """
        我们只接受语法对应的oracle
        :param grammarOracle:
        :return:
        """
        score = 0
        for tokens in self.__benchmark:
            if grammarOracle.parse(tokens):
                score += 1
        if score == 0:
            return 0
        return score / len(self.__benchmark)


class BubbleEvaluator:
    def __init__(self, benchmark: Collection[Tuple[Token]], grammar: ColoredGrammar):
        self.__benchmark = set(benchmark)
        self.__cache = {}
        self.__grammar = grammar
        # cache会记录它有哪些是可以接受的

    def evaluate(self, bubble: Bubble):
        if bubble in self.__cache:
            return len(self.__cache[bubble]) / len(self.__benchmark)
        if len(self.__benchmark)==0:
            return 0
        clauses = set(bubble)
        grammar = self.__grammar.copy()
        grammar.mergeClauses(clauses)
        # 先寻找当前bubble的子集
        parsed = set()
        notParsed = set()
        for cachedBubble in self.__cache:
            cachedClauses = set(cachedBubble)
            if cachedClauses.issubset(clauses):
                parsed = parsed.union(self.__cache[cachedBubble])
            elif cachedClauses.issuperset(clauses):
                notParsed = notParsed.union(self.__benchmark.difference(self.__cache[cachedBubble]))
        check = self.__benchmark.difference(parsed).difference(notParsed)
        oracle = grammar.getOracle()
        for tokens in check:
            if oracle.parse(tokens):
                parsed.add(tokens)
        self.__cache[bubble] = parsed
        return len(parsed) / len(self.__benchmark)
