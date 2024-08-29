grammar g_arith;
start: expr EOF;
expr : NUM exprp | '(' expr ')' exprp;
exprp : op expr exprp |;
op: '+' | '*' | '-' | '/';
NUM : '0'..'9' | '1'..'9' ('0'..'9')+;