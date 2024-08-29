from abc import abstractmethod
from Instantiate.ContextIns import RandomizedContextInstantiator
from Instantiate.SymbolIns import RandomizedSymbolInstantiator
from Instantiate.SyntaxNodeGrow import LevelSNG
from Instantiate.Tree import SyntaxNode
from DataTypes import Grammar, Symbol, Clause


class GrammarSampler:
    def __init__(self, grammar: Grammar) -> None:
        # 语法采样器
        self._grammar = grammar

    @abstractmethod
    def sample(self):
        pass

    def getGrammar(self):
        return self._grammar


class NtSampler(GrammarSampler):
    def __init__(self, grammar: Grammar, nt: str) -> None:
        super().__init__(grammar)
        self._nt = nt
        self._data = set()

    def __sampleNt(self):
        # 此处采用上下同时2阶采样
        level = 2
        # if len(list(self._grammar.getProds(self._nt))) >= 7:
        #    level = 1
        lsng = LevelSNG(self._grammar, level)
        # 我们应当从它的更上一级进行验证，这样才能考虑得更全面
        # 或者我们进行多重验证。
        rsi = RandomizedSymbolInstantiator(self._grammar)
        rci = RandomizedContextInstantiator(self._grammar)
        # 构造根节点

        roots = [SyntaxNode(Symbol(self._nt))]
        for ref in self._grammar.getReachableRefers(self._nt):
            root = SyntaxNode(Symbol(ref.getNt()))
            root.produce(ref.getProd())
            roots.append(root)

        # 遍历所有的根节点
        for root in roots:
            for sn in lsng.grow(root):
                context = rsi.instantiateContext(rci.instantiate(root.getSymbol().getValue()))
                tokens = context.assembly(sn.toTokens())
                self._data.add(tokens)
        for _ in range(15):
            context = rsi.instantiateContext(rci.instantiate(self._nt))
            tokens = context.assembly(rsi.instantiate((Symbol(self._nt),)))
            self._data.add(tokens)
            # print('y',tokens)

    @abstractmethod
    def sample(self):
        if len(self._data) == 0:
            self.__sampleNt()
        return self._data

    # IDENT - IDENT - IDENT
