//
// Created by MohammadMojtabaRoshani on 4/14/2021 AD.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H
typedef  struct TOKEN_STRUCT{
    char* value;
    enum {
        //  IDENTIFIER
        TOKEN_ID,               //      LEXER
        //  STRING
        TOKEN_STRING,            //  "   LEXER
        TOKEN_CHARACTER,         //  '   LEXER
        //  PUNCTUATION
        TOKEN_R_CURLY,          //  {   LEXER
        TOKEN_L_CURLY,          //  }   LEXER
        TOKEN_R_PARENTHESIS,    //  (   LEXER
        TOKEN_L_PARENTHESIS,    //  )   LEXER
        TOKEN_R_BRACKET,        //  [   LEXER
        TOKEN_L_BRACKET,        //  ]   LEXER
        TOKEN_SEMICOLON,        //  ;   LEXER
        TOKEN_COMMA,            //  ,   LEXER
        TOKEN_DOT,              //  .   LEXER
        //  OPERATORS
        //# ASSIGNMENTS
        TOKEN_ASSIGN,           //  =   LEXER
        TOKEN_ADD_ASSIGN,       //  +=  LEXER
        TOKEN_SUB_ASSIGN,       //  =-  LEXER
        TOKEN_MUL_ASSIGN,       //  *=  LEXER
        TOKEN_DIV_ASSIGN,       //  /=  LEXER
        TOKEN_MOD_ASSIGN,       //  %=  LEXER
        //# 4 MAIN OPERATORS
        TOKEN_INC,              //  ++  LEXER
        TOKEN_DEC,              //  --  LEXER
        TOKEN_ADD,              //  +   LEXER
        TOKEN_SUB,              //  -   LEXER
        TOKEN_MUL,              //  *   LEXER
        TOKEN_POWER,            //  **  LEXER
        TOKEN_DIV,              //  /   LEXER
        TOKEN_MOD,              //  %   LEXER
        //# CHECKERS AND BOOL OPERATORS
        TOKEN_EQ,               //  ==  LEXER
        TOKEN_NE,               //  !=  LEXER
        TOKEN_LT,               //  <   LEXER
        TOKEN_GT,               //  >   LEXER
        TOKEN_LE,               //  <=  LEXER
        TOKEN_GE,               //  >=  LEXER
        TOKEN_NOT,              //  !   LEXER
        TOKEN_AND,              //  &&  LEXER
        TOKEN_OR,               //  ||  LEXER
        //  KEYWORD
        TOKEN_AUTO,             //  auto
        TOKEN_BREAK,            //  break
        TOKEN_CASE,             //  case
        TOKEN_CHAR,             //  char
        TOKEN_CONST,            //  const
        TOKEN_CONTINUE,         //  continue
        TOKEN_DEFAULT,          //  default
        TOKEN_DO,               //  do
        TOKEN_DOUBLE,           //  double
        TOKEN_ELSE,             //  else
        TOKEN_ENUM,             //  enum
        TOKEN_EXTERN,           //  extern
        TOKEN_FLOAT,            //  float
        TOKEN_FOR,              //  for
        TOKEN_GOTO,             //  goto
        TOKEN_IF,               //  if
        TOKEN_INT,              //  int
        TOKEN_LONG,             //  long
        TOKEN_REGISTER,         //  register
        TOKEN_RETURN,           //  return
        TOKEN_SHORT,            //  short
        TOKEN_SIGNED,           //  signed
        TOKEN_SIZEOF,           //  sizeof
        TOKEN_STATIC,           //  static
        TOKEN_STRUCT,           //  struct
        TOKEN_SWITCH,           //  switch
        TOKEN_TYPEDEF,          //  typedef
        TOKEN_UNION,            //  union
        TOKEN_UNSIGNED,         //  unsigned
        TOKEN_VOID,             //  void
        TOKEN_VOLATILE,         //  volatile
        TOKEN_WHILE,            //  while
        //  Comment
        TOKEN_SINGLE_COMMENT,   //  '//'
        TOKEN_MULTI_COMMENT,    //  '/**/'
        //  Delimiter
        TOKEN_NEXT_LINE,        //  \n
        TOKEN_TAB,              //  \t
        //  OTHERS
        TOKEN_EOF               //  end of the file
    } type;
} token_T;
token_T* init_token(char* value , int type);
char* token_to_str(token_T* token);
#endif //COMPILER_TOKEN_H
