
// Generated from g_mathexpr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  g_mathexprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    FUNC = 8, CONSTANT = 9, VAR = 10, FLOAT = 11, INTEGER = 12, SPACE = 13
  };

  enum {
    RuleStart = 0, RuleExpr = 1, RuleExprp = 2, RuleFunccall = 3, RuleArglist = 4, 
    RuleOp = 5
  };

  g_mathexprParser(antlr4::TokenStream *input);
  ~g_mathexprParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class ExprContext;
  class ExprpContext;
  class FunccallContext;
  class ArglistContext;
  class OpContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *EOF();

   
  };

  StartContext* start();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunccallContext *funccall();
    ExprpContext *exprp();
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *CONSTANT();
    ExprContext *expr();

   
  };

  ExprContext* expr();

  class  ExprpContext : public antlr4::ParserRuleContext {
  public:
    ExprpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);
    OpContext *op();
    ExprContext *expr();
    ExprpContext *exprp();

   
  };

  ExprpContext* exprp();

  class  FunccallContext : public antlr4::ParserRuleContext {
  public:
    FunccallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNC();
    ArglistContext *arglist();

   
  };

  FunccallContext* funccall();

  class  ArglistContext : public antlr4::ParserRuleContext {
  public:
    ArglistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *SPACE();
    ArglistContext *arglist();

   
  };

  ArglistContext* arglist();

  class  OpContext : public antlr4::ParserRuleContext {
  public:
    OpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OpContext* op();


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

