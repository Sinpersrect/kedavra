from Decompose.XSeq import XSeq, Interval, XRSeq


def test_XSeq():
    a = XSeq([0] * 34)
    assert a.getRemovableIntervals() == [Interval(start=0, end=34)]
    a.remove(Interval(1, 3))
    assert a.getRemovableIntervals() == [Interval(start=0, end=1), Interval(start=3, end=34)]
    a.remove(Interval(32, 34))
    assert a.getRemovableIntervals() == [Interval(start=0, end=1), Interval(start=3, end=32)]
    a.remove(Interval(30, 32))
    assert a.getRemovableIntervals() == [Interval(start=0, end=1), Interval(start=3, end=30)]


def test_XRSeq():
    a = XSeq([0] * 34)
    b = XRSeq(a, 0)
    assert b.getRemovableIntervals() == [Interval(start=1, end=34)]
    c = XRSeq(a, 3)
    assert c.getRemovableIntervals() == [Interval(start=0, end=3), Interval(start=4, end=34)]


def test_subsets():
    a = Interval(0, 10)
    subsets = a.subsets()
    for i in range(len(subsets) - 1):
        assert len(subsets[i]) >= len(subsets[i + 1])
