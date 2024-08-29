from Tokenize import Token
from Tokenize.Tokenizers.__Lark import LarkTokenizer


def test_tokenize():
    lark_str = """
        start: WORD+
        %import common.WORD
        %ignore " "
    """
    tokenizer = LarkTokenizer(lark_str)
    tokens = tokenizer.tokenize("Hello world")
    assert len(tokens) == 2
    assert tokens[0].type() == "WORD"
    assert tokens[0].value() == "Hello"
    assert tokens[1].type() == "WORD"
    assert tokens[1].value() == "world"

def test_instantiate():
    lark_str = """
        start: WORD+
        %import common.WORD
        %ignore " "
    """
    tokenizer = LarkTokenizer(lark_str, tokenSep=" ")
    tokens = [Token("WORD", "Hello"), Token("WORD", "world")]
    instantiated = tokenizer.instantiate(tokens)
    assert instantiated == "Hello world"
