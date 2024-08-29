from Bubble import Bubble
from DataTypes import Grammar, ColoredGrammar
from Sample import GrammarSampler, NtSampler


class BubbleSampler(GrammarSampler):
    def __init__(self, grammar: Grammar, bubble: Bubble) -> None:
        grammar = ColoredGrammar(grammar.copy())
        super().__init__(grammar)
        nt, _ = grammar.mergeClauses(set(bubble))
        sampler = NtSampler(grammar, nt)
        self._data = sampler.sample()

    def sample(self):
        return self._data
