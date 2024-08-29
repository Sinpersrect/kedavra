from typing import Union, Tuple, Collection

from Bubble import Bubble
from Bubble.Sample import BubbleSampler
from DataTypes import Grammar, Clause, Context, Symbol, Prod, ColoredGrammar
from Eval import BubbleEvaluator
from Instantiate.ContextIns import RandomizedContextInstantiator
from Instantiate.SymbolIns import StaticSymbolInstantiator
from Oracle.Symbolized import SymbolizedOracle
from Oracle.Tokenized import TokenizedOracle
from Sample import NtSampler
from Swap import NaiveSwapChecker, SwapRecord
from Tokenize import Token
from Tool import str1


class InferSession:
    def __init__(self, grammar: Grammar, prod: Prod, env: "InferEnv"):
        self.__si = StaticSymbolInstantiator(grammar)
        self.__symbolizedOracle = SymbolizedOracle(env.getGoldenOracle(), self.__si)
        self.__ci = RandomizedContextInstantiator(grammar)
        self.__grammar = ColoredGrammar(grammar)
        self.__env = env
        self.__grammarOracle = grammar.getOracle()
        self.__prod = prod
        self.__swapChecker = NaiveSwapChecker(grammar, env.getGoldenOracle(), self.__si, self.__ci)
        self.__swapRecords = {}
        if prod is not None:
            self.__lackGenColor = self.__grammar.attachColor(prod.newClause())

    def instantiate(self, symbols: Tuple[Symbol, ...]) -> Tuple[Token, ...]:
        return self.__si.instantiate(symbols)

    def showGeneralizedData(self):
        for record in self.__swapRecords.values():
            record: SwapRecord
            for positive in record.positive:
                if not self.getGrammarOracle().parse(positive):
                    print(str1(positive))

    def update(self, grammar: Grammar):
        self.__grammar = ColoredGrammar(grammar)
        self.__si = StaticSymbolInstantiator(grammar)
        self.__ci = RandomizedContextInstantiator(grammar)
        self.__grammarOracle = grammar.getOracle()
        self.__swapChecker = NaiveSwapChecker(grammar, self.__env.getGoldenOracle(), self.__si, self.__ci)

    def isLackGen(self, prod: Prod):
        return prod in self.getLackGenProds()

    def getLackGenProds(self):
        return [clause.getProd() for clause in self.__grammar.getColoredClauses(self.__lackGenColor) if clause.isProd()]

    def larkGen(self):
        return len(self.getLackGenProds()) > 0

    def chooseLackGenProd(self):
        self.__prod = self.getLackGenProds()[0]
        return self.getLackGenProds()[0]

    def setFindGen(self, prod: Prod):
        self.__grammar.clearColor(prod.newClause(), self.__lackGenColor)

    def getProd(self):
        return self.__prod

    def getGrammarOracle(self) -> TokenizedOracle:
        return self.__grammarOracle

    def getGoldenOracle(self) -> TokenizedOracle:
        return self.__env.getGoldenOracle()

    def getEnv(self) -> "InferEnv":
        return self.__env

    def getGrammar(self):
        return self.__grammar

    def getContext(self, clauseOrNt: Union[str, Clause]) -> Context:
        return self.__ci.instantiate(clauseOrNt)

    def isSwappable(self, clause1: Clause, clause2: Clause) -> bool:
        key = frozenset((clause1, clause2))
        if clause1.getValue() == clause2.getValue():
            self.__swapRecords[key] = SwapRecord(clause1, clause2, (), (), True)
            return True
        if key not in self.__swapRecords:
            swapRecord = self.__swapChecker.check(clause1, clause2)
            self.__swapRecords[key] = swapRecord
        return self.__swapRecords[key].swappable

    def getSwapRecord(self, clause1: Clause, clause2: Clause) -> SwapRecord:
        key = frozenset((clause1, clause2))
        if key not in self.__swapRecords:
            self.isSwappable(clause1, clause2)
        return self.__swapRecords[key]

    def parse(self, symbols: Tuple[Symbol, ...]):
        return self.__symbolizedOracle.parse(symbols)

    def createBubbleSession(self, bubble: Bubble):
        return BubbleSession(self, bubble)

    def isClauseBalanced(self, clause: Clause):
        tokens = self.__si.instantiate(clause.getValue())
        ps = ['()', '[]', '{}']
        pstack = []
        for token in tokens:
            for p in ps:
                if token.value() == p[0]:
                    pstack.append(p[0])
                elif token.value() == p[1]:
                    if len(pstack) == 0 or pstack[-1] != p[0]:
                        return False
                    else:
                        pstack.pop()
        return len(pstack) == 0


def freq(x):
    if x[1] == 0:
        return 0
    return x[0] / x[1]


class BubbleSession:
    def __init__(self, inferSession: InferSession, bubble: Bubble):
        self._positive = None
        self._negative = None
        self._inferSession = inferSession
        self._fullBubble = bubble
        self._grammarAfter = inferSession.getGrammar().copy()
        nt, _ = self._grammarAfter.mergeClauses(set(bubble))
        self._nt = nt
        self._genEvaluator = None
        self._genScoreCache = {}
        self._overGenCache = {}

    def isOverGeneralized(self, bubble: Bubble) -> bool:
        if bubble in self._overGenCache:
            return self._overGenCache[bubble]
        self.__checkEvaluator()
        # 构造语法
        grammar = self._inferSession.getGrammar().copy()
        nt, _ = grammar.mergeClauses(set(bubble))
        # 检查negative case
        grammarOracle: TokenizedOracle = grammar.getOracle()
        for negative in sorted(self._negative.keys(), key=lambda x: freq(self._negative[x]), reverse=True):
            if grammarOracle.parse(negative):
                a, b = self._negative[negative]
                self._negative[negative] = (a + 1, b + 1)
                self._overGenCache[bubble] = True
                return True
            else:
                a, b = self._negative[negative]
                self._negative[negative] = (a, b + 1)  # 将其改造为一个频率统计器，专门用一个class来做这件事。
        # 此处采取对grammar的nt采样
        bubbleSampler = BubbleSampler(self._inferSession.getGrammar(), bubble)
        for sample in bubbleSampler.sample():
            if self._inferSession.getGrammarOracle().parse(sample):
                continue
            if not self._inferSession.getGoldenOracle().parse(sample):
                self._negative[sample] = (1, 1)
                self._overGenCache[bubble] = True
                return True
        self._overGenCache[bubble] = False
        return False

    def setBenchmark(self, samples: Collection[Tuple[Token]]):
        self._positive = []
        self._negative = {}
        for sample in samples:
            if self._inferSession.getGrammarOracle().parse(sample):
                continue
            if self._inferSession.getGoldenOracle().parse(sample):
                self._positive.append(sample)
            else:
                self._negative[sample] = (0, 0)
        self._genEvaluator = BubbleEvaluator(self._positive,ColoredGrammar(self._inferSession.getGrammar()))

    def __createDefaultBenchmark(self):
        sampler = NtSampler(self._grammarAfter, self._nt)
        return sampler.sample()

    def __checkEvaluator(self):
        if self._genEvaluator is None:
            self.setBenchmark(self.__createDefaultBenchmark())

    def getGenScore(self, bubble: Bubble) -> float:
        self.__checkEvaluator()
        if bubble not in self._genScoreCache:
            self._genScoreCache[bubble] = self._genEvaluator.evaluate(bubble)
        return self._genScoreCache[bubble]

    def getInferSession(self):
        return self._inferSession

    def getBubble(self):
        return self._fullBubble


class InferEnv:
    def __init__(self, oracle: TokenizedOracle, trainData=None):
        if trainData is None:
            trainData = []
        self._oracle = oracle
        self._train = list(trainData)
        self._grammar = ColoredGrammar(Grammar('n0', []))
        self._grammarOracle = self._grammar.getOracle()

    def getGrammarOracle(self):
        return self._grammarOracle

    def createSession(self, grammar: Grammar, prod: Prod):
        return InferSession(grammar, prod, self)

    def getGoldenOracle(self):
        return self._oracle

    def getTrainTokens(self):
        ret = self._train[0]
        self._train = self._train[1:]
        return ret

    def getGrammar(self):
        return self._grammar

    def update(self, grammar: ColoredGrammar):
        self._grammar = grammar
        self._grammarOracle = self._grammar.getOracle()

    def hasData(self):
        return len(self._train) > 0

