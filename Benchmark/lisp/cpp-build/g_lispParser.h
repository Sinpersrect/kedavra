
// Generated from g_lisp.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  g_lispParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, LETTER = 4, NUMBER = 5, EMPTY = 6
  };

  enum {
    RuleStart = 0, RuleSexpression = 1, RuleList = 2, RuleAtomicsymbol = 3, 
    RuleAtompart = 4
  };

  g_lispParser(antlr4::TokenStream *input);
  ~g_lispParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class SexpressionContext;
  class ListContext;
  class AtomicsymbolContext;
  class AtompartContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SexpressionContext *sexpression();
    antlr4::tree::TerminalNode *EOF();

   
  };

  StartContext* start();

  class  SexpressionContext : public antlr4::ParserRuleContext {
  public:
    SexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomicsymbolContext *atomicsymbol();
    std::vector<SexpressionContext *> sexpression();
    SexpressionContext* sexpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EMPTY();
    antlr4::tree::TerminalNode* EMPTY(size_t i);
    ListContext *list();

   
  };

  SexpressionContext* sexpression();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
    ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SexpressionContext *> sexpression();
    SexpressionContext* sexpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EMPTY();
    antlr4::tree::TerminalNode* EMPTY(size_t i);

   
  };

  ListContext* list();

  class  AtomicsymbolContext : public antlr4::ParserRuleContext {
  public:
    AtomicsymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LETTER();
    AtompartContext *atompart();

   
  };

  AtomicsymbolContext* atomicsymbol();

  class  AtompartContext : public antlr4::ParserRuleContext {
  public:
    AtompartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LETTER();
    antlr4::tree::TerminalNode *NUMBER();
    AtompartContext *atompart();

   
  };

  AtompartContext* atompart();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

