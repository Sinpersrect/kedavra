"""
词法推导的结果有:
lexicalDict
tokenizedData
spaceSensitive
"""
from typing import Tuple, List, Dict, Collection

from DataTypes import Grammar, Prod, Symbol
from Instantiate.Ins import DefaultTokenInstantiator
from Lexical.Classify import mergeAll, getTTVM, getIndexes
from Lexical.Combine import isSingle
from Lexical.Generalize import IndexesOracle, processGrammarForNum, processProd, generalizeRep, generalizeCharset, \
    createCharset, CharsetGrammar
from Lexical.Name import NameAllocator
from Lexical.PreTokenize import PreTokenizer
from Oracle.Raw import RawOracle, LarkOracle
from Tokenize import Token
from Tool import str1


class LexicalResult:
    def __init__(self, data, lexicalDict, spaceSensitive):
        self.data = data
        self.lexicalDict = lexicalDict
        self.spaceSensitive = spaceSensitive


def lexicalInfer(rawData: Collection[str], oracle: RawOracle) -> LexicalResult:
    # 预标记化输入程序
    tokenizedData = PreTokenizer.tokenizeAll(rawData)
    # 合并等价Token,以及检测空格敏感性
    tc = mergeAll(tokenizedData, oracle)
    data = tc.getTokenizedData()
    ttvm = getTTVM(data)

    def processDataByLexicalDict(lexicalDict, data):
        na = NameAllocator()
        transDict = {}
        newLexicalDict = {}
        for k, v in lexicalDict.items():
            name = k
            if not isSingle(v):
                name = na.name()
            transDict[k] = name
            newLexicalDict[name] = v
        ret = set()
        for tokens in data:
            newTokens = [Token(transDict[token.type()], token.value()) for token in tokens]
            ret.add(tuple(newTokens))
        return newLexicalDict, ret

    lexicalDict = {}
    for k, v in ttvm.items():
        io = IndexesOracle(getIndexes(data, [k]), oracle, tc.getInstantiator())
        g = CharsetGrammar('n0', [])
        charset = ''
        for sentence in v:
            charset += ''.join(set(sentence))
        if len(set(createCharset('a-z')).intersection(charset)) > 0:
            charset += createCharset('a-z')
        if len(set(createCharset('A-Z')).intersection(charset)) > 0:
            charset += createCharset('A-Z')
        if len(set(createCharset('0-9')).intersection(charset)) > 0:
            charset += createCharset('0-9')
        charset = ''.join(sorted(set(charset)))
        for sentence in sorted(v, key=len):
            if LarkOracle(str(g)).parse(sentence):
                continue
            prod = Prod('n0', [Symbol(Token(i, i)) for i in sentence])
            g.addProd(prod)
            for i in range(len(prod)):
                prod = generalizeCharset(g, prod.newClause(i, i + 1), charset, io, DefaultTokenInstantiator())
                prod = generalizeRep(g, prod.newClause(i, i + 1), io, DefaultTokenInstantiator())
            processProd(g, prod)
        g = processGrammarForNum(g)
        lexicalDict[k] = g
    lexicalDict, data = processDataByLexicalDict(lexicalDict, data)
    return LexicalResult(list(data), lexicalDict, tc.isSpaceSensitive())
