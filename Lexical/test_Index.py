from Lexical.Index import SeqIndexSet, SeqIndex


def test_Indexes():
    ts = tuple([1, 2, 3])
    sis = SeqIndexSet([
        SeqIndex(ts, 0),
        SeqIndex(ts, 2),
    ])
    assert sis.getSeqs(4) == [(4, 2, 4), ]
