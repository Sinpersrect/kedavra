
// Generated from g_turtle.g4 by ANTLR 4.7.2



#include "g_turtleParser.h"


using namespace antlrcpp;
using namespace antlr4;

g_turtleParser::g_turtleParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

g_turtleParser::~g_turtleParser() {
  delete _interpreter;
}

std::string g_turtleParser::getGrammarFileName() const {
  return "g_turtle.g4";
}

const std::vector<std::string>& g_turtleParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& g_turtleParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

g_turtleParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_turtleParser::InstructionsContext* g_turtleParser::StartContext::instructions() {
  return getRuleContext<g_turtleParser::InstructionsContext>(0);
}

tree::TerminalNode* g_turtleParser::StartContext::EOF() {
  return getToken(g_turtleParser::EOF, 0);
}


size_t g_turtleParser::StartContext::getRuleIndex() const {
  return g_turtleParser::RuleStart;
}


g_turtleParser::StartContext* g_turtleParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, g_turtleParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    instructions();
    setState(9);
    match(g_turtleParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionsContext ------------------------------------------------------------------

g_turtleParser::InstructionsContext::InstructionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

g_turtleParser::InstructionContext* g_turtleParser::InstructionsContext::instruction() {
  return getRuleContext<g_turtleParser::InstructionContext>(0);
}

tree::TerminalNode* g_turtleParser::InstructionsContext::SPACE() {
  return getToken(g_turtleParser::SPACE, 0);
}

g_turtleParser::InstructionsContext* g_turtleParser::InstructionsContext::instructions() {
  return getRuleContext<g_turtleParser::InstructionsContext>(0);
}


size_t g_turtleParser::InstructionsContext::getRuleIndex() const {
  return g_turtleParser::RuleInstructions;
}


g_turtleParser::InstructionsContext* g_turtleParser::instructions() {
  InstructionsContext *_localctx = _tracker.createInstance<InstructionsContext>(_ctx, getState());
  enterRule(_localctx, 2, g_turtleParser::RuleInstructions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(16);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(11);
      instruction();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(12);
      instruction();
      setState(13);
      match(g_turtleParser::SPACE);
      setState(14);
      instructions();
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

//----------------- InstructionContext ------------------------------------------------------------------

g_turtleParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* g_turtleParser::InstructionContext::MOVEMENT() {
  return getToken(g_turtleParser::MOVEMENT, 0);
}

tree::TerminalNode* g_turtleParser::InstructionContext::NUMBER() {
  return getToken(g_turtleParser::NUMBER, 0);
}

std::vector<tree::TerminalNode *> g_turtleParser::InstructionContext::SPACE() {
  return getTokens(g_turtleParser::SPACE);
}

tree::TerminalNode* g_turtleParser::InstructionContext::SPACE(size_t i) {
  return getToken(g_turtleParser::SPACE, i);
}

std::vector<tree::TerminalNode *> g_turtleParser::InstructionContext::COLOR() {
  return getTokens(g_turtleParser::COLOR);
}

tree::TerminalNode* g_turtleParser::InstructionContext::COLOR(size_t i) {
  return getToken(g_turtleParser::COLOR, i);
}

g_turtleParser::CodeblockContext* g_turtleParser::InstructionContext::codeblock() {
  return getRuleContext<g_turtleParser::CodeblockContext>(0);
}


size_t g_turtleParser::InstructionContext::getRuleIndex() const {
  return g_turtleParser::RuleInstruction;
}


g_turtleParser::InstructionContext* g_turtleParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 4, g_turtleParser::RuleInstruction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(35);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case g_turtleParser::MOVEMENT: {
        enterOuterAlt(_localctx, 1);
        setState(18);
        match(g_turtleParser::MOVEMENT);
        setState(19);
        match(g_turtleParser::NUMBER);
        break;
      }

      case g_turtleParser::T__0: {
        enterOuterAlt(_localctx, 2);
        setState(20);
        match(g_turtleParser::T__0);
        setState(21);
        match(g_turtleParser::SPACE);
        setState(22);
        match(g_turtleParser::COLOR);
        setState(25);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          setState(23);
          match(g_turtleParser::SPACE);
          setState(24);
          match(g_turtleParser::COLOR);
          break;
        }

        }
        break;
      }

      case g_turtleParser::T__1: {
        enterOuterAlt(_localctx, 3);
        setState(27);
        match(g_turtleParser::T__1);
        setState(28);
        match(g_turtleParser::SPACE);
        setState(29);
        codeblock();
        break;
      }

      case g_turtleParser::T__2: {
        enterOuterAlt(_localctx, 4);
        setState(30);
        match(g_turtleParser::T__2);
        setState(31);
        match(g_turtleParser::SPACE);
        setState(32);
        match(g_turtleParser::NUMBER);
        setState(33);
        match(g_turtleParser::SPACE);
        setState(34);
        codeblock();
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

//----------------- CodeblockContext ------------------------------------------------------------------

g_turtleParser::CodeblockContext::CodeblockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<g_turtleParser::InstructionContext *> g_turtleParser::CodeblockContext::instruction() {
  return getRuleContexts<g_turtleParser::InstructionContext>();
}

g_turtleParser::InstructionContext* g_turtleParser::CodeblockContext::instruction(size_t i) {
  return getRuleContext<g_turtleParser::InstructionContext>(i);
}

std::vector<tree::TerminalNode *> g_turtleParser::CodeblockContext::SPACE() {
  return getTokens(g_turtleParser::SPACE);
}

tree::TerminalNode* g_turtleParser::CodeblockContext::SPACE(size_t i) {
  return getToken(g_turtleParser::SPACE, i);
}


size_t g_turtleParser::CodeblockContext::getRuleIndex() const {
  return g_turtleParser::RuleCodeblock;
}


g_turtleParser::CodeblockContext* g_turtleParser::codeblock() {
  CodeblockContext *_localctx = _tracker.createInstance<CodeblockContext>(_ctx, getState());
  enterRule(_localctx, 6, g_turtleParser::RuleCodeblock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37);
    match(g_turtleParser::T__3);
    setState(41); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(38);
      instruction();
      setState(39);
      match(g_turtleParser::SPACE);
      setState(43); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << g_turtleParser::T__0)
      | (1ULL << g_turtleParser::T__1)
      | (1ULL << g_turtleParser::T__2)
      | (1ULL << g_turtleParser::MOVEMENT))) != 0));
    setState(45);
    match(g_turtleParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> g_turtleParser::_decisionToDFA;
atn::PredictionContextCache g_turtleParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN g_turtleParser::_atn;
std::vector<uint16_t> g_turtleParser::_serializedATN;

std::vector<std::string> g_turtleParser::_ruleNames = {
  "start", "instructions", "instruction", "codeblock"
};

std::vector<std::string> g_turtleParser::_literalNames = {
  "", "'c'", "'fill'", "'repeat'", "'{'", "'}'", "", "", "", "' '"
};

std::vector<std::string> g_turtleParser::_symbolicNames = {
  "", "", "", "", "", "", "MOVEMENT", "COLOR", "NUMBER", "SPACE"
};

dfa::Vocabulary g_turtleParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> g_turtleParser::_tokenNames;

g_turtleParser::Initializer::Initializer() {
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
    0x3, 0xb, 0x32, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x13, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x1c, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x26, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 0x2c, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x2d, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x2, 0x2, 0x6, 0x2, 0x4, 0x6, 0x8, 0x2, 
    0x2, 0x2, 0x33, 0x2, 0xa, 0x3, 0x2, 0x2, 0x2, 0x4, 0x12, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x25, 0x3, 0x2, 0x2, 0x2, 0x8, 0x27, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0xb, 0x5, 0x4, 0x3, 0x2, 0xb, 0xc, 0x7, 0x2, 0x2, 0x3, 0xc, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0xd, 0x13, 0x5, 0x6, 0x4, 0x2, 0xe, 0xf, 0x5, 0x6, 0x4, 
    0x2, 0xf, 0x10, 0x7, 0xb, 0x2, 0x2, 0x10, 0x11, 0x5, 0x4, 0x3, 0x2, 
    0x11, 0x13, 0x3, 0x2, 0x2, 0x2, 0x12, 0xd, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0xe, 0x3, 0x2, 0x2, 0x2, 0x13, 0x5, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 
    0x7, 0x8, 0x2, 0x2, 0x15, 0x26, 0x7, 0xa, 0x2, 0x2, 0x16, 0x17, 0x7, 
    0x3, 0x2, 0x2, 0x17, 0x18, 0x7, 0xb, 0x2, 0x2, 0x18, 0x1b, 0x7, 0x9, 
    0x2, 0x2, 0x19, 0x1a, 0x7, 0xb, 0x2, 0x2, 0x1a, 0x1c, 0x7, 0x9, 0x2, 
    0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x1c, 0x26, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x4, 0x2, 0x2, 0x1e, 
    0x1f, 0x7, 0xb, 0x2, 0x2, 0x1f, 0x26, 0x5, 0x8, 0x5, 0x2, 0x20, 0x21, 
    0x7, 0x5, 0x2, 0x2, 0x21, 0x22, 0x7, 0xb, 0x2, 0x2, 0x22, 0x23, 0x7, 
    0xa, 0x2, 0x2, 0x23, 0x24, 0x7, 0xb, 0x2, 0x2, 0x24, 0x26, 0x5, 0x8, 
    0x5, 0x2, 0x25, 0x14, 0x3, 0x2, 0x2, 0x2, 0x25, 0x16, 0x3, 0x2, 0x2, 
    0x2, 0x25, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x25, 0x20, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x7, 0x3, 0x2, 0x2, 0x2, 0x27, 0x2b, 0x7, 0x6, 0x2, 0x2, 0x28, 
    0x29, 0x5, 0x6, 0x4, 0x2, 0x29, 0x2a, 0x7, 0xb, 0x2, 0x2, 0x2a, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x2b, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x7, 0x2, 
    0x2, 0x30, 0x9, 0x3, 0x2, 0x2, 0x2, 0x6, 0x12, 0x1b, 0x25, 0x2d, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

g_turtleParser::Initializer g_turtleParser::_init;
