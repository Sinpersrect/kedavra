from typing import Tuple, List, Sequence
from Tokenize import Token
import itertools
from colored import bg, attr


class Interval:
    def __init__(self, start: int, end: int):
        self.start = start
        self.end = end

    def __hash__(self):
        return hash((self.start, self.end))

    def __eq__(self, other):
        return self.start == other.start and self.end == other.end

    def __str__(self):
        return "(%d,%d)" % (self.start, self.end)

    def __contains__(self, item):
        return self.start <= item < self.end

    def __len__(self):
        return self.end - self.start

    def subsets(self):
        subInts = [Interval(l, r) for l, r in itertools.combinations(range(self.start, self.end + 1), 2)]
        return list(sorted(subInts, key=len, reverse=True))


class XSeq:
    def __init__(self, seq: Sequence):
        self._seq = seq
        self._removed = [False] * len(seq)

    def getValue(self) -> Tuple[Token, ...]:
        ret = []
        for i, token in enumerate(self._seq):
            if not self._removed[i]:
                ret.append(token)
        return tuple(ret)

    def remove(self, interval: Interval):
        for i in range(interval.start, interval.end):
            self._removed[i] = True

    def getRemovableIntervals(self) -> List[Interval]:
        removable = [i for i in range(len(self._removed)) if not self._removed[i]]
        return [Interval(start, end) for start, end in itertools.combinations(removable, 2)]

    def copy(self):
        ret = XSeq(self._seq)
        ret._removed = list(self._removed)
        return ret

    def isRemovable(self, interval: Interval) -> bool:
        for i in range(interval.start, interval.end):
            if not self._removed[i]:
                return True
        return False

    def __eq__(self, other):
        return self._seq == other._seq and self._removed == other._removed

    def __hash__(self):
        return hash(self.getValue())

    def __len__(self):
        return len(self.getValue())

    def __str__(self):
        ret = []
        for i, token in enumerate(self._seq):
            if not self._removed[i]:
                if i == 0 or self._removed[i - 1]:
                    ret.append(bg('yellow'))
            if self._removed[i]:
                if i > 0 and not self._removed[i - 1]:
                    ret.append(attr('reset'))
            ret.append(str(token))
        ret.append(attr('reset'))
        return ' '.join(ret)


class XRSeq(XSeq):
    def __init__(self, xSeq: XSeq, reserve: int):
        super().__init__(xSeq._seq)
        self._removed = xSeq._removed
        self._xSeq = xSeq
        self._reserve = reserve

    def getRemovableIntervals(self) -> List[Interval]:
        removable = [i for i in range(len(self._removed)) if not self._removed[i] and i != self._reserve]
        return [Interval(start, end + 1) for start, end in itertools.combinations(removable, 2)]

    def remove(self, interval: Interval):
        for i in range(interval.start, interval.end):
            if i == self._reserve:
                continue
            self._removed[i] = True

    def copy(self):
        ret = XRSeq(self._xSeq.copy(), self._reserve)
        return ret

    def isRemovable(self, interval: Interval) -> bool:
        for i in range(interval.start, interval.end):
            if not self._removed[i] and i != self._reserve:
                return True
        return False
