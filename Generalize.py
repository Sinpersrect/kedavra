from abc import abstractmethod

from Bubble.Filter import NaiveBubbleFilter, BubblePreFilter
from Bubble.Search import NaiveBubbleSearcher
from Env import InferSession


class ProdGeneralizer:
    @abstractmethod
    def generalize(self, inferSession: InferSession) -> bool:
        pass


class NaiveProdGeneralizer(ProdGeneralizer):
    def __init__(self, balanceParen: bool):
        self._balanceParen = balanceParen

    def generalize(self, inferSession: InferSession) -> bool:
        nbs = NaiveBubbleSearcher(self._balanceParen)
        bubble = nbs.search(inferSession)  # 已计时
        if bubble is None:
            return False
        bubbleSession = inferSession.createBubbleSession(bubble)  # 已计时
        bpf = BubblePreFilter(bubbleSession)
        preFilteredBubble = bpf.getBubble()
        bubbleSession = inferSession.createBubbleSession(preFilteredBubble)  # 已计时
        nbf = NaiveBubbleFilter(bubbleSession)  # 几乎不花费时间
        filteredBubble = nbf.getBubble()  # 已计时
        if filteredBubble is None:
            return False
        grammar = inferSession.getGrammar()
        grammar = filteredBubble.apply(grammar).grammarAfter  # 已计时
        inferSession.update(grammar)
        return True
