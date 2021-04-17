//
// Created by MohammadMojtabaRoshani on 4/14/2021 AD.
//
#include "include/lexer.h"
#include "include/main.h"
#include "include/macros.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>



lexer_T* init_lexer(char* src){
    //  set located memory to zero and then allocate requested memory and set pointer to it
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->src_size = strlen(src);  //  not include null character
    lexer->c = src[lexer->i];       //  current char
    lexer->i = 0;                   //  index

    return  lexer;
}

void lexer_advance(lexer_T* lexer){
    if (lexer->i < lexer->src_size && lexer->c != '\0'){
        lexer-> i += 1;
        lexer->c = lexer->src[lexer->i];
    }
}

char lexer_peek(lexer_T* lexer, int offset){
    return  lexer->src[MIN(lexer->i + offset, lexer->src_size)];
}

token_T* lexer_advance_with(lexer_T* lexer, token_T* token){
    lexer_advance(lexer);
    return token;
}

token_T* lexer_advance_current(lexer_T* lexer, int type){
    char* value = calloc(2, sizeof(char ));
    value[0] = lexer->c;
    value[1] = '\0';
    token_T* token = init_token(value, type);
    lexer_advance(lexer);
    return token;
}

void lexer_skip_whitespaces(lexer_T* lexer){
    //  check: Carriage Return || New Line || White Space || Tab Space
    while ((lexer->c == 13 && lexer->c == 10 )|| lexer->c == 32 || lexer->c == '\n' || lexer->c == ' ' || lexer->c == '\t'){
        lexer_advance(lexer);
    }
}

void lexer_skip_comment(lexer_T* lexer){
    if (lexer->c == '/' ){
        if (lexer_peek(lexer,1) == '/'){
            while (lexer->c != '\n')
                lexer_advance(lexer);
        }else if(lexer_peek(lexer,1) == '*'){
            while (1){
                if (lexer->c == '*' && lexer_peek(lexer, 1) == '/') {
                    lexer_advance(lexer);
                    lexer_advance(lexer);
                    break;
                }
            }
            lexer_advance(lexer);
        }
    }
    lexer_skip_whitespaces(lexer);
}

void lexer_skip_other_language(lexer_T* lexer){
    char* value = calloc(1, sizeof(char));
    static bool print_flag = false;
        while (lexer->c < 0 ) {
            value = realloc(value, (strlen(value) + 2) * sizeof(char));
            strcat(value, (char[]) {lexer->c, 0});
            lexer_advance(lexer);
            lexer_skip_whitespaces(lexer);
            print_flag = true;
        }
    if (print_flag)
    printf("ERROR[lexer]: OTHER LANGUAGE DETECTED: [%s]\n", value);
    print_flag = false;
}

token_T* lexer_parse_id(lexer_T* lexer){

    char* value = calloc(1, sizeof(char));
    //  check:
    while(isalpha(lexer->c) || lexer->c == '_'){
        //  allocate memory and return newly allocated memory/null
        value = realloc(value, (strlen(value) + 2) * sizeof(char));
        strcat(value, (char[]){lexer->c,0});
        lexer_advance(lexer);
    }
    return init_token(value, TOKEN_ID);
}

token_T* lexer_parse_number(lexer_T* lexer){
    char* value = calloc(1, sizeof(char));
    //  check:
    while(isdigit(lexer->c)){
        //  allocate memory and return newly allocated memory/null
        value = realloc(value, (strlen(value) + 2 * sizeof(char)));
        strcat(value, (char[]){lexer->c,0});
        lexer_advance(lexer);
    }
    return init_token(value, TOKEN_INT);
}

token_T* lexer_parse_string(lexer_T* lexer){
    char* value = calloc(1, sizeof(char));
    lexer_advance(lexer);   //  for first "
    while(lexer->c != '"'){
        //  allocate memory and return newly allocated memory/null
        value = realloc(value, (strlen(value) + 2 * sizeof(char)));
        strcat(value, (char[]){lexer->c,0});
        lexer_advance(lexer);
    }
    lexer_advance(lexer);   //  for second "
    return init_token(value, TOKEN_STRING);
}

token_T* lexer_next_token(lexer_T* lexer){

    while (lexer->c != '\0') {
        if (lexer->c == '$')break;

        lexer_skip_whitespaces(lexer);
        lexer_skip_comment(lexer);
        lexer_skip_other_language(lexer);


        if (isalpha(lexer->c) || lexer->c == '_')
            return lexer_advance_with(lexer, lexer_parse_id(lexer));

        if (isdigit(lexer->c))
            return lexer_advance_with(lexer, lexer_parse_number(lexer));

        switch (lexer->c) {
            case '=': {
                if (lexer_peek(lexer, 1) == '=')
                    return lexer_advance_with(lexer, init_token("==", TOKEN_EQ));
                else if (lexer_peek(lexer, 1) == '-')
                    return lexer_advance_with(lexer, init_token("=-", TOKEN_SUB_ASSIGN));
                return lexer_advance_with(lexer, init_token("=", TOKEN_ASSIGN));
            }
                break;
                //  PUNCTUATION
            case '{':
                return lexer_advance_current(lexer, TOKEN_R_CURLY);
            case '}':
                return lexer_advance_current(lexer, TOKEN_L_CURLY);
            case '(':
                return lexer_advance_current(lexer, TOKEN_R_PARENTHESIS);
            case ')':
                return lexer_advance_current(lexer, TOKEN_L_PARENTHESIS);
            case '[':
                return lexer_advance_current(lexer, TOKEN_R_BRACKET);
            case ']':
                return lexer_advance_current(lexer, TOKEN_L_BRACKET);
            case ';':
                return lexer_advance_current(lexer, TOKEN_SEMICOLON);
            case ',':
                return lexer_advance_current(lexer, TOKEN_COMMA);
            case '.':
                return lexer_advance_current(lexer, TOKEN_DOT);
            //  STRING
            case '"':
                return lexer_parse_string(lexer);
                //  OPERATORS
                //# ASSIGNMENTS
            case '+': {
                if (lexer_peek(lexer, 1) == '=')
                    return lexer_advance_with(lexer, init_token("+=", TOKEN_ADD_ASSIGN));
                else if (lexer_peek(lexer, 1) == '+')
                    return lexer_advance_with(lexer, init_token("++", TOKEN_INC));
                return lexer_advance_with(lexer, init_token("+", TOKEN_ADD));
            }
                break;
            case '-': {
                if (lexer_peek(lexer, 1) == '-')
                    return lexer_advance_with(lexer, init_token("--", TOKEN_DEC));
                return lexer_advance_with(lexer, init_token("-", TOKEN_SUB));
            }
                break;
            case '*': {
                if (lexer_peek(lexer, 1) == '=')
                    return lexer_advance_with(lexer, init_token("*=", TOKEN_MUL_ASSIGN));
                else if (lexer_peek(lexer, 1) == '*')
                    return lexer_advance_with(lexer, init_token("**", TOKEN_POWER));
                return lexer_advance_with(lexer, init_token("*", TOKEN_MUL));
            }
                break;
            case '/': {
                if (lexer_peek(lexer, 1) == '=')
                    return lexer_advance_with(lexer, init_token("/=", TOKEN_DIV_ASSIGN));
                return lexer_advance_with(lexer, init_token("/", TOKEN_DIV));
            }
                break;
            case '%': {
                if (lexer_peek(lexer, 1) == '=')
                    return lexer_advance_with(lexer, init_token("%=", TOKEN_MOD_ASSIGN));
                return lexer_advance_with(lexer, init_token("%", TOKEN_MOD));
            }
                break;
            case '!': {
                if (lexer_peek(lexer, 1) == '=')
                    return lexer_advance_with(lexer, init_token("!=", TOKEN_NE));
                return lexer_advance_with(lexer, init_token("!", TOKEN_NOT));
            }
                break;
            case '<': {
                if (lexer_peek(lexer, 1) == '=')
                    return lexer_advance_with(lexer, init_token("<=", TOKEN_LE));
                return lexer_advance_with(lexer, init_token("<", TOKEN_LT));
            }
                break;
            case '>': {
                if (lexer_peek(lexer, 1) == '=')
                    return lexer_advance_with(lexer, init_token(">=", TOKEN_GE));
                return lexer_advance_with(lexer, init_token(">", TOKEN_GT));
            }
                break;
            case '&': {
                if (lexer_peek(lexer, 1) == '&')
                    return lexer_advance_with(lexer, init_token("&&", TOKEN_AND));
            }
                break;
            case '|': {
                if (lexer_peek(lexer, 1) == '|')
                    return lexer_advance_with(lexer, init_token("||", TOKEN_OR));
            }
                break;
            case '\0': break;
            default: printf("ERROR[lexer]: UNEXPECTED CHARACTER: `%c`, ASCII :%d\n", lexer->c, (int) lexer->c); exit(1); break;
        }
    }
    return init_token(0, TOKEN_EOF);
}