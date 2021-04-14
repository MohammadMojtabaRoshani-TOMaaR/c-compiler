//
// Created by MohammadMojtabaRoshani on 4/14/2021 AD.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H
typedef  struct TOKEN_STRUCT{
    char* value;
    enum {
        //  IDENTIFIER
        TOKEN_ID,
        //  STRING
        //  PUNCTUATION
        TOKEN_R_CURLY,          //  {
        TOKEN_L_CURLY,          //  }
        TOKEN_R_PARENTHESIS,    //  (
        TOKEN_E_PARENTHESIS,    //  )
        TOKEN_R_BRACKET,        //  [
        TOKEN_L_BRACKET,        //  ]
        TOKEN_SEMICOLON,        //  ;
        TOKEN_COMMA,            //  ,
        TOKEN_DOT,              //  .
        //  OPERATORS
        //# ASSIGNMENTS
        TOKEN_ASSIGN,           //  =
        TOKEN_ADD_ASSIGN,       //  +=
        TOKEN_SUB_ASSIGN,       //  =-
        TOKEN_MUL_ASSIGN,       //  *=
        TOKEN_DIV_ASSIGN,       //  /=
        //# 4 MAIN OPERATORS
        TOKEN_INC,              //  ++
        TOKEN_DEC,              //  --
        TOKEN_ADD,              //  +
        TOKEN_SUB,              //  -
        TOKEN_MUL,              //  *
        TOKEN_DIV,              //  /
        TOKEN_mod,              //  %
        //# CHECKERS AND BOOL OPERATORS
        TOKEN_EQ,               //  ==
        TOKEN_NE,               //  !=
        TOKEN_LT,               //  <
        TOKEN_GT,               //  >
        TOKEN_LE,               //  <=
        TOKEN_GE,               //  >=
        TOKEN_NOT,              //  !
        TOKEN_AND,              //  &&
        TOKEN_OR,               //  ||
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


    };
} token_T;
#endif //COMPILER_TOKEN_H
