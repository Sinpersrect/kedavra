
// Generated from g_fol.g4 by ANTLR 4.7.2



#include "g_folParser.h"


using namespace antlrcpp;
using namespace antlr4;

g_folParser::g_folParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

g_folParser::~g_folParser() {
  delete _interpreter;
}

std::string g_folParser::getGrammarFileName() const {
  return "g_fol.g4";
}

const std::vector<std::string>& g_folParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& g_folParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

g_folParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_folParser::FormulaContext* g_folParser::StartContext::formula() {
  return getRuleContext<g_folParser::FormulaContext>(0);
}

tree::TerminalNode* g_folParser::StartContext::EOF() {
  return getToken(g_folParser::EOF, 0);
}


size_t g_folParser::StartContext::getRuleIndex() const {
  return g_folParser::RuleStart;
}


g_folParser::StartContext* g_folParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_folParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    formula(0);
    setState(19);
    match(g_folParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormulaContext ------------------------------------------------------------------

g_folParser::FormulaContext::FormulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_folParser::FormulaContext::NOT() {
  return getToken(g_folParser::NOT, 0);
}

std::vector<g_folParser::FormulaContext *> g_folParser::FormulaContext::formula() {
  return getRuleContexts<g_folParser::FormulaContext>();
}

g_folParser::FormulaContext* g_folParser::FormulaContext::formula(size_t i) {
  return getRuleContext<g_folParser::FormulaContext>(i);
}

std::vector<tree::TerminalNode *> g_folParser::FormulaContext::SPACE() {
  return getTokens(g_folParser::SPACE);
}

tree::TerminalNode* g_folParser::FormulaContext::SPACE(size_t i) {
  return getToken(g_folParser::SPACE, i);
}

g_folParser::Bin_connectiveContext* g_folParser::FormulaContext::bin_connective() {
  return getRuleContext<g_folParser::Bin_connectiveContext>(0);
}

tree::TerminalNode* g_folParser::FormulaContext::FORALL() {
  return getToken(g_folParser::FORALL, 0);
}

tree::TerminalNode* g_folParser::FormulaContext::LPAREN() {
  return getToken(g_folParser::LPAREN, 0);
}

g_folParser::VariableContext* g_folParser::FormulaContext::variable() {
  return getRuleContext<g_folParser::VariableContext>(0);
}

tree::TerminalNode* g_folParser::FormulaContext::RPAREN() {
  return getToken(g_folParser::RPAREN, 0);
}

tree::TerminalNode* g_folParser::FormulaContext::EXISTS() {
  return getToken(g_folParser::EXISTS, 0);
}

g_folParser::Pred_constantContext* g_folParser::FormulaContext::pred_constant() {
  return getRuleContext<g_folParser::Pred_constantContext>(0);
}

std::vector<g_folParser::TermContext *> g_folParser::FormulaContext::term() {
  return getRuleContexts<g_folParser::TermContext>();
}

g_folParser::TermContext* g_folParser::FormulaContext::term(size_t i) {
  return getRuleContext<g_folParser::TermContext>(i);
}

std::vector<g_folParser::SeparatorContext *> g_folParser::FormulaContext::separator() {
  return getRuleContexts<g_folParser::SeparatorContext>();
}

g_folParser::SeparatorContext* g_folParser::FormulaContext::separator(size_t i) {
  return getRuleContext<g_folParser::SeparatorContext>(i);
}

tree::TerminalNode* g_folParser::FormulaContext::EQUAL() {
  return getToken(g_folParser::EQUAL, 0);
}


size_t g_folParser::FormulaContext::getRuleIndex() const {
  return g_folParser::RuleFormula;
}



g_folParser::FormulaContext* g_folParser::formula() {
   return formula(0);
}

g_folParser::FormulaContext* g_folParser::formula(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  g_folParser::FormulaContext *_localctx = _tracker.createInstance<FormulaContext>(_ctx, parentState);
  g_folParser::FormulaContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, g_folParser::RuleFormula, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(64);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(22);
      match(g_folParser::NOT);
      setState(23);
      formula(0);
      setState(24);
      match(g_folParser::SPACE);
      setState(25);
      bin_connective();
      setState(26);
      match(g_folParser::SPACE);
      setState(27);
      formula(6);
      break;
    }

    case 2: {
      setState(29);
      match(g_folParser::NOT);
      setState(30);
      formula(5);
      break;
    }

    case 3: {
      setState(31);
      match(g_folParser::FORALL);
      setState(32);
      match(g_folParser::LPAREN);
      setState(33);
      variable();
      setState(34);
      match(g_folParser::RPAREN);
      setState(35);
      match(g_folParser::SPACE);
      setState(36);
      formula(4);
      break;
    }

    case 4: {
      setState(38);
      match(g_folParser::EXISTS);
      setState(39);
      match(g_folParser::LPAREN);
      setState(40);
      variable();
      setState(41);
      match(g_folParser::RPAREN);
      setState(42);
      match(g_folParser::SPACE);
      setState(43);
      formula(3);
      break;
    }

    case 5: {
      setState(45);
      pred_constant();
      setState(46);
      match(g_folParser::LPAREN);
      setState(47);
      term();
      setState(53);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == g_folParser::T__4) {
        setState(48);
        separator();
        setState(49);
        term();
        setState(55);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(56);
      match(g_folParser::RPAREN);
      break;
    }

    case 6: {
      setState(58);
      term();
      setState(59);
      match(g_folParser::SPACE);
      setState(60);
      match(g_folParser::EQUAL);
      setState(61);
      match(g_folParser::SPACE);
      setState(62);
      term();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(74);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<FormulaContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleFormula);
        setState(66);

        if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
        setState(67);
        match(g_folParser::SPACE);
        setState(68);
        bin_connective();
        setState(69);
        match(g_folParser::SPACE);
        setState(70);
        formula(8); 
      }
      setState(76);
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

//----------------- TermContext ------------------------------------------------------------------

g_folParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_folParser::Ind_constantContext* g_folParser::TermContext::ind_constant() {
  return getRuleContext<g_folParser::Ind_constantContext>(0);
}

g_folParser::VariableContext* g_folParser::TermContext::variable() {
  return getRuleContext<g_folParser::VariableContext>(0);
}

g_folParser::Func_constantContext* g_folParser::TermContext::func_constant() {
  return getRuleContext<g_folParser::Func_constantContext>(0);
}

tree::TerminalNode* g_folParser::TermContext::LPAREN() {
  return getToken(g_folParser::LPAREN, 0);
}

std::vector<g_folParser::TermContext *> g_folParser::TermContext::term() {
  return getRuleContexts<g_folParser::TermContext>();
}

g_folParser::TermContext* g_folParser::TermContext::term(size_t i) {
  return getRuleContext<g_folParser::TermContext>(i);
}

tree::TerminalNode* g_folParser::TermContext::RPAREN() {
  return getToken(g_folParser::RPAREN, 0);
}

std::vector<g_folParser::SeparatorContext *> g_folParser::TermContext::separator() {
  return getRuleContexts<g_folParser::SeparatorContext>();
}

g_folParser::SeparatorContext* g_folParser::TermContext::separator(size_t i) {
  return getRuleContext<g_folParser::SeparatorContext>(i);
}


size_t g_folParser::TermContext::getRuleIndex() const {
  return g_folParser::RuleTerm;
}


g_folParser::TermContext* g_folParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 4, g_folParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_folParser::T__2: {
        enterOuterAlt(_localctx, 1);
        setState(77);
        ind_constant();
        break;
      }

      case g_folParser::T__0: {
        enterOuterAlt(_localctx, 2);
        setState(78);
        variable();
        break;
      }

      case g_folParser::T__3: {
        enterOuterAlt(_localctx, 3);
        setState(79);
        func_constant();
        setState(80);
        match(g_folParser::LPAREN);
        setState(81);
        term();
        setState(87);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == g_folParser::T__4) {
          setState(82);
          separator();
          setState(83);
          term();
          setState(89);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(90);
        match(g_folParser::RPAREN);
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

//----------------- Bin_connectiveContext ------------------------------------------------------------------

g_folParser::Bin_connectiveContext::Bin_connectiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_folParser::Bin_connectiveContext::CONJ() {
  return getToken(g_folParser::CONJ, 0);
}

tree::TerminalNode* g_folParser::Bin_connectiveContext::DISJ() {
  return getToken(g_folParser::DISJ, 0);
}

tree::TerminalNode* g_folParser::Bin_connectiveContext::IMPL() {
  return getToken(g_folParser::IMPL, 0);
}

tree::TerminalNode* g_folParser::Bin_connectiveContext::BICOND() {
  return getToken(g_folParser::BICOND, 0);
}


size_t g_folParser::Bin_connectiveContext::getRuleIndex() const {
  return g_folParser::RuleBin_connective;
}


g_folParser::Bin_connectiveContext* g_folParser::bin_connective() {
  Bin_connectiveContext *_localctx = _tracker.createInstance<Bin_connectiveContext>(_ctx, getState());
  enterRule(_localctx, 6, g_folParser::RuleBin_connective);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << g_folParser::CONJ)
      | (1ULL << g_folParser::DISJ)
      | (1ULL << g_folParser::IMPL)
      | (1ULL << g_folParser::BICOND))) != 0))) {
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

//----------------- VariableContext ------------------------------------------------------------------

g_folParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> g_folParser::VariableContext::CHARACTER() {
  return getTokens(g_folParser::CHARACTER);
}

tree::TerminalNode* g_folParser::VariableContext::CHARACTER(size_t i) {
  return getToken(g_folParser::CHARACTER, i);
}


size_t g_folParser::VariableContext::getRuleIndex() const {
  return g_folParser::RuleVariable;
}


g_folParser::VariableContext* g_folParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 8, g_folParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(g_folParser::T__0);
    setState(98); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(97);
              match(g_folParser::CHARACTER);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(100); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pred_constantContext ------------------------------------------------------------------

g_folParser::Pred_constantContext::Pred_constantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> g_folParser::Pred_constantContext::CHARACTER() {
  return getTokens(g_folParser::CHARACTER);
}

tree::TerminalNode* g_folParser::Pred_constantContext::CHARACTER(size_t i) {
  return getToken(g_folParser::CHARACTER, i);
}


size_t g_folParser::Pred_constantContext::getRuleIndex() const {
  return g_folParser::RulePred_constant;
}


g_folParser::Pred_constantContext* g_folParser::pred_constant() {
  Pred_constantContext *_localctx = _tracker.createInstance<Pred_constantContext>(_ctx, getState());
  enterRule(_localctx, 10, g_folParser::RulePred_constant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    match(g_folParser::T__1);
    setState(104); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(103);
      match(g_folParser::CHARACTER);
      setState(106); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == g_folParser::CHARACTER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ind_constantContext ------------------------------------------------------------------

g_folParser::Ind_constantContext::Ind_constantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> g_folParser::Ind_constantContext::CHARACTER() {
  return getTokens(g_folParser::CHARACTER);
}

tree::TerminalNode* g_folParser::Ind_constantContext::CHARACTER(size_t i) {
  return getToken(g_folParser::CHARACTER, i);
}


size_t g_folParser::Ind_constantContext::getRuleIndex() const {
  return g_folParser::RuleInd_constant;
}


g_folParser::Ind_constantContext* g_folParser::ind_constant() {
  Ind_constantContext *_localctx = _tracker.createInstance<Ind_constantContext>(_ctx, getState());
  enterRule(_localctx, 12, g_folParser::RuleInd_constant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(g_folParser::T__2);
    setState(110); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(109);
              match(g_folParser::CHARACTER);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(112); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_constantContext ------------------------------------------------------------------

g_folParser::Func_constantContext::Func_constantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> g_folParser::Func_constantContext::CHARACTER() {
  return getTokens(g_folParser::CHARACTER);
}

tree::TerminalNode* g_folParser::Func_constantContext::CHARACTER(size_t i) {
  return getToken(g_folParser::CHARACTER, i);
}


size_t g_folParser::Func_constantContext::getRuleIndex() const {
  return g_folParser::RuleFunc_constant;
}


g_folParser::Func_constantContext* g_folParser::func_constant() {
  Func_constantContext *_localctx = _tracker.createInstance<Func_constantContext>(_ctx, getState());
  enterRule(_localctx, 14, g_folParser::RuleFunc_constant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(g_folParser::T__3);
    setState(116); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(115);
      match(g_folParser::CHARACTER);
      setState(118); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == g_folParser::CHARACTER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SeparatorContext ------------------------------------------------------------------

g_folParser::SeparatorContext::SeparatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t g_folParser::SeparatorContext::getRuleIndex() const {
  return g_folParser::RuleSeparator;
}


g_folParser::SeparatorContext* g_folParser::separator() {
  SeparatorContext *_localctx = _tracker.createInstance<SeparatorContext>(_ctx, getState());
  enterRule(_localctx, 16, g_folParser::RuleSeparator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(g_folParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool g_folParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return formulaSempred(dynamic_cast<FormulaContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool g_folParser::formulaSempred(FormulaContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> g_folParser::_decisionToDFA;
atn::PredictionContextCache g_folParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN g_folParser::_atn;
std::vector<uint16_t> g_folParser::_serializedATN;

std::vector<std::string> g_folParser::_ruleNames = {
  "start", "formula", "term", "bin_connective", "variable", "pred_constant", 
  "ind_constant", "func_constant", "separator"
};

std::vector<std::string> g_folParser::_literalNames = {
  "", "'?'", "'_'", "'#'", "'.'", "', '", "'('", "')'", "'='", "'!'", "'Forall'", 
  "'Exists'", "", "'\\/'", "'^'", "'->'", "'<->'", "' '"
};

std::vector<std::string> g_folParser::_symbolicNames = {
  "", "", "", "", "", "", "LPAREN", "RPAREN", "EQUAL", "NOT", "FORALL", 
  "EXISTS", "CHARACTER", "CONJ", "DISJ", "IMPL", "BICOND", "SPACE"
};

dfa::Vocabulary g_folParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> g_folParser::_tokenNames;

g_folParser::Initializer::Initializer() {
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
    0x3, 0x13, 0x7d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x36, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x39, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x43, 0xa, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x4b, 0xa, 
    0x3, 0xc, 0x3, 0xe, 0x3, 0x4e, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x58, 0xa, 
    0x4, 0xc, 0x4, 0xe, 0x4, 0x5b, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x5f, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x65, 
    0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x66, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x6b, 
    0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0x6c, 0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 0x71, 
    0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x72, 0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0x77, 
    0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 0x78, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x2, 
    0x3, 0x4, 0xb, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x2, 0x3, 
    0x3, 0x2, 0xf, 0x12, 0x2, 0x81, 0x2, 0x14, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0x6, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x62, 0x3, 0x2, 0x2, 0x2, 0xc, 0x68, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x5, 0x4, 0x3, 0x2, 
    0x15, 0x16, 0x7, 0x2, 0x2, 0x3, 0x16, 0x3, 0x3, 0x2, 0x2, 0x2, 0x17, 
    0x18, 0x8, 0x3, 0x1, 0x2, 0x18, 0x19, 0x7, 0xb, 0x2, 0x2, 0x19, 0x1a, 
    0x5, 0x4, 0x3, 0x2, 0x1a, 0x1b, 0x7, 0x13, 0x2, 0x2, 0x1b, 0x1c, 0x5, 
    0x8, 0x5, 0x2, 0x1c, 0x1d, 0x7, 0x13, 0x2, 0x2, 0x1d, 0x1e, 0x5, 0x4, 
    0x3, 0x8, 0x1e, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x7, 0xb, 0x2, 
    0x2, 0x20, 0x43, 0x5, 0x4, 0x3, 0x7, 0x21, 0x22, 0x7, 0xc, 0x2, 0x2, 
    0x22, 0x23, 0x7, 0x8, 0x2, 0x2, 0x23, 0x24, 0x5, 0xa, 0x6, 0x2, 0x24, 
    0x25, 0x7, 0x9, 0x2, 0x2, 0x25, 0x26, 0x7, 0x13, 0x2, 0x2, 0x26, 0x27, 
    0x5, 0x4, 0x3, 0x6, 0x27, 0x43, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 
    0xd, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x8, 0x2, 0x2, 0x2a, 0x2b, 0x5, 0xa, 
    0x6, 0x2, 0x2b, 0x2c, 0x7, 0x9, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x13, 0x2, 
    0x2, 0x2d, 0x2e, 0x5, 0x4, 0x3, 0x5, 0x2e, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x2f, 0x30, 0x5, 0xc, 0x7, 0x2, 0x30, 0x31, 0x7, 0x8, 0x2, 0x2, 0x31, 
    0x37, 0x5, 0x6, 0x4, 0x2, 0x32, 0x33, 0x5, 0x12, 0xa, 0x2, 0x33, 0x34, 
    0x5, 0x6, 0x4, 0x2, 0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x32, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3a, 0x3, 0x2, 0x2, 
    0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x9, 0x2, 0x2, 
    0x3b, 0x43, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0x6, 0x4, 0x2, 0x3d, 
    0x3e, 0x7, 0x13, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0xa, 0x2, 0x2, 0x3f, 0x40, 
    0x7, 0x13, 0x2, 0x2, 0x40, 0x41, 0x5, 0x6, 0x4, 0x2, 0x41, 0x43, 0x3, 
    0x2, 0x2, 0x2, 0x42, 0x17, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x21, 0x3, 0x2, 0x2, 0x2, 0x42, 0x28, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0xc, 0x9, 0x2, 0x2, 0x45, 
    0x46, 0x7, 0x13, 0x2, 0x2, 0x46, 0x47, 0x5, 0x8, 0x5, 0x2, 0x47, 0x48, 
    0x7, 0x13, 0x2, 0x2, 0x48, 0x49, 0x5, 0x4, 0x3, 0xa, 0x49, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x44, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4e, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x5f, 0x5, 0xe, 0x8, 0x2, 0x50, 0x5f, 0x5, 0xa, 0x6, 0x2, 0x51, 
    0x52, 0x5, 0x10, 0x9, 0x2, 0x52, 0x53, 0x7, 0x8, 0x2, 0x2, 0x53, 0x59, 
    0x5, 0x6, 0x4, 0x2, 0x54, 0x55, 0x5, 0x12, 0xa, 0x2, 0x55, 0x56, 0x5, 
    0x6, 0x4, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 0x2, 0x57, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x9, 0x2, 0x2, 0x5d, 
    0x5f, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x61, 0x9, 0x2, 0x2, 0x2, 0x61, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x64, 0x7, 0x3, 0x2, 0x2, 0x63, 0x65, 0x7, 0xe, 0x2, 
    0x2, 0x64, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6a, 0x7, 0x4, 0x2, 0x2, 0x69, 0x6b, 
    0x7, 0xe, 0x2, 0x2, 0x6a, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x6d, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x70, 0x7, 0x5, 0x2, 
    0x2, 0x6f, 0x71, 0x7, 0xe, 0x2, 0x2, 0x70, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0xf, 0x3, 0x2, 0x2, 0x2, 0x74, 0x76, 
    0x7, 0x6, 0x2, 0x2, 0x75, 0x77, 0x7, 0xe, 0x2, 0x2, 0x76, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 0x78, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x7b, 0x7, 0x7, 0x2, 0x2, 0x7b, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0xb, 0x37, 0x42, 0x4c, 0x59, 0x5e, 0x66, 0x6c, 0x72, 0x78, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

g_folParser::Initializer g_folParser::_init;
