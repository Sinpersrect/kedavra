
// Generated from g_arith.g4 by ANTLR 4.7.2



#include "g_arithParser.h"


using namespace antlrcpp;
using namespace antlr4;

g_arithParser::g_arithParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

g_arithParser::~g_arithParser() {
  delete _interpreter;
}

std::string g_arithParser::getGrammarFileName() const {
  return "g_arith.g4";
}

const std::vector<std::string>& g_arithParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& g_arithParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

g_arithParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_arithParser::ExprContext* g_arithParser::StartContext::expr() {
  return getRuleContext<g_arithParser::ExprContext>(0);
}

tree::TerminalNode* g_arithParser::StartContext::EOF() {
  return getToken(g_arithParser::EOF, 0);
}


size_t g_arithParser::StartContext::getRuleIndex() const {
  return g_arithParser::RuleStart;
}


g_arithParser::StartContext* g_arithParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_arithParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    expr();
    setState(9);
    match(g_arithParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

g_arithParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_arithParser::ExprContext::NUM() {
  return getToken(g_arithParser::NUM, 0);
}

g_arithParser::ExprpContext* g_arithParser::ExprContext::exprp() {
  return getRuleContext<g_arithParser::ExprpContext>(0);
}

g_arithParser::ExprContext* g_arithParser::ExprContext::expr() {
  return getRuleContext<g_arithParser::ExprContext>(0);
}


size_t g_arithParser::ExprContext::getRuleIndex() const {
  return g_arithParser::RuleExpr;
}


g_arithParser::ExprContext* g_arithParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 2, g_arithParser::RuleExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(18);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_arithParser::NUM: {
        enterOuterAlt(_localctx, 1);
        setState(11);
        match(g_arithParser::NUM);
        setState(12);
        exprp();
        break;
      }

      case g_arithParser::T__0: {
        enterOuterAlt(_localctx, 2);
        setState(13);
        match(g_arithParser::T__0);
        setState(14);
        expr();
        setState(15);
        match(g_arithParser::T__1);
        setState(16);
        exprp();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprpContext ------------------------------------------------------------------

g_arithParser::ExprpContext::ExprpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_arithParser::OpContext* g_arithParser::ExprpContext::op() {
  return getRuleContext<g_arithParser::OpContext>(0);
}

g_arithParser::ExprContext* g_arithParser::ExprpContext::expr() {
  return getRuleContext<g_arithParser::ExprContext>(0);
}

g_arithParser::ExprpContext* g_arithParser::ExprpContext::exprp() {
  return getRuleContext<g_arithParser::ExprpContext>(0);
}


size_t g_arithParser::ExprpContext::getRuleIndex() const {
  return g_arithParser::RuleExprp;
}


g_arithParser::ExprpContext* g_arithParser::exprp() {
  ExprpContext *_localctx = _tracker.createInstance<ExprpContext>(_ctx, getState());
  enterRule(_localctx, 4, g_arithParser::RuleExprp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(25);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(20);
      op();
      setState(21);
      expr();
      setState(22);
      exprp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);

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

//----------------- OpContext ------------------------------------------------------------------

g_arithParser::OpContext::OpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t g_arithParser::OpContext::getRuleIndex() const {
  return g_arithParser::RuleOp;
}


g_arithParser::OpContext* g_arithParser::op() {
  OpContext *_localctx = _tracker.createInstance<OpContext>(_ctx, getState());
  enterRule(_localctx, 6, g_arithParser::RuleOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << g_arithParser::T__2)
      | (1ULL << g_arithParser::T__3)
      | (1ULL << g_arithParser::T__4)
      | (1ULL << g_arithParser::T__5))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
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
std::vector<dfa::DFA> g_arithParser::_decisionToDFA;
atn::PredictionContextCache g_arithParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN g_arithParser::_atn;
std::vector<uint16_t> g_arithParser::_serializedATN;

std::vector<std::string> g_arithParser::_ruleNames = {
  "start", "expr", "exprp", "op"
};

std::vector<std::string> g_arithParser::_literalNames = {
  "", "'('", "')'", "'+'", "'*'", "'-'", "'/'"
};

std::vector<std::string> g_arithParser::_symbolicNames = {
  "", "", "", "", "", "", "", "NUM"
};

dfa::Vocabulary g_arithParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> g_arithParser::_tokenNames;

g_arithParser::Initializer::Initializer() {
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
    0x3, 0x9, 0x20, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x15, 
    0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x1c, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x2, 0x2, 0x6, 0x2, 0x4, 
    0x6, 0x8, 0x2, 0x3, 0x3, 0x2, 0x5, 0x8, 0x2, 0x1d, 0x2, 0xa, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x14, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb, 0x5, 0x4, 0x3, 0x2, 0xb, 0xc, 
    0x7, 0x2, 0x2, 0x3, 0xc, 0x3, 0x3, 0x2, 0x2, 0x2, 0xd, 0xe, 0x7, 0x9, 
    0x2, 0x2, 0xe, 0x15, 0x5, 0x6, 0x4, 0x2, 0xf, 0x10, 0x7, 0x3, 0x2, 0x2, 
    0x10, 0x11, 0x5, 0x4, 0x3, 0x2, 0x11, 0x12, 0x7, 0x4, 0x2, 0x2, 0x12, 
    0x13, 0x5, 0x6, 0x4, 0x2, 0x13, 0x15, 0x3, 0x2, 0x2, 0x2, 0x14, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0xf, 0x3, 0x2, 0x2, 0x2, 0x15, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x17, 0x5, 0x8, 0x5, 0x2, 0x17, 0x18, 0x5, 0x4, 0x3, 
    0x2, 0x18, 0x19, 0x5, 0x6, 0x4, 0x2, 0x19, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x16, 0x3, 0x2, 0x2, 0x2, 0x1b, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 
    0x9, 0x2, 0x2, 0x2, 0x1e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4, 0x14, 0x1b, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

g_arithParser::Initializer g_arithParser::_init;
