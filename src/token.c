//
// Created by MohammadMojtabaRoshani on 4/14/2021 AD.
//
#include "include/token.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

token_T* init_token(char* value , int type){
    //  set located memory to zero and then allocate requested memory and set pointer to it
    token_T* token = calloc(1,sizeof (struct TOKEN_STRUCT));
    token->value = value;
    token->type = type;

    return token;
}

static const char* token_type_to_str(int type){
    switch (type) {
        case TOKEN_ID: return "TOKEN_ID";
        case TOKEN_STRING: return "TOKEN_STRING";                    //  "
        case TOKEN_CHARACTER: return "TOKEN_CHARACTER";              //  '
        case TOKEN_R_CURLY: return "TOKEN_R_CURLY";                  //  {
        case TOKEN_L_CURLY: return "TOKEN_L_CURLY";                  //  }
        case TOKEN_R_PARENTHESIS: return "TOKEN_R_PARENTHESIS";      //  (
        case TOKEN_L_PARENTHESIS: return "TOKEN_L_PARENTHESIS";      //  )
        case TOKEN_R_BRACKET: return "TOKEN_R_BRACKET";              //  [
        case TOKEN_L_BRACKET: return "TOKEN_L_BRACKET";              //  ]
        case TOKEN_SEMICOLON: return "TOKEN_SEMICOLON";              //  ;
        case TOKEN_COMMA: return "TOKEN_COMMA";                      //  ;
        case TOKEN_DOT: return "TOKEN_DOT";                          //  .
        case TOKEN_ASSIGN: return "TOKEN_ASSIGN";                    //  =
        case TOKEN_ADD_ASSIGN: return "TOKEN_ADD_ASSIGN";            //  +=
        case TOKEN_SUB_ASSIGN: return "TOKEN_SUB_ASSIGN";            //  =-
        case TOKEN_MUL_ASSIGN: return "TOKEN_MUL_ASSIGN";            //  *=
        case TOKEN_DIV_ASSIGN: return "TOKEN_DIV_ASSIGN";            //  /=
        case TOKEN_MOD_ASSIGN: return "TOKEN_MOD_ASSIGN";            //  %=
        case TOKEN_INC: return "TOKEN_INC";                          //  ++
        case TOKEN_DEC: return "TOKEN_DEC";                          //  --
        case TOKEN_ADD: return "TOKEN_ADD";                          //  +
        case TOKEN_SUB: return "TOKEN_SUB";                          //  -
        case TOKEN_MUL: return "TOKEN_MUL";                          //  *
        case TOKEN_POWER: return "TOKEN_POWER";                      //  **
        case TOKEN_DIV: return "TOKEN_DIV";                          //  /
        case TOKEN_MOD: return "TOKEN_MOD";                          //  %
        case TOKEN_EQ: return "TOKEN_EQ";                            //  ==
        case TOKEN_NE: return "TOKEN_NE";                            //  !=
        case TOKEN_LT: return "TOKEN_LT";                            //  <
        case TOKEN_GT: return "TOKEN_GT";                            //  >
        case TOKEN_LE: return "TOKEN_LE";                            //  <=
        case TOKEN_GE: return "TOKEN_GE";                            //  >=
        case TOKEN_NOT: return "TOKEN_NOT";                          //  !
        case TOKEN_AND: return "TOKEN_AND";                          //  &&
        case TOKEN_OR: return "TOKEN_OR";                            //  ||
        case TOKEN_AUTO: return "TOKEN_AUTO";                        //  auto
        case TOKEN_BREAK: return "TOKEN_BREAK";                      //  break
        case TOKEN_CASE: return "TOKEN_CASE";                        //  case
        case TOKEN_CHAR: return "TOKEN_CHAR";                        //  char
        case TOKEN_CONST: return "TOKEN_CONTINUE";                   //  const
        case TOKEN_CONTINUE: return "TOKEN_CONTINUE";                //  continue
        case TOKEN_DEFAULT: return "TOKEN_DEFAULT";                  //  default
        case TOKEN_DO: return "TOKEN_DO";                            //  do
        case TOKEN_DOUBLE: return "TOKEN_DOUBLE";                    //  double
        case TOKEN_ELSE: return "TOKEN_ELSE";                        //  else
        case TOKEN_ENUM: return "TOKEN_ENUM";                        //  enum
        case TOKEN_EXTERN: return "TOKEN_EXTERN";                    //  extern
        case TOKEN_FLOAT: return "TOKEN_FLOAT";                      //  float
        case TOKEN_FOR: return "TOKEN_FOR";                          //  for
        case TOKEN_GOTO: return "TOKEN_GOTO";                        //  goto
        case TOKEN_IF: return "TOKEN_IF";                            //  if
        case TOKEN_INT: return "TOKEN_INT";                          //  int
        case TOKEN_LONG: return "TOKEN_LONG";                        //  long
        case TOKEN_REGISTER: return "TOKEN_REGISTER";                //  register
        case TOKEN_RETURN: return "TOKEN_RETURN";                    //  return
        case TOKEN_SHORT: return "TOKEN_SHORT";                      //  short
        case TOKEN_SIGNED: return "TOKEN_SIGNED";                    //  signed
        case TOKEN_SIZEOF: return "TOKEN_SIZEOF";                    //  sizeof
        case TOKEN_STATIC: return "TOKEN_STATIC";                    //  static
        case TOKEN_STRUCT: return "TOKEN_STRUCT";                    //  struct
        case TOKEN_SWITCH: return "TOKEN_SWITCH";                    //  switch
        case TOKEN_TYPEDEF: return "TOKEN_TYPEDEF";                  //  typedef
        case TOKEN_UNION: return "TOKEN_UNION";                      //  union
        case TOKEN_UNSIGNED: return "TOKEN_UNSIGNED";                //  unsigned
        case TOKEN_VOID: return "TOKEN_VOID";                        //  void
        case TOKEN_VOLATILE: return "TOKEN_VOLATILE";                //  volatile
        case TOKEN_WHILE: return "TOKEN_WHILE";                      //  while
        case TOKEN_SINGLE_COMMENT: return "TOKEN_SINGLE_COMMENT";    //  '//'
        case TOKEN_MULTI_COMMENT: return "TOKEN_MULTI_COMMENT";      //  '/**/'
        case TOKEN_NEXT_LINE: return "TOKEN_NEXT_LINE";              //  \n
        case TOKEN_TAB: return "TOKEN_TAB";                          //  \t
        case TOKEN_EOF: return "TOKEN_EOF";                          //  end of the file
        default: exit(1);
    }
}

char* token_to_str(token_T* token){
    const char* type_str = token_type_to_str(token-> type);
    const char* template = "< token: `%s` [%d] , value: `%s` >";            //  <type[type_num] , value>

    char* str = calloc(strlen(type_str) + strlen(template) + 8 , sizeof(char ));
    sprintf(str, template, type_str, token-> type, token->value);

    return str;
}