
// Generated from g_json.g4 by ANTLR 4.7.2



#include "g_jsonParser.h"


using namespace antlrcpp;
using namespace antlr4;

g_jsonParser::g_jsonParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

g_jsonParser::~g_jsonParser() {
  delete _interpreter;
}

std::string g_jsonParser::getGrammarFileName() const {
  return "g_json.g4";
}

const std::vector<std::string>& g_jsonParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& g_jsonParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

g_jsonParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ValueContext* g_jsonParser::StartContext::value() {
  return getRuleContext<g_jsonParser::ValueContext>(0);
}

tree::TerminalNode* g_jsonParser::StartContext::EOF() {
  return getToken(g_jsonParser::EOF, 0);
}


size_t g_jsonParser::StartContext::getRuleIndex() const {
  return g_jsonParser::RuleStart;
}


g_jsonParser::StartContext* g_jsonParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_jsonParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    value();
    setState(15);
    match(g_jsonParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

g_jsonParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ObjectContext* g_jsonParser::ValueContext::object() {
  return getRuleContext<g_jsonParser::ObjectContext>(0);
}

g_jsonParser::ArrayContext* g_jsonParser::ValueContext::array() {
  return getRuleContext<g_jsonParser::ArrayContext>(0);
}

tree::TerminalNode* g_jsonParser::ValueContext::STRING() {
  return getToken(g_jsonParser::STRING, 0);
}

tree::TerminalNode* g_jsonParser::ValueContext::NUMBER() {
  return getToken(g_jsonParser::NUMBER, 0);
}


size_t g_jsonParser::ValueContext::getRuleIndex() const {
  return g_jsonParser::RuleValue;
}


g_jsonParser::ValueContext* g_jsonParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 2, g_jsonParser::RuleValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(24);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_jsonParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(17);
        object();
        break;
      }

      case g_jsonParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(18);
        array();
        break;
      }

      case g_jsonParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(19);
        match(g_jsonParser::STRING);
        break;
      }

      case g_jsonParser::NUMBER: {
        enterOuterAlt(_localctx, 4);
        setState(20);
        match(g_jsonParser::NUMBER);
        break;
      }

      case g_jsonParser::T__0: {
        enterOuterAlt(_localctx, 5);
        setState(21);
        match(g_jsonParser::T__0);
        break;
      }

      case g_jsonParser::T__1: {
        enterOuterAlt(_localctx, 6);
        setState(22);
        match(g_jsonParser::T__1);
        break;
      }

      case g_jsonParser::T__2: {
        enterOuterAlt(_localctx, 7);
        setState(23);
        match(g_jsonParser::T__2);
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

//----------------- ArrayContext ------------------------------------------------------------------

g_jsonParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ListContext* g_jsonParser::ArrayContext::list() {
  return getRuleContext<g_jsonParser::ListContext>(0);
}


size_t g_jsonParser::ArrayContext::getRuleIndex() const {
  return g_jsonParser::RuleArray;
}


g_jsonParser::ArrayContext* g_jsonParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 4, g_jsonParser::RuleArray);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(32);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(26);
      match(g_jsonParser::T__3);
      setState(27);
      match(g_jsonParser::T__4);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(28);
      match(g_jsonParser::T__3);
      setState(29);
      list(0);
      setState(30);
      match(g_jsonParser::T__4);
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

g_jsonParser::ListContext::ListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ValueContext* g_jsonParser::ListContext::value() {
  return getRuleContext<g_jsonParser::ValueContext>(0);
}

g_jsonParser::ListContext* g_jsonParser::ListContext::list() {
  return getRuleContext<g_jsonParser::ListContext>(0);
}


size_t g_jsonParser::ListContext::getRuleIndex() const {
  return g_jsonParser::RuleList;
}



g_jsonParser::ListContext* g_jsonParser::list() {
   return list(0);
}

g_jsonParser::ListContext* g_jsonParser::list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  g_jsonParser::ListContext *_localctx = _tracker.createInstance<ListContext>(_ctx, parentState);
  g_jsonParser::ListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, g_jsonParser::RuleList, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(35);
    value();
    _ctx->stop = _input->LT(-1);
    setState(42);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleList);
        setState(37);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(38);
        match(g_jsonParser::T__5);
        setState(39);
        value(); 
      }
      setState(44);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

g_jsonParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ObjlistContext* g_jsonParser::ObjectContext::objlist() {
  return getRuleContext<g_jsonParser::ObjlistContext>(0);
}


size_t g_jsonParser::ObjectContext::getRuleIndex() const {
  return g_jsonParser::RuleObject;
}


g_jsonParser::ObjectContext* g_jsonParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 8, g_jsonParser::RuleObject);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(51);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(45);
      match(g_jsonParser::T__6);
      setState(46);
      match(g_jsonParser::T__7);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(47);
      match(g_jsonParser::T__6);
      setState(48);
      objlist(0);
      setState(49);
      match(g_jsonParser::T__7);
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

//----------------- ObjtupleContext ------------------------------------------------------------------

g_jsonParser::ObjtupleContext::ObjtupleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_jsonParser::ObjtupleContext::STRING() {
  return getToken(g_jsonParser::STRING, 0);
}

g_jsonParser::ValueContext* g_jsonParser::ObjtupleContext::value() {
  return getRuleContext<g_jsonParser::ValueContext>(0);
}


size_t g_jsonParser::ObjtupleContext::getRuleIndex() const {
  return g_jsonParser::RuleObjtuple;
}


g_jsonParser::ObjtupleContext* g_jsonParser::objtuple() {
  ObjtupleContext *_localctx = _tracker.createInstance<ObjtupleContext>(_ctx, getState());
  enterRule(_localctx, 10, g_jsonParser::RuleObjtuple);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(g_jsonParser::STRING);
    setState(54);
    match(g_jsonParser::T__8);
    setState(55);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjlistContext ------------------------------------------------------------------

g_jsonParser::ObjlistContext::ObjlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_jsonParser::ObjtupleContext* g_jsonParser::ObjlistContext::objtuple() {
  return getRuleContext<g_jsonParser::ObjtupleContext>(0);
}

g_jsonParser::ObjlistContext* g_jsonParser::ObjlistContext::objlist() {
  return getRuleContext<g_jsonParser::ObjlistContext>(0);
}


size_t g_jsonParser::ObjlistContext::getRuleIndex() const {
  return g_jsonParser::RuleObjlist;
}



g_jsonParser::ObjlistContext* g_jsonParser::objlist() {
   return objlist(0);
}

g_jsonParser::ObjlistContext* g_jsonParser::objlist(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  g_jsonParser::ObjlistContext *_localctx = _tracker.createInstance<ObjlistContext>(_ctx, parentState);
  g_jsonParser::ObjlistContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, g_jsonParser::RuleObjlist, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(58);
    objtuple();
    _ctx->stop = _input->LT(-1);
    setState(65);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ObjlistContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleObjlist);
        setState(60);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(61);
        match(g_jsonParser::T__5);
        setState(62);
        objtuple(); 
      }
      setState(67);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool g_jsonParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return listSempred(dynamic_cast<ListContext *>(context), predicateIndex);
    case 6: return objlistSempred(dynamic_cast<ObjlistContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool g_jsonParser::listSempred(ListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool g_jsonParser::objlistSempred(ObjlistContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> g_jsonParser::_decisionToDFA;
atn::PredictionContextCache g_jsonParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN g_jsonParser::_atn;
std::vector<uint16_t> g_jsonParser::_serializedATN;

std::vector<std::string> g_jsonParser::_ruleNames = {
  "start", "value", "array", "list", "object", "objtuple", "objlist"
};

std::vector<std::string> g_jsonParser::_literalNames = {
  "", "'true'", "'false'", "'null'", "'['", "']'", "','", "'{'", "'}'", 
  "':'", "", "", "'\u0022'"
};

std::vector<std::string> g_jsonParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "NUMBER", "STRING", "QUOTE"
};

dfa::Vocabulary g_jsonParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> g_jsonParser::_tokenNames;

g_jsonParser::Initializer::Initializer() {
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
    0x3, 0xe, 0x47, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x1b, 0xa, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x23, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x7, 0x5, 0x2b, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x2e, 0xb, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x36, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x42, 0xa, 0x8, 0xc, 
    0x8, 0xe, 0x8, 0x45, 0xb, 0x8, 0x3, 0x8, 0x2, 0x4, 0x8, 0xe, 0x9, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x2, 0x2, 0x2, 0x49, 0x2, 0x10, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x22, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x24, 0x3, 0x2, 0x2, 0x2, 0xa, 0x35, 0x3, 0x2, 0x2, 0x2, 0xc, 0x37, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x5, 
    0x4, 0x3, 0x2, 0x11, 0x12, 0x7, 0x2, 0x2, 0x3, 0x12, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x13, 0x1b, 0x5, 0xa, 0x6, 0x2, 0x14, 0x1b, 0x5, 0x6, 0x4, 
    0x2, 0x15, 0x1b, 0x7, 0xd, 0x2, 0x2, 0x16, 0x1b, 0x7, 0xc, 0x2, 0x2, 
    0x17, 0x1b, 0x7, 0x3, 0x2, 0x2, 0x18, 0x1b, 0x7, 0x4, 0x2, 0x2, 0x19, 
    0x1b, 0x7, 0x5, 0x2, 0x2, 0x1a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x14, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x15, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x16, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x17, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x18, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x1d, 0x7, 0x6, 0x2, 0x2, 0x1d, 0x23, 0x7, 0x7, 0x2, 0x2, 
    0x1e, 0x1f, 0x7, 0x6, 0x2, 0x2, 0x1f, 0x20, 0x5, 0x8, 0x5, 0x2, 0x20, 
    0x21, 0x7, 0x7, 0x2, 0x2, 0x21, 0x23, 0x3, 0x2, 0x2, 0x2, 0x22, 0x1c, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x23, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x25, 0x8, 0x5, 0x1, 0x2, 0x25, 0x26, 0x5, 0x4, 
    0x3, 0x2, 0x26, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0xc, 0x3, 0x2, 
    0x2, 0x28, 0x29, 0x7, 0x8, 0x2, 0x2, 0x29, 0x2b, 0x5, 0x4, 0x3, 0x2, 
    0x2a, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 
    0x9, 0x2, 0x2, 0x30, 0x36, 0x7, 0xa, 0x2, 0x2, 0x31, 0x32, 0x7, 0x9, 
    0x2, 0x2, 0x32, 0x33, 0x5, 0xe, 0x8, 0x2, 0x33, 0x34, 0x7, 0xa, 0x2, 
    0x2, 0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x31, 0x3, 0x2, 0x2, 0x2, 0x36, 0xb, 0x3, 0x2, 0x2, 0x2, 0x37, 
    0x38, 0x7, 0xd, 0x2, 0x2, 0x38, 0x39, 0x7, 0xb, 0x2, 0x2, 0x39, 0x3a, 
    0x5, 0x4, 0x3, 0x2, 0x3a, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x8, 
    0x8, 0x1, 0x2, 0x3c, 0x3d, 0x5, 0xc, 0x7, 0x2, 0x3d, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x3f, 0xc, 0x3, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x8, 0x2, 
    0x2, 0x40, 0x42, 0x5, 0xc, 0x7, 0x2, 0x41, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x45, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0xf, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x7, 0x1a, 0x22, 0x2c, 0x35, 0x43, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

g_jsonParser::Initializer g_jsonParser::_init;
