from Oracle.Raw import LarkOracle
from typing import Any, Iterable
from Consts import SEP
from colored import bg, attr


def loadLarkOracle(larkPath: str):
    return LarkOracle(open(larkPath).read())


def str1(obj: Any):
    if isinstance(obj, Iterable):
        return ' '.join(map(str, obj))
    return str(obj)


def title(s):
    print(bg('yellow') + SEP)
    print(s)
    print(SEP + attr('reset'))
