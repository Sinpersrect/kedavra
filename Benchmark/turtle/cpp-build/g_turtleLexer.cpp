
// Generated from g_turtle.g4 by ANTLR 4.7.2


#include "g_turtleLexer.h"


using namespace antlr4;


g_turtleLexer::g_turtleLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

g_turtleLexer::~g_turtleLexer() {
  delete _interpreter;
}

std::string g_turtleLexer::getGrammarFileName() const {
  return "g_turtle.g4";
}

const std::vector<std::string>& g_turtleLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& g_turtleLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& g_turtleLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& g_turtleLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& g_turtleLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> g_turtleLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& g_turtleLexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> g_turtleLexer::_decisionToDFA;
atn::PredictionContextCache g_turtleLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN g_turtleLexer::_atn;
std::vector<uint16_t> g_turtleLexer::_serializedATN;

std::vector<std::string> g_turtleLexer::_ruleNames = {
  u8"T__0", u8"T__1", u8"T__2", u8"T__3", u8"T__4", u8"MOVEMENT", u8"COLOR", 
  u8"NUMBER", u8"SPACE"
};

std::vector<std::string> g_turtleLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> g_turtleLexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> g_turtleLexer::_literalNames = {
  "", u8"'c'", u8"'fill'", u8"'repeat'", u8"'{'", u8"'}'", "", "", "", u8"' '"
};

std::vector<std::string> g_turtleLexer::_symbolicNames = {
  "", "", "", "", "", "", u8"MOVEMENT", u8"COLOR", u8"NUMBER", u8"SPACE"
};

dfa::Vocabulary g_turtleLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> g_turtleLexer::_tokenNames;

g_turtleLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x2, 0xb, 0x33, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 
    0x4, 0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
    0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x6, 0x8, 0x2c, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x2d, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x2, 0x2, 0xb, 0x3, 0x3, 0x5, 0x4, 0x7, 0x5, 
    0x9, 0x6, 0xb, 0x7, 0xd, 0x8, 0xf, 0x9, 0x11, 0xa, 0x13, 0xb, 0x3, 0x2, 
    0x3, 0x6, 0x2, 0x64, 0x64, 0x68, 0x68, 0x6e, 0x6e, 0x74, 0x74, 0x2, 
    0x33, 0x2, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x2, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 0x3, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x5, 0x17, 0x3, 0x2, 0x2, 0x2, 0x7, 0x1c, 
    0x3, 0x2, 0x2, 0x2, 0x9, 0x23, 0x3, 0x2, 0x2, 0x2, 0xb, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xd, 0x27, 0x3, 0x2, 0x2, 0x2, 0xf, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x11, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x13, 0x31, 0x3, 0x2, 0x2, 0x2, 0x15, 
    0x16, 0x7, 0x65, 0x2, 0x2, 0x16, 0x4, 0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 
    0x7, 0x68, 0x2, 0x2, 0x18, 0x19, 0x7, 0x6b, 0x2, 0x2, 0x19, 0x1a, 0x7, 
    0x6e, 0x2, 0x2, 0x1a, 0x1b, 0x7, 0x6e, 0x2, 0x2, 0x1b, 0x6, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x1d, 0x7, 0x74, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x67, 0x2, 
    0x2, 0x1e, 0x1f, 0x7, 0x72, 0x2, 0x2, 0x1f, 0x20, 0x7, 0x67, 0x2, 0x2, 
    0x20, 0x21, 0x7, 0x63, 0x2, 0x2, 0x21, 0x22, 0x7, 0x76, 0x2, 0x2, 0x22, 
    0x8, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x7, 0x7d, 0x2, 0x2, 0x24, 0xa, 
    0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x7, 0x7f, 0x2, 0x2, 0x26, 0xc, 0x3, 
    0x2, 0x2, 0x2, 0x27, 0x28, 0x9, 0x2, 0x2, 0x2, 0x28, 0xe, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x2b, 0x4, 0x43, 0x5c, 0x2, 0x2a, 0x2c, 0x4, 0x63, 0x7c, 
    0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x10, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x4, 0x32, 0x3b, 0x2, 0x30, 0x12, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0x22, 0x2, 0x2, 0x32, 0x14, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x2, 0x2d, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

g_turtleLexer::Initializer g_turtleLexer::_init;