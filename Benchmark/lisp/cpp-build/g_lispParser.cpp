
// Generated from g_lisp.g4 by ANTLR 4.7.2



#include "g_lispParser.h"


using namespace antlrcpp;
using namespace antlr4;

g_lispParser::g_lispParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

g_lispParser::~g_lispParser() {
  delete _interpreter;
}

std::string g_lispParser::getGrammarFileName() const {
  return "g_lisp.g4";
}

const std::vector<std::string>& g_lispParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& g_lispParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

g_lispParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_lispParser::SexpressionContext* g_lispParser::StartContext::sexpression() {
  return getRuleContext<g_lispParser::SexpressionContext>(0);
}

tree::TerminalNode* g_lispParser::StartContext::EOF() {
  return getToken(g_lispParser::EOF, 0);
}


size_t g_lispParser::StartContext::getRuleIndex() const {
  return g_lispParser::RuleStart;
}


g_lispParser::StartContext* g_lispParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_lispParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(10);
    sexpression();
    setState(11);
    match(g_lispParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SexpressionContext ------------------------------------------------------------------

g_lispParser::SexpressionContext::SexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_lispParser::AtomicsymbolContext* g_lispParser::SexpressionContext::atomicsymbol() {
  return getRuleContext<g_lispParser::AtomicsymbolContext>(0);
}

std::vector<g_lispParser::SexpressionContext *> g_lispParser::SexpressionContext::sexpression() {
  return getRuleContexts<g_lispParser::SexpressionContext>();
}

g_lispParser::SexpressionContext* g_lispParser::SexpressionContext::sexpression(size_t i) {
  return getRuleContext<g_lispParser::SexpressionContext>(i);
}

std::vector<tree::TerminalNode *> g_lispParser::SexpressionContext::EMPTY() {
  return getTokens(g_lispParser::EMPTY);
}

tree::TerminalNode* g_lispParser::SexpressionContext::EMPTY(size_t i) {
  return getToken(g_lispParser::EMPTY, i);
}

g_lispParser::ListContext* g_lispParser::SexpressionContext::list() {
  return getRuleContext<g_lispParser::ListContext>(0);
}


size_t g_lispParser::SexpressionContext::getRuleIndex() const {
  return g_lispParser::RuleSexpression;
}


g_lispParser::SexpressionContext* g_lispParser::sexpression() {
  SexpressionContext *_localctx = _tracker.createInstance<SexpressionContext>(_ctx, getState());
  enterRule(_localctx, 2, g_lispParser::RuleSexpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(23);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(13);
      atomicsymbol();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(14);
      match(g_lispParser::T__0);
      setState(15);
      sexpression();
      setState(16);
      match(g_lispParser::EMPTY);
      setState(17);
      match(g_lispParser::T__1);
      setState(18);
      match(g_lispParser::EMPTY);
      setState(19);
      sexpression();
      setState(20);
      match(g_lispParser::T__2);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(22);
      list();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListContext ------------------------------------------------------------------

g_lispParser::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<g_lispParser::SexpressionContext *> g_lispParser::ListContext::sexpression() {
  return getRuleContexts<g_lispParser::SexpressionContext>();
}

g_lispParser::SexpressionContext* g_lispParser::ListContext::sexpression(size_t i) {
  return getRuleContext<g_lispParser::SexpressionContext>(i);
}

std::vector<tree::TerminalNode *> g_lispParser::ListContext::EMPTY() {
  return getTokens(g_lispParser::EMPTY);
}

tree::TerminalNode* g_lispParser::ListContext::EMPTY(size_t i) {
  return getToken(g_lispParser::EMPTY, i);
}


size_t g_lispParser::ListContext::getRuleIndex() const {
  return g_lispParser::RuleList;
}


g_lispParser::ListContext* g_lispParser::list() {
  ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, getState());
  enterRule(_localctx, 4, g_lispParser::RuleList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25);
    match(g_lispParser::T__0);
    setState(26);
    sexpression();
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == g_lispParser::EMPTY) {
      setState(27);
      match(g_lispParser::EMPTY);
      setState(28);
      sexpression();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(34);
    match(g_lispParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomicsymbolContext ------------------------------------------------------------------

g_lispParser::AtomicsymbolContext::AtomicsymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_lispParser::AtomicsymbolContext::LETTER() {
  return getToken(g_lispParser::LETTER, 0);
}

g_lispParser::AtompartContext* g_lispParser::AtomicsymbolContext::atompart() {
  return getRuleContext<g_lispParser::AtompartContext>(0);
}


size_t g_lispParser::AtomicsymbolContext::getRuleIndex() const {
  return g_lispParser::RuleAtomicsymbol;
}


g_lispParser::AtomicsymbolContext* g_lispParser::atomicsymbol() {
  AtomicsymbolContext *_localctx = _tracker.createInstance<AtomicsymbolContext>(_ctx, getState());
  enterRule(_localctx, 6, g_lispParser::RuleAtomicsymbol);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(39);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(36);
      match(g_lispParser::LETTER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(37);
      match(g_lispParser::LETTER);
      setState(38);
      atompart();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtompartContext ------------------------------------------------------------------

g_lispParser::AtompartContext::AtompartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_lispParser::AtompartContext::LETTER() {
  return getToken(g_lispParser::LETTER, 0);
}

tree::TerminalNode* g_lispParser::AtompartContext::NUMBER() {
  return getToken(g_lispParser::NUMBER, 0);
}

g_lispParser::AtompartContext* g_lispParser::AtompartContext::atompart() {
  return getRuleContext<g_lispParser::AtompartContext>(0);
}


size_t g_lispParser::AtompartContext::getRuleIndex() const {
  return g_lispParser::RuleAtompart;
}


g_lispParser::AtompartContext* g_lispParser::atompart() {
  AtompartContext *_localctx = _tracker.createInstance<AtompartContext>(_ctx, getState());
  enterRule(_localctx, 8, g_lispParser::RuleAtompart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(41);
      match(g_lispParser::LETTER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(42);
      match(g_lispParser::NUMBER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(43);
      match(g_lispParser::LETTER);
      setState(44);
      atompart();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(45);
      match(g_lispParser::NUMBER);
      setState(46);
      atompart();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> g_lispParser::_decisionToDFA;
atn::PredictionContextCache g_lispParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN g_lispParser::_atn;
std::vector<uint16_t> g_lispParser::_serializedATN;

std::vector<std::string> g_lispParser::_ruleNames = {
  "start", "sexpression", "list", "atomicsymbol", "atompart"
};

std::vector<std::string> g_lispParser::_literalNames = {
  "", "'('", "'.'", "')'", "", "", "' '"
};

std::vector<std::string> g_lispParser::_symbolicNames = {
  "", "", "", "", "LETTER", "NUMBER", "EMPTY"
};

dfa::Vocabulary g_lispParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> g_lispParser::_tokenNames;

g_lispParser::Initializer::Initializer() {
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
    0x3, 0x8, 0x34, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x1a, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x20, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0x23, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x2a, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x32, 0xa, 0x6, 0x3, 0x6, 0x2, 0x2, 0x7, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0x2, 0x2, 0x2, 0x35, 0x2, 0xc, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x19, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x31, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x5, 0x4, 
    0x3, 0x2, 0xd, 0xe, 0x7, 0x2, 0x2, 0x3, 0xe, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0xf, 0x1a, 0x5, 0x8, 0x5, 0x2, 0x10, 0x11, 0x7, 0x3, 0x2, 0x2, 0x11, 
    0x12, 0x5, 0x4, 0x3, 0x2, 0x12, 0x13, 0x7, 0x8, 0x2, 0x2, 0x13, 0x14, 
    0x7, 0x4, 0x2, 0x2, 0x14, 0x15, 0x7, 0x8, 0x2, 0x2, 0x15, 0x16, 0x5, 
    0x4, 0x3, 0x2, 0x16, 0x17, 0x7, 0x5, 0x2, 0x2, 0x17, 0x1a, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x1a, 0x5, 0x6, 0x4, 0x2, 0x19, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x19, 0x10, 0x3, 0x2, 0x2, 0x2, 0x19, 0x18, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x7, 0x3, 0x2, 0x2, 0x1c, 
    0x21, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x1e, 0x7, 0x8, 0x2, 0x2, 0x1e, 0x20, 
    0x5, 0x4, 0x3, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x24, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x25, 0x7, 0x5, 0x2, 0x2, 0x25, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x2a, 0x7, 0x6, 0x2, 0x2, 0x27, 0x28, 0x7, 0x6, 0x2, 0x2, 0x28, 
    0x2a, 0x5, 0xa, 0x6, 0x2, 0x29, 0x26, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x32, 0x7, 
    0x6, 0x2, 0x2, 0x2c, 0x32, 0x7, 0x7, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x6, 
    0x2, 0x2, 0x2e, 0x32, 0x5, 0xa, 0x6, 0x2, 0x2f, 0x30, 0x7, 0x7, 0x2, 
    0x2, 0x30, 0x32, 0x5, 0xa, 0x6, 0x2, 0x31, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x31, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x31, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x32, 0xb, 0x3, 0x2, 0x2, 0x2, 0x6, 0x19, 
    0x21, 0x29, 0x31, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

g_lispParser::Initializer g_lispParser::_init;
