grammar g_fol;
start: formula EOF;
formula: formula SPACE bin_connective SPACE formula
   | NOT formula SPACE bin_connective SPACE formula
   | NOT formula
   | FORALL LPAREN variable RPAREN SPACE formula
   | EXISTS LPAREN variable RPAREN SPACE formula
   | pred_constant LPAREN term (separator term)* RPAREN
   | term SPACE EQUAL SPACE term;
term: ind_constant
   | variable
   | func_constant LPAREN term (separator term)* RPAREN;
bin_connective: CONJ
   | DISJ
   | IMPL
   | BICOND;
variable : '?' CHARACTER+;
pred_constant : '_' CHARACTER+;
ind_constant: '#' CHARACTER+;
func_constant: '.' CHARACTER+;
LPAREN:'(';
RPAREN:')';
separator:', ';
EQUAL:'=';
NOT:'!';
FORALL:'Forall';
EXISTS:'Exists';
CHARACTER:('0'..'9' | 'a'..'z' | 'A'..'Z');
CONJ:'\\/';
DISJ:'^';
IMPL:'->';
BICOND:'<->';
SPACE: ' ';