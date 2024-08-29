
// Generated from g_fol.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  g_folParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, LPAREN = 6, RPAREN = 7, 
    EQUAL = 8, NOT = 9, FORALL = 10, EXISTS = 11, CHARACTER = 12, CONJ = 13, 
    DISJ = 14, IMPL = 15, BICOND = 16, SPACE = 17
  };

  enum {
    RuleStart = 0, RuleFormula = 1, RuleTerm = 2, RuleBin_connective = 3, 
    RuleVariable = 4, RulePred_constant = 5, RuleInd_constant = 6, RuleFunc_constant = 7, 
    RuleSeparator = 8
  };

  g_folParser(antlr4::TokenStream *input);
  ~g_folParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class FormulaContext;
  class TermContext;
  class Bin_connectiveContext;
  class VariableContext;
  class Pred_constantContext;
  class Ind_constantContext;
  class Func_constantContext;
  class SeparatorContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FormulaContext *formula();
    antlr4::tree::TerminalNode *EOF();

   
  };

  StartContext* start();

  class  FormulaContext : public antlr4::ParserRuleContext {
  public:
    FormulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    std::vector<FormulaContext *> formula();
    FormulaContext* formula(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);
    Bin_connectiveContext *bin_connective();
    antlr4::tree::TerminalNode *FORALL();
    antlr4::tree::TerminalNode *LPAREN();
    VariableContext *variable();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *EXISTS();
    Pred_constantContext *pred_constant();
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    std::vector<SeparatorContext *> separator();
    SeparatorContext* separator(size_t i);
    antlr4::tree::TerminalNode *EQUAL();

   
  };

  FormulaContext* formula();
  FormulaContext* formula(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ind_constantContext *ind_constant();
    VariableContext *variable();
    Func_constantContext *func_constant();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<SeparatorContext *> separator();
    SeparatorContext* separator(size_t i);

   
  };

  TermContext* term();

  class  Bin_connectiveContext : public antlr4::ParserRuleContext {
  public:
    Bin_connectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONJ();
    antlr4::tree::TerminalNode *DISJ();
    antlr4::tree::TerminalNode *IMPL();
    antlr4::tree::TerminalNode *BICOND();

   
  };

  Bin_connectiveContext* bin_connective();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CHARACTER();
    antlr4::tree::TerminalNode* CHARACTER(size_t i);

   
  };

  VariableContext* variable();

  class  Pred_constantContext : public antlr4::ParserRuleContext {
  public:
    Pred_constantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CHARACTER();
    antlr4::tree::TerminalNode* CHARACTER(size_t i);

   
  };

  Pred_constantContext* pred_constant();

  class  Ind_constantContext : public antlr4::ParserRuleContext {
  public:
    Ind_constantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CHARACTER();
    antlr4::tree::TerminalNode* CHARACTER(size_t i);

   
  };

  Ind_constantContext* ind_constant();

  class  Func_constantContext : public antlr4::ParserRuleContext {
  public:
    Func_constantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CHARACTER();
    antlr4::tree::TerminalNode* CHARACTER(size_t i);

   
  };

  Func_constantContext* func_constant();

  class  SeparatorContext : public antlr4::ParserRuleContext {
  public:
    SeparatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  SeparatorContext* separator();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool formulaSempred(FormulaContext *_localctx, size_t predicateIndex);

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

