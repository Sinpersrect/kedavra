from Tokenize import Token
from Tokenize.Tokenizers.__Keyword import KeywordTokenizer


def test_tokenize():
    tokenizer = KeywordTokenizer(['int','while','true','break'])
    sentence = "int a = 42; while (true) { break; }"
    expected_tokens = [Token('int', 'int'), Token('IDENT', 'a'), Token('=', '='), Token('NUM', '42'), Token(';', ';'),
                       Token('while', 'while'), Token('(', '('), Token('true', 'true'), Token(')', ')'),
                       Token('{', '{'),
                       Token('break', 'break'), Token(';', ';'), Token('}', '}')]
    assert tokenizer.tokenize(sentence) == tuple(expected_tokens)
    assert tokenizer.tokenize(tokenizer.instantiate(expected_tokens)) == tokenizer.tokenize(sentence)


def test_instantiateToken():
    tokenizer = KeywordTokenizer(['int'])
    token1 = Token('int', 'int')
    token2 = Token('IDENT', 'a')
    token3 = Token(';', ';')
    assert tokenizer.instantiateToken(token1) == 'int'
    assert tokenizer.instantiateToken(token2) == 'a'
    assert tokenizer.instantiateToken(token3) == ';'
