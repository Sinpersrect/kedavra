
// Generated from g_xml.g4 by ANTLR 4.7.2



#include "g_xmlParser.h"


using namespace antlrcpp;
using namespace antlr4;

g_xmlParser::g_xmlParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

g_xmlParser::~g_xmlParser() {
  delete _interpreter;
}

std::string g_xmlParser::getGrammarFileName() const {
  return "g_xml.g4";
}

const std::vector<std::string>& g_xmlParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& g_xmlParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

g_xmlParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_xmlParser::XmlContext* g_xmlParser::StartContext::xml() {
  return getRuleContext<g_xmlParser::XmlContext>(0);
}

tree::TerminalNode* g_xmlParser::StartContext::EOF() {
  return getToken(g_xmlParser::EOF, 0);
}


size_t g_xmlParser::StartContext::getRuleIndex() const {
  return g_xmlParser::RuleStart;
}


g_xmlParser::StartContext* g_xmlParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_xmlParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    xml();
    setState(15);
    match(g_xmlParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- XmlContext ------------------------------------------------------------------

g_xmlParser::XmlContext::XmlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_xmlParser::XmlContext::ASTART() {
  return getToken(g_xmlParser::ASTART, 0);
}

g_xmlParser::BodyContext* g_xmlParser::XmlContext::body() {
  return getRuleContext<g_xmlParser::BodyContext>(0);
}

tree::TerminalNode* g_xmlParser::XmlContext::AEND() {
  return getToken(g_xmlParser::AEND, 0);
}

g_xmlParser::AttrlistContext* g_xmlParser::XmlContext::attrlist() {
  return getRuleContext<g_xmlParser::AttrlistContext>(0);
}

tree::TerminalNode* g_xmlParser::XmlContext::BSTART() {
  return getToken(g_xmlParser::BSTART, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::BEND() {
  return getToken(g_xmlParser::BEND, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::CSTART() {
  return getToken(g_xmlParser::CSTART, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::CEND() {
  return getToken(g_xmlParser::CEND, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::DSTART() {
  return getToken(g_xmlParser::DSTART, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::DEND() {
  return getToken(g_xmlParser::DEND, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::ESTART() {
  return getToken(g_xmlParser::ESTART, 0);
}

tree::TerminalNode* g_xmlParser::XmlContext::EEND() {
  return getToken(g_xmlParser::EEND, 0);
}


size_t g_xmlParser::XmlContext::getRuleIndex() const {
  return g_xmlParser::RuleXml;
}


g_xmlParser::XmlContext* g_xmlParser::xml() {
  XmlContext *_localctx = _tracker.createInstance<XmlContext>(_ctx, getState());
  enterRule(_localctx, 2, g_xmlParser::RuleXml);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(72);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_xmlParser::ASTART: {
        enterOuterAlt(_localctx, 1);
        setState(17);
        match(g_xmlParser::ASTART);
        setState(26);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case g_xmlParser::T__0:
          case g_xmlParser::T__3: {
            setState(19);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == g_xmlParser::T__3) {
              setState(18);
              attrlist();
            }
            setState(21);
            match(g_xmlParser::T__0);
            setState(22);
            body();
            setState(23);
            match(g_xmlParser::AEND);
            break;
          }

          case g_xmlParser::T__1: {
            setState(25);
            match(g_xmlParser::T__1);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case g_xmlParser::BSTART: {
        enterOuterAlt(_localctx, 2);
        setState(28);
        match(g_xmlParser::BSTART);
        setState(37);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case g_xmlParser::T__0:
          case g_xmlParser::T__3: {
            setState(30);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == g_xmlParser::T__3) {
              setState(29);
              attrlist();
            }
            setState(32);
            match(g_xmlParser::T__0);
            setState(33);
            body();
            setState(34);
            match(g_xmlParser::BEND);
            break;
          }

          case g_xmlParser::T__1: {
            setState(36);
            match(g_xmlParser::T__1);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case g_xmlParser::CSTART: {
        enterOuterAlt(_localctx, 3);
        setState(39);
        match(g_xmlParser::CSTART);
        setState(48);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case g_xmlParser::T__0:
          case g_xmlParser::T__3: {
            setState(41);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == g_xmlParser::T__3) {
              setState(40);
              attrlist();
            }
            setState(43);
            match(g_xmlParser::T__0);
            setState(44);
            body();
            setState(45);
            match(g_xmlParser::CEND);
            break;
          }

          case g_xmlParser::T__1: {
            setState(47);
            match(g_xmlParser::T__1);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case g_xmlParser::DSTART: {
        enterOuterAlt(_localctx, 4);
        setState(50);
        match(g_xmlParser::DSTART);
        setState(59);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case g_xmlParser::T__0:
          case g_xmlParser::T__3: {
            setState(52);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == g_xmlParser::T__3) {
              setState(51);
              attrlist();
            }
            setState(54);
            match(g_xmlParser::T__0);
            setState(55);
            body();
            setState(56);
            match(g_xmlParser::DEND);
            break;
          }

          case g_xmlParser::T__1: {
            setState(58);
            match(g_xmlParser::T__1);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case g_xmlParser::ESTART: {
        enterOuterAlt(_localctx, 5);
        setState(61);
        match(g_xmlParser::ESTART);
        setState(70);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case g_xmlParser::T__0:
          case g_xmlParser::T__3: {
            setState(63);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == g_xmlParser::T__3) {
              setState(62);
              attrlist();
            }
            setState(65);
            match(g_xmlParser::T__0);
            setState(66);
            body();
            setState(67);
            match(g_xmlParser::EEND);
            break;
          }

          case g_xmlParser::T__1: {
            setState(69);
            match(g_xmlParser::T__1);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
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

//----------------- BodyContext ------------------------------------------------------------------

g_xmlParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_xmlParser::XmlContext* g_xmlParser::BodyContext::xml() {
  return getRuleContext<g_xmlParser::XmlContext>(0);
}

g_xmlParser::TextContext* g_xmlParser::BodyContext::text() {
  return getRuleContext<g_xmlParser::TextContext>(0);
}


size_t g_xmlParser::BodyContext::getRuleIndex() const {
  return g_xmlParser::RuleBody;
}


g_xmlParser::BodyContext* g_xmlParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 4, g_xmlParser::RuleBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_xmlParser::ASTART:
      case g_xmlParser::BSTART:
      case g_xmlParser::CSTART:
      case g_xmlParser::DSTART:
      case g_xmlParser::ESTART: {
        enterOuterAlt(_localctx, 1);
        setState(74);
        xml();
        break;
      }

      case g_xmlParser::CHAR: {
        enterOuterAlt(_localctx, 2);
        setState(75);
        text(0);
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

//----------------- AttrlistContext ------------------------------------------------------------------

g_xmlParser::AttrlistContext::AttrlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_xmlParser::SpaceContext* g_xmlParser::AttrlistContext::space() {
  return getRuleContext<g_xmlParser::SpaceContext>(0);
}

g_xmlParser::AttrContext* g_xmlParser::AttrlistContext::attr() {
  return getRuleContext<g_xmlParser::AttrContext>(0);
}

g_xmlParser::AttrlistContext* g_xmlParser::AttrlistContext::attrlist() {
  return getRuleContext<g_xmlParser::AttrlistContext>(0);
}


size_t g_xmlParser::AttrlistContext::getRuleIndex() const {
  return g_xmlParser::RuleAttrlist;
}


g_xmlParser::AttrlistContext* g_xmlParser::attrlist() {
  AttrlistContext *_localctx = _tracker.createInstance<AttrlistContext>(_ctx, getState());
  enterRule(_localctx, 6, g_xmlParser::RuleAttrlist);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(85);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(78);
      space();
      setState(79);
      attr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(81);
      space();
      setState(82);
      attr();
      setState(83);
      attrlist();
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

//----------------- AttrContext ------------------------------------------------------------------

g_xmlParser::AttrContext::AttrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<g_xmlParser::TextContext *> g_xmlParser::AttrContext::text() {
  return getRuleContexts<g_xmlParser::TextContext>();
}

g_xmlParser::TextContext* g_xmlParser::AttrContext::text(size_t i) {
  return getRuleContext<g_xmlParser::TextContext>(i);
}

std::vector<tree::TerminalNode *> g_xmlParser::AttrContext::QUOTE() {
  return getTokens(g_xmlParser::QUOTE);
}

tree::TerminalNode* g_xmlParser::AttrContext::QUOTE(size_t i) {
  return getToken(g_xmlParser::QUOTE, i);
}


size_t g_xmlParser::AttrContext::getRuleIndex() const {
  return g_xmlParser::RuleAttr;
}


g_xmlParser::AttrContext* g_xmlParser::attr() {
  AttrContext *_localctx = _tracker.createInstance<AttrContext>(_ctx, getState());
  enterRule(_localctx, 8, g_xmlParser::RuleAttr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    text(0);
    setState(88);
    match(g_xmlParser::T__2);
    setState(89);
    match(g_xmlParser::QUOTE);
    setState(90);
    text(0);
    setState(91);
    match(g_xmlParser::QUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TextContext ------------------------------------------------------------------

g_xmlParser::TextContext::TextContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_xmlParser::TextContext::CHAR() {
  return getToken(g_xmlParser::CHAR, 0);
}

g_xmlParser::TextContext* g_xmlParser::TextContext::text() {
  return getRuleContext<g_xmlParser::TextContext>(0);
}


size_t g_xmlParser::TextContext::getRuleIndex() const {
  return g_xmlParser::RuleText;
}



g_xmlParser::TextContext* g_xmlParser::text() {
   return text(0);
}

g_xmlParser::TextContext* g_xmlParser::text(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  g_xmlParser::TextContext *_localctx = _tracker.createInstance<TextContext>(_ctx, parentState);
  g_xmlParser::TextContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, g_xmlParser::RuleText, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(g_xmlParser::CHAR);
    _ctx->stop = _input->LT(-1);
    setState(100);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TextContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleText);
        setState(96);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(97);
        match(g_xmlParser::CHAR); 
      }
      setState(102);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SpaceContext ------------------------------------------------------------------

g_xmlParser::SpaceContext::SpaceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t g_xmlParser::SpaceContext::getRuleIndex() const {
  return g_xmlParser::RuleSpace;
}


g_xmlParser::SpaceContext* g_xmlParser::space() {
  SpaceContext *_localctx = _tracker.createInstance<SpaceContext>(_ctx, getState());
  enterRule(_localctx, 12, g_xmlParser::RuleSpace);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(g_xmlParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool g_xmlParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return textSempred(dynamic_cast<TextContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool g_xmlParser::textSempred(TextContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> g_xmlParser::_decisionToDFA;
atn::PredictionContextCache g_xmlParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN g_xmlParser::_atn;
std::vector<uint16_t> g_xmlParser::_serializedATN;

std::vector<std::string> g_xmlParser::_ruleNames = {
  "start", "xml", "body", "attrlist", "attr", "text", "space"
};

std::vector<std::string> g_xmlParser::_literalNames = {
  "", "'>'", "'/>'", "'='", "' '", "'<a'", "'</a>'", "'<b'", "'</b>'", "'<c'", 
  "'</c>'", "'<d'", "'</d>'", "'<e'", "'</e>'", "", "'\u0022'"
};

std::vector<std::string> g_xmlParser::_symbolicNames = {
  "", "", "", "", "", "ASTART", "AEND", "BSTART", "BEND", "CSTART", "CEND", 
  "DSTART", "DEND", "ESTART", "EEND", "CHAR", "QUOTE"
};

dfa::Vocabulary g_xmlParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> g_xmlParser::_tokenNames;

g_xmlParser::Initializer::Initializer() {
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
    0x3, 0x12, 0x6c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x16, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x1d, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x21, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x28, 0xa, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2c, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x33, 0xa, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x37, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x5, 0x3, 0x3e, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x42, 
    0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
    0x49, 0xa, 0x3, 0x5, 0x3, 0x4b, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x4f, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x58, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x7, 0x7, 0x65, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x68, 0xb, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x2, 0x3, 0xc, 0x9, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x2, 0x2, 0x2, 0x75, 0x2, 0x10, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x4a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x59, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x69, 0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x5, 0x4, 0x3, 
    0x2, 0x11, 0x12, 0x7, 0x2, 0x2, 0x3, 0x12, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x13, 0x1c, 0x7, 0x7, 0x2, 0x2, 0x14, 0x16, 0x5, 0x8, 0x5, 0x2, 0x15, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 0x7, 0x3, 0x2, 0x2, 0x18, 0x19, 0x5, 
    0x6, 0x4, 0x2, 0x19, 0x1a, 0x7, 0x8, 0x2, 0x2, 0x1a, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x1b, 0x1d, 0x7, 0x4, 0x2, 0x2, 0x1c, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x27, 0x7, 0x9, 0x2, 0x2, 0x1f, 0x21, 0x5, 0x8, 0x5, 0x2, 0x20, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x7, 0x3, 0x2, 0x2, 0x23, 0x24, 0x5, 
    0x6, 0x4, 0x2, 0x24, 0x25, 0x7, 0xa, 0x2, 0x2, 0x25, 0x28, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x28, 0x7, 0x4, 0x2, 0x2, 0x27, 0x20, 0x3, 0x2, 0x2, 
    0x2, 0x27, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x29, 0x32, 0x7, 0xb, 0x2, 0x2, 0x2a, 0x2c, 0x5, 0x8, 0x5, 0x2, 0x2b, 
    0x2a, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x3, 0x2, 0x2, 0x2e, 0x2f, 0x5, 
    0x6, 0x4, 0x2, 0x2f, 0x30, 0x7, 0xc, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x33, 0x7, 0x4, 0x2, 0x2, 0x32, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x32, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x3d, 0x7, 0xd, 0x2, 0x2, 0x35, 0x37, 0x5, 0x8, 0x5, 0x2, 0x36, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 
    0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x3, 0x2, 0x2, 0x39, 0x3a, 0x5, 
    0x6, 0x4, 0x2, 0x3a, 0x3b, 0x7, 0xe, 0x2, 0x2, 0x3b, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x3e, 0x7, 0x4, 0x2, 0x2, 0x3d, 0x36, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x3f, 0x48, 0x7, 0xf, 0x2, 0x2, 0x40, 0x42, 0x5, 0x8, 0x5, 0x2, 0x41, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x7, 0x3, 0x2, 0x2, 0x44, 0x45, 0x5, 
    0x6, 0x4, 0x2, 0x45, 0x46, 0x7, 0x10, 0x2, 0x2, 0x46, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x49, 0x7, 0x4, 0x2, 0x2, 0x48, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x4a, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x34, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4f, 0x5, 
    0x4, 0x3, 0x2, 0x4d, 0x4f, 0x5, 0xc, 0x7, 0x2, 0x4e, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x51, 0x5, 0xe, 0x8, 0x2, 0x51, 0x52, 0x5, 0xa, 0x6, 0x2, 
    0x52, 0x58, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x5, 0xe, 0x8, 0x2, 0x54, 
    0x55, 0x5, 0xa, 0x6, 0x2, 0x55, 0x56, 0x5, 0x8, 0x5, 0x2, 0x56, 0x58, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x50, 0x3, 0x2, 0x2, 0x2, 0x57, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x9, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x5, 0xc, 
    0x7, 0x2, 0x5a, 0x5b, 0x7, 0x5, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x12, 0x2, 
    0x2, 0x5c, 0x5d, 0x5, 0xc, 0x7, 0x2, 0x5d, 0x5e, 0x7, 0x12, 0x2, 0x2, 
    0x5e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x8, 0x7, 0x1, 0x2, 0x60, 
    0x61, 0x7, 0x11, 0x2, 0x2, 0x61, 0x66, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 
    0xc, 0x4, 0x2, 0x2, 0x63, 0x65, 0x7, 0x11, 0x2, 0x2, 0x64, 0x62, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x68, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x6, 0x2, 0x2, 
    0x6a, 0xf, 0x3, 0x2, 0x2, 0x2, 0x10, 0x15, 0x1c, 0x20, 0x27, 0x2b, 0x32, 
    0x36, 0x3d, 0x41, 0x48, 0x4a, 0x4e, 0x57, 0x66, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

g_xmlParser::Initializer g_xmlParser::_init;
