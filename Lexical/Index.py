import itertools
import random
from typing import Optional, Tuple

from Tokenize import Token
from typing import Collection


class SeqIndex:
    def __init__(self, seq: Tuple, index: int):
        self.seq = seq
        self.index = index

    def getSeq(self, mask: Optional = None):
        value = mask
        if mask is None:
            value = self.seq[self.index]
        maskedSeq = self.seq[:self.index] + (value,) + self.seq[self.index + 1:]
        return maskedSeq

    def __eq__(self, other):
        return self.index == other.index and self.seq == other.seq

    def __hash__(self):
        return hash((self.seq, self.index))


class SeqIndexSet:
    def __init__(self, indexes: Collection[SeqIndex]):
        self.__indexDict = {}
        # Seq:[None,None,...set(),set(),set()...]
        for k, vs in itertools.groupby(sorted(indexes, key=lambda x: x.seq), key=lambda x: x.seq):
            indexes = {i.index for i in vs}
            key = tuple([k[index] if index not in indexes else None for index in range(len(k))])
            if key not in self.__indexDict:
                self.__indexDict[key] = [k[index] if index not in indexes else set() for index in range(len(k))]
            for i in indexes:
                self.__indexDict[key][i].add(k[i])

    def getSeqs(self, mask):
        seqs = set()
        for i in range(5):
            for key in self.__indexDict:
                seq = []
                for t in key:
                    if t is None:
                        t = mask
                    seq.append(t)
                seqs.add(tuple(seq))
        return seqs

    def getMultiMaskSeqs(self, masks: Collection):
        masks = {i: 0 for i in masks}
        seqs = set()
        c = 0
        prob = 0.7
        while c < len(masks)*10:
            for key in self.__indexDict:
                seq = []
                used = False
                for i, t in enumerate(key):
                    if t is None and random.random() < prob:
                        seq.append(random.choice(list(self.__indexDict[key][i])))
                        continue
                    if t is None:
                        t = min(masks.keys(), key=lambda x: masks[x])
                        masks[t] += 1
                        c += 1
                        used = True
                    seq.append(t)
                if not used:
                    continue
                seqs.add(tuple(seq))
        for mask in masks.keys():
            for key in self.__indexDict:
                seqs.add(tuple(map(lambda x: x if x is not None else mask, key)))
        return seqs
