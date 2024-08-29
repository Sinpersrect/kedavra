from Tokenize import Tokenizer, Token
from Tokenize.Tokenizers.__Default import DefaultTokenizer

def test_tokenize():
    tokenizer = DefaultTokenizer()
    sentence = "Hello world"
    expected_tokens = (Token('H', 'H'), Token('e', 'e'), Token('l', 'l'), Token('l', 'l'), Token('o', 'o'),
                       Token(' ', ' '), Token('w', 'w'), Token('o', 'o'), Token('r', 'r'), Token('l', 'l'), Token('d', 'd'))
    assert tokenizer.tokenize(sentence) == expected_tokens

def test_instantiate():
    tokenizer = DefaultTokenizer()
    tokens = [Token('H', 'H'), Token('e', 'e'), Token('l', 'l'), Token('l', 'l'), Token('o', 'o'),
              Token(' ', ' '), Token('w', 'w'), Token('o', 'o'), Token('r', 'r'), Token('l', 'l'), Token('d', 'd')]
    expected_result = "Hello world"
    assert tokenizer.instantiate(tokens) == expected_result

def test_instantiateToken():
    tokenizer = DefaultTokenizer()
    token = Token('H', 'H')
    expected_result = "H"
    assert tokenizer.instantiateToken(token) == expected_result
