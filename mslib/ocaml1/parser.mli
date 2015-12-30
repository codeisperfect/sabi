type token =
  | NUMBER of (int)
  | STRING of (string)
  | NAME of (string)
  | ADD
  | SUB
  | MUL
  | MOD
  | DIV
  | COLON
  | LPARENM
  | RPARENM
  | LPAREN
  | RPAREN
  | LPARENB
  | RPARENB
  | TRUE
  | FALSE
  | AND
  | OR
  | QUESTION
  | SEMICOLON
  | COMMA
  | EQUAL
  | IF
  | ELIF
  | ELSE
  | FOR
  | ISEQUAL
  | LE
  | GE
  | LS
  | GT
  | NOTEQUAL
  | NOT
  | DOT
  | NONE
  | DEFINE
  | EOF

val main :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> inst list
