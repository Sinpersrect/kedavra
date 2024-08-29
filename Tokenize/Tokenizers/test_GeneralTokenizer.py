from Tokenize import Token
from Tokenize.Tokenizers.__General import GeneralTokenizer


def test_tokenize():
    tokenizer = GeneralTokenizer()
    code = 'hello "world" 42 .'
    expected_tokens = (
    Token('IDENT', 'hello'), Token('DOUBLE_QUOTE_STRING', '"world"'), Token('NUM', '42'), Token('.', '.'))
    assert tokenizer.tokenize(code) == expected_tokens


def test_instantiateToken():
    tokenizer = GeneralTokenizer()
    token = Token('IDENT', 'hello')
    assert tokenizer.tokenize(tokenizer.instantiateToken(token)) == tokenizer.tokenize('hello')


def test_instantiate():
    tokenizer = GeneralTokenizer()
    tokens = [Token('IDENT', 'hello'), Token('DOUBLE_QUOTE_STRING', '"world"'), Token('NUM', '42'), Token('.', '.')]
    expected_result = 'hello "world" 42 .'
    assert tokenizer.tokenize(tokenizer.instantiate(tokens)) == tokenizer.tokenize(expected_result)
