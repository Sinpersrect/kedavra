import time
from abc import abstractmethod
from typing import Collection

from tqdm import tqdm
from DataTypes.__Grammar import Grammar, Symbol
from Instantiate.SymbolIns import RandomizedSymbolInstantiator, ArvadaSymbolInstantiator, SymbolInstantiator
from Oracle.Raw import RawOracle
from Tokenize import Tokenizer


class GrammarEvaluation:
    def __init__(self, precision, recall, infer_time, oracle_time, calls, NT, A, lA, S, T, tp):
        self.precision = precision
        self.recall = recall
        self.infer_time = infer_time
        self.oracle_time = oracle_time
        self.calls = calls
        self.NT = NT
        self.A = A
        self.lA = lA
        self.S = S
        self.T = T
        self.tp = tp


    def f1(self):
        return 2 * self.precision * self.recall / (self.precision + self.recall)

    def __str__(self):
        return str({
            'precision': self.precision,
            'recall': self.recall,
            'f1': self.f1(),
            'infer_time': self.infer_time,
            'oracle_time': self.oracle_time,
            'calls': self.calls,
            'NT': self.NT,
            'A': self.A,
            'l(A)': self.lA,
            'S': self.S,
            'T': self.T,
            'tp': self.tp
        })


def grammarComplexity(grammar: Grammar) -> int:
    complexity = 0
    for nt in grammar.getNts():
        for prod in grammar.getRule(nt).getProds():
            complexity += len(prod)
    return complexity


class RawSampler:
    @abstractmethod
    def sample(self) -> str:
        pass


class TreevadaGrammarSampler(RawSampler):
    def __init__(self, grammar: Grammar, tokenizer: Tokenizer):
        self.__grammar = grammar
        self.__asi = ArvadaSymbolInstantiator(grammar)
        self.__tokenizer = tokenizer

    def sample(self) -> str:
        tokens = self.__asi.instantiateSymbol(Symbol(self.__grammar.getStart()))
        return self.__tokenizer.instantiate(tokens)


class ArvadaGrammarSampler(RawSampler):
    def __init__(self, grammar: Grammar, tokenizer: Tokenizer):
        self.__grammar = grammar
        self.__asi = ArvadaSymbolInstantiator(grammar)
        self.__tokenizer = tokenizer

    def sample(self) -> str:
        tokens = self.__asi.instantiateSymbol(Symbol(self.__grammar.getStart()))
        ret = self.__tokenizer.instantiate(tokens)
        if len(ret) > 300:
            return self.sample()
        return ret


class SiGrammarSampler(RawSampler):
    def __init__(self, si: SymbolInstantiator, tokenizer: Tokenizer):
        self.__grammar = si.getGrammar()
        self.__si = si
        self.__tokenizer = tokenizer

    def sample(self) -> str:
        tokens = self.__si.instantiateSymbol(Symbol(self.__grammar.getStart()))
        ret = self.__tokenizer.instantiate(tokens)
        return ret


class WrappedGrammar:
    def __init__(self, grammar: Grammar, sampler: RawSampler, oracle: RawOracle):
        self.__sampler = sampler
        self.__oracle = oracle
        self.grammar = grammar

    def sample(self) -> str:
        return self.__sampler.sample()

    def parse(self, s: str) -> bool:
        return self.__oracle.parse(s)


def evaluateGrammar(grammar: WrappedGrammar, testSet: Collection[str], inferStatistics,
                    oracle: RawOracle, path: str) -> GrammarEvaluation:
    # 评估precision
    logfile = open(path, mode='w')
    print(grammar.grammar, file=logfile)
    precision = 0
    precisionSet = set()
    while len(precisionSet) < 1000:
        precisionSet.add(grammar.sample())
    print('Eval of precision:')
    print('Eval of precision:', file=logfile)
    for sentence in tqdm(precisionSet):
        print(sentence, file=logfile)
        if oracle.parse(sentence):
            print("Passed", file=logfile)
            precision += 1
        else:
            print('Failed', file=logfile)
    precision /= 1000
    # 评估recall
    recall = 0
    start_parse = time.time()
    print('Eval of recall:')
    print('Eval of recall:', file=logfile)
    for sentence in tqdm(testSet):
        print(sentence, file=logfile)
        if grammar.parse(sentence):
            print("Passed", file=logfile)
            recall += 1
        else:
            print("Failed", file=logfile)
    parse_time = time.time() - start_parse
    if len(testSet) > 0:
        recall /= len(testSet)
    # 评估语法的相关参数
    terminals = set()
    S = 0
    for prod in grammar.grammar.getProds():
        S += len(prod)
        for symbol in prod:
            if not symbol.isTerminal():
                continue
            terminals.add(symbol.getValue().type())
    T = len(terminals)
    A = len(list(grammar.grammar.getProds()))
    evaluation = GrammarEvaluation(precision, recall, inferStatistics['infer_time'],
                                   inferStatistics['oracle_time'],
                                   inferStatistics['calls'], len(grammar.grammar.getNts()), A, S / A, S, T, parse_time)
    print(str(evaluation), file=logfile)
    logfile.close()
    return evaluation


