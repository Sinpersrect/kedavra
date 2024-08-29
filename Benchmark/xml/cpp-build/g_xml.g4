grammar g_xml;
start: xml EOF;
xml: ASTART ((attrlist? '>' body AEND)| '/>')
    | BSTART ((attrlist? '>' body BEND)| '/>')
    | CSTART ((attrlist? '>' body CEND)| '/>')
    | DSTART ((attrlist? '>' body DEND)| '/>')
    | ESTART ((attrlist? '>' body EEND)| '/>');
body: xml | text;
ASTART: '<a';
AEND: '</a>';
BSTART: '<b';
BEND: '</b>';
CSTART: '<c';
CEND: '</c>';
DSTART: '<d';
DEND: '</d>';
ESTART: '<e';
EEND: '</e>';
attrlist: space attr | space attr attrlist;
attr: text '=' QUOTE text  QUOTE;
text: text CHAR | CHAR;
CHAR: 'a'..'z' | 'A'..'Z';
space: ' ';
QUOTE: '\u0022';