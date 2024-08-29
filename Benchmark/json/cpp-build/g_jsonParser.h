
// Generated from g_json.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  g_jsonParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, NUMBER = 10, STRING = 11, QUOTE = 12
  };

  enum {
    RuleStart = 0, RuleValue = 1, RuleArray = 2, RuleList = 3, RuleObject = 4, 
    RuleObjtuple = 5, RuleObjlist = 6
  };

  g_jsonParser(antlr4::TokenStream *input);
  ~g_jsonParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class ValueContext;
  class ArrayContext;
  class ListContext;
  class ObjectContext;
  class ObjtupleContext;
  class ObjlistContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueContext *value();
    antlr4::tree::TerminalNode *EOF();

   
  };

  StartContext* start();

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ObjectContext *object();
    ArrayContext *array();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *NUMBER();

   
  };

  ValueContext* value();

  class  ArrayContext : public antlr4::ParserRuleContext {
  public:
    ArrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ListContext *list();

   
  };

  ArrayContext* array();

  class  ListContext : public antlr4::ParserRuleContext {
  public:
    ListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueContext *value();
    ListContext *list();

   
  };

  ListContext* list();
  ListContext* list(int precedence);
  class  ObjectContext : public antlr4::ParserRuleContext {
  public:
    ObjectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ObjlistContext *objlist();

   
  };

  ObjectContext* object();

  class  ObjtupleContext : public antlr4::ParserRuleContext {
  public:
    ObjtupleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    ValueContext *value();

   
  };

  ObjtupleContext* objtuple();

  class  ObjlistContext : public antlr4::ParserRuleContext {
  public:
    ObjlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ObjtupleContext *objtuple();
    ObjlistContext *objlist();

   
  };

  ObjlistContext* objlist();
  ObjlistContext* objlist(int precedence);

  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool listSempred(ListContext *_localctx, size_t predicateIndex);
  bool objlistSempred(ObjlistContext *_localctx, size_t predicateIndex);

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

