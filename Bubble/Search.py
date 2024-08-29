from abc import abstractmethod
from typing import Optional

from Bubble import Bubble
from Env import InferSession

class BubbleSearcher:
    @abstractmethod
    def search(self, session: InferSession) -> Optional[Bubble]:
        pass


class NaiveBubbleSearcher(BubbleSearcher):
    def __init__(self, balanceParen=True):
        self._balanceParen = balanceParen

    def search(self, session: InferSession) -> Optional[Bubble]:
        oracle = session.getGrammarOracle()
        clausesDict = {}
        generalized = False
        for clause in session.getProd().clauses():
            if not session.isClauseBalanced(clause):
                continue
            clauses = {clause}
            # 计算swap，并且评分
            score = 0
            for other in session.getGrammar().clauses():
                if clause == other:
                    continue
                if not session.isClauseBalanced(other):
                    continue
                if session.isSwappable(clause, other):
                    clauses.add(other)
                    for sentence in session.getSwapRecord(clause, other).positive:
                        if not oracle.parse(sentence):
                            score += 1
                            generalized = True
                            break
            # 统计哪些可以泛化，可以产生泛化的数量作为一个评分标准
            finalScore = (score, len(clauses), -sum(map(len, clauses)) / len(clauses))
            clausesDict[frozenset(clauses)] = finalScore
        # 如果没有泛化，我们直接返回None
        if not generalized:
            return None
        return Bubble(max(clausesDict.keys(), key=lambda x: clausesDict[x]))


"""
;
f ;
6 ;
{ ; }
h < f ;
6 - f ;
o = x ;
( x ) ;
s + 2 ;
if ( f ) ;
while ( f ) ;
do ; while ( y ) ;
if ( l ) { } else ;
"""
