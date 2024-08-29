
// Generated from g_mathexpr.g4 by ANTLR 4.7.2



#include "g_mathexprParser.h"


using namespace antlrcpp;
using namespace antlr4;

g_mathexprParser::g_mathexprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

g_mathexprParser::~g_mathexprParser() {
  delete _interpreter;
}

std::string g_mathexprParser::getGrammarFileName() const {
  return "g_mathexpr.g4";
}

const std::vector<std::string>& g_mathexprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& g_mathexprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

g_mathexprParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_mathexprParser::ExprContext* g_mathexprParser::StartContext::expr() {
  return getRuleContext<g_mathexprParser::ExprContext>(0);
}

tree::TerminalNode* g_mathexprParser::StartContext::EOF() {
  return getToken(g_mathexprParser::EOF, 0);
}


size_t g_mathexprParser::StartContext::getRuleIndex() const {
  return g_mathexprParser::RuleStart;
}


g_mathexprParser::StartContext* g_mathexprParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_mathexprParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(12);
    expr();
    setState(13);
    match(g_mathexprParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

g_mathexprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_mathexprParser::FunccallContext* g_mathexprParser::ExprContext::funccall() {
  return getRuleContext<g_mathexprParser::FunccallContext>(0);
}

g_mathexprParser::ExprpContext* g_mathexprParser::ExprContext::exprp() {
  return getRuleContext<g_mathexprParser::ExprpContext>(0);
}

tree::TerminalNode* g_mathexprParser::ExprContext::VAR() {
  return getToken(g_mathexprParser::VAR, 0);
}

tree::TerminalNode* g_mathexprParser::ExprContext::FLOAT() {
  return getToken(g_mathexprParser::FLOAT, 0);
}

tree::TerminalNode* g_mathexprParser::ExprContext::INTEGER() {
  return getToken(g_mathexprParser::INTEGER, 0);
}

tree::TerminalNode* g_mathexprParser::ExprContext::CONSTANT() {
  return getToken(g_mathexprParser::CONSTANT, 0);
}

g_mathexprParser::ExprContext* g_mathexprParser::ExprContext::expr() {
  return getRuleContext<g_mathexprParser::ExprContext>(0);
}


size_t g_mathexprParser::ExprContext::getRuleIndex() const {
  return g_mathexprParser::RuleExpr;
}


g_mathexprParser::ExprContext* g_mathexprParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 2, g_mathexprParser::RuleExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(31);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_mathexprParser::FUNC: {
        enterOuterAlt(_localctx, 1);
        setState(15);
        funccall();
        setState(16);
        exprp();
        break;
      }

      case g_mathexprParser::VAR: {
        enterOuterAlt(_localctx, 2);
        setState(18);
        match(g_mathexprParser::VAR);
        setState(19);
        exprp();
        break;
      }

      case g_mathexprParser::FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(20);
        match(g_mathexprParser::FLOAT);
        setState(21);
        exprp();
        break;
      }

      case g_mathexprParser::INTEGER: {
        enterOuterAlt(_localctx, 4);
        setState(22);
        match(g_mathexprParser::INTEGER);
        setState(23);
        exprp();
        break;
      }

      case g_mathexprParser::CONSTANT: {
        enterOuterAlt(_localctx, 5);
        setState(24);
        match(g_mathexprParser::CONSTANT);
        setState(25);
        exprp();
        break;
      }

      case g_mathexprParser::T__0: {
        enterOuterAlt(_localctx, 6);
        setState(26);
        match(g_mathexprParser::T__0);
        setState(27);
        expr();
        setState(28);
        match(g_mathexprParser::T__1);
        setState(29);
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

g_mathexprParser::ExprpContext::ExprpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> g_mathexprParser::ExprpContext::SPACE() {
  return getTokens(g_mathexprParser::SPACE);
}

tree::TerminalNode* g_mathexprParser::ExprpContext::SPACE(size_t i) {
  return getToken(g_mathexprParser::SPACE, i);
}

g_mathexprParser::OpContext* g_mathexprParser::ExprpContext::op() {
  return getRuleContext<g_mathexprParser::OpContext>(0);
}

g_mathexprParser::ExprContext* g_mathexprParser::ExprpContext::expr() {
  return getRuleContext<g_mathexprParser::ExprContext>(0);
}

g_mathexprParser::ExprpContext* g_mathexprParser::ExprpContext::exprp() {
  return getRuleContext<g_mathexprParser::ExprpContext>(0);
}


size_t g_mathexprParser::ExprpContext::getRuleIndex() const {
  return g_mathexprParser::RuleExprp;
}


g_mathexprParser::ExprpContext* g_mathexprParser::exprp() {
  ExprpContext *_localctx = _tracker.createInstance<ExprpContext>(_ctx, getState());
  enterRule(_localctx, 4, g_mathexprParser::RuleExprp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(40);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(33);
      match(g_mathexprParser::SPACE);
      setState(34);
      op();
      setState(35);
      match(g_mathexprParser::SPACE);
      setState(36);
      expr();
      setState(37);
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

//----------------- FunccallContext ------------------------------------------------------------------

g_mathexprParser::FunccallContext::FunccallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_mathexprParser::FunccallContext::FUNC() {
  return getToken(g_mathexprParser::FUNC, 0);
}

g_mathexprParser::ArglistContext* g_mathexprParser::FunccallContext::arglist() {
  return getRuleContext<g_mathexprParser::ArglistContext>(0);
}


size_t g_mathexprParser::FunccallContext::getRuleIndex() const {
  return g_mathexprParser::RuleFunccall;
}


g_mathexprParser::FunccallContext* g_mathexprParser::funccall() {
  FunccallContext *_localctx = _tracker.createInstance<FunccallContext>(_ctx, getState());
  enterRule(_localctx, 6, g_mathexprParser::RuleFunccall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    match(g_mathexprParser::FUNC);
    setState(43);
    match(g_mathexprParser::T__0);
    setState(44);
    arglist();
    setState(45);
    match(g_mathexprParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArglistContext ------------------------------------------------------------------

g_mathexprParser::ArglistContext::ArglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_mathexprParser::ExprContext* g_mathexprParser::ArglistContext::expr() {
  return getRuleContext<g_mathexprParser::ExprContext>(0);
}

tree::TerminalNode* g_mathexprParser::ArglistContext::SPACE() {
  return getToken(g_mathexprParser::SPACE, 0);
}

g_mathexprParser::ArglistContext* g_mathexprParser::ArglistContext::arglist() {
  return getRuleContext<g_mathexprParser::ArglistContext>(0);
}


size_t g_mathexprParser::ArglistContext::getRuleIndex() const {
  return g_mathexprParser::RuleArglist;
}


g_mathexprParser::ArglistContext* g_mathexprParser::arglist() {
  ArglistContext *_localctx = _tracker.createInstance<ArglistContext>(_ctx, getState());
  enterRule(_localctx, 8, g_mathexprParser::RuleArglist);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(53);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(47);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(48);
      expr();
      setState(49);
      match(g_mathexprParser::T__2);
      setState(50);
      match(g_mathexprParser::SPACE);
      setState(51);
      arglist();
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

g_mathexprParser::OpContext::OpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t g_mathexprParser::OpContext::getRuleIndex() const {
  return g_mathexprParser::RuleOp;
}


g_mathexprParser::OpContext* g_mathexprParser::op() {
  OpContext *_localctx = _tracker.createInstance<OpContext>(_ctx, getState());
  enterRule(_localctx, 10, g_mathexprParser::RuleOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << g_mathexprParser::T__3)
      | (1ULL << g_mathexprParser::T__4)
      | (1ULL << g_mathexprParser::T__5)
      | (1ULL << g_mathexprParser::T__6))) != 0))) {
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
std::vector<dfa::DFA> g_mathexprParser::_decisionToDFA;
atn::PredictionContextCache g_mathexprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN g_mathexprParser::_atn;
std::vector<uint16_t> g_mathexprParser::_serializedATN;

std::vector<std::string> g_mathexprParser::_ruleNames = {
  "start", "expr", "exprp", "funccall", "arglist", "op"
};

std::vector<std::string> g_mathexprParser::_literalNames = {
  "", "'('", "')'", "','", "'+'", "'-'", "'*'", "'/'", "", "", "", "", "", 
  "' '"
};

std::vector<std::string> g_mathexprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "FUNC", "CONSTANT", "VAR", "FLOAT", "INTEGER", 
  "SPACE"
};

dfa::Vocabulary g_mathexprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> g_mathexprParser::_tokenNames;

g_mathexprParser::Initializer::Initializer() {
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
    0x3, 0xf, 0x3c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x22, 0xa, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x2b, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x38, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x2, 0x2, 0x8, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0x2, 0x3, 0x3, 0x2, 0x6, 0x9, 0x2, 0x3c, 0x2, 
    0xe, 0x3, 0x2, 0x2, 0x2, 0x4, 0x21, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2a, 0x3, 
    0x2, 0x2, 0x2, 0x8, 0x2c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0xc, 0x39, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf, 0x5, 0x4, 0x3, 0x2, 0xf, 
    0x10, 0x7, 0x2, 0x2, 0x3, 0x10, 0x3, 0x3, 0x2, 0x2, 0x2, 0x11, 0x12, 
    0x5, 0x8, 0x5, 0x2, 0x12, 0x13, 0x5, 0x6, 0x4, 0x2, 0x13, 0x22, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x15, 0x7, 0xc, 0x2, 0x2, 0x15, 0x22, 0x5, 0x6, 
    0x4, 0x2, 0x16, 0x17, 0x7, 0xd, 0x2, 0x2, 0x17, 0x22, 0x5, 0x6, 0x4, 
    0x2, 0x18, 0x19, 0x7, 0xe, 0x2, 0x2, 0x19, 0x22, 0x5, 0x6, 0x4, 0x2, 
    0x1a, 0x1b, 0x7, 0xb, 0x2, 0x2, 0x1b, 0x22, 0x5, 0x6, 0x4, 0x2, 0x1c, 
    0x1d, 0x7, 0x3, 0x2, 0x2, 0x1d, 0x1e, 0x5, 0x4, 0x3, 0x2, 0x1e, 0x1f, 
    0x7, 0x4, 0x2, 0x2, 0x1f, 0x20, 0x5, 0x6, 0x4, 0x2, 0x20, 0x22, 0x3, 
    0x2, 0x2, 0x2, 0x21, 0x11, 0x3, 0x2, 0x2, 0x2, 0x21, 0x14, 0x3, 0x2, 
    0x2, 0x2, 0x21, 0x16, 0x3, 0x2, 0x2, 0x2, 0x21, 0x18, 0x3, 0x2, 0x2, 
    0x2, 0x21, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x5, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x7, 0xf, 0x2, 0x2, 0x24, 
    0x25, 0x5, 0xc, 0x7, 0x2, 0x25, 0x26, 0x7, 0xf, 0x2, 0x2, 0x26, 0x27, 
    0x5, 0x4, 0x3, 0x2, 0x27, 0x28, 0x5, 0x6, 0x4, 0x2, 0x28, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x29, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x2d, 0x7, 0xa, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x3, 0x2, 0x2, 
    0x2e, 0x2f, 0x5, 0xa, 0x6, 0x2, 0x2f, 0x30, 0x7, 0x4, 0x2, 0x2, 0x30, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x31, 0x38, 0x5, 0x4, 0x3, 0x2, 0x32, 0x33, 
    0x5, 0x4, 0x3, 0x2, 0x33, 0x34, 0x7, 0x5, 0x2, 0x2, 0x34, 0x35, 0x7, 
    0xf, 0x2, 0x2, 0x35, 0x36, 0x5, 0xa, 0x6, 0x2, 0x36, 0x38, 0x3, 0x2, 
    0x2, 0x2, 0x37, 0x31, 0x3, 0x2, 0x2, 0x2, 0x37, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0xb, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x9, 0x2, 0x2, 0x2, 
    0x3a, 0xd, 0x3, 0x2, 0x2, 0x2, 0x5, 0x21, 0x2a, 0x37, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

g_mathexprParser::Initializer g_mathexprParser::_init;
