
// Generated from g_xml.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  g_xmlParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, ASTART = 5, AEND = 6, BSTART = 7, 
    BEND = 8, CSTART = 9, CEND = 10, DSTART = 11, DEND = 12, ESTART = 13, 
    EEND = 14, CHAR = 15, QUOTE = 16
  };

  enum {
    RuleStart = 0, RuleXml = 1, RuleBody = 2, RuleAttrlist = 3, RuleAttr = 4, 
    RuleText = 5, RuleSpace = 6
  };

  g_xmlParser(antlr4::TokenStream *input);
  ~g_xmlParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class XmlContext;
  class BodyContext;
  class AttrlistContext;
  class AttrContext;
  class TextContext;
  class SpaceContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    XmlContext *xml();
    antlr4::tree::TerminalNode *EOF();

   
  };

  StartContext* start();

  class  XmlContext : public antlr4::ParserRuleContext {
  public:
    XmlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASTART();
    BodyContext *body();
    antlr4::tree::TerminalNode *AEND();
    AttrlistContext *attrlist();
    antlr4::tree::TerminalNode *BSTART();
    antlr4::tree::TerminalNode *BEND();
    antlr4::tree::TerminalNode *CSTART();
    antlr4::tree::TerminalNode *CEND();
    antlr4::tree::TerminalNode *DSTART();
    antlr4::tree::TerminalNode *DEND();
    antlr4::tree::TerminalNode *ESTART();
    antlr4::tree::TerminalNode *EEND();

   
  };

  XmlContext* xml();

  class  BodyContext : public antlr4::ParserRuleContext {
  public:
    BodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    XmlContext *xml();
    TextContext *text();

   
  };

  BodyContext* body();

  class  AttrlistContext : public antlr4::ParserRuleContext {
  public:
    AttrlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SpaceContext *space();
    AttrContext *attr();
    AttrlistContext *attrlist();

   
  };

  AttrlistContext* attrlist();

  class  AttrContext : public antlr4::ParserRuleContext {
  public:
    AttrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TextContext *> text();
    TextContext* text(size_t i);
    std::vector<antlr4::tree::TerminalNode *> QUOTE();
    antlr4::tree::TerminalNode* QUOTE(size_t i);

   
  };

  AttrContext* attr();

  class  TextContext : public antlr4::ParserRuleContext {
  public:
    TextContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHAR();
    TextContext *text();

   
  };

  TextContext* text();
  TextContext* text(int precedence);
  class  SpaceContext : public antlr4::ParserRuleContext {
  public:
    SpaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  SpaceContext* space();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool textSempred(TextContext *_localctx, size_t predicateIndex);

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

