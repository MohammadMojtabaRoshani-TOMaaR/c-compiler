//
// Created by MohammadMojtabaRoshani on 4/14/2021 AD.
//
#include "include/lexer.h"
#include "include/main.h"
#include "include/macros.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
        lexer-> i = 1;
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

void lexer_skip_whitespaces(lexer_T* lexer){
    //  check: Carriage Return || New Line || White Space || Tab Space
    while ((lexer->c == 13 && lexer->c == 10) || lexer->c == ' ' || lexer->c == '\t'){
        lexer_advance(lexer);
    }
}

token_T* lexer_parse_id(lexer_T* lexer){
    char* value = calloc(1, sizeof(char));
    //  check:
    while(isalpha(lexer->c)){
        //  allocate memory and return newly allocated memory/null
        value = realloc(value, (strlen(value) + 2 * sizeof(char)));
        strcat(value, (char[]){lexer->c,0});
        lexer_advance(lexer);
    }
    return init_token(value, TOKEN_ID);
}

token_T* lexer_next_token(lexer_T* lexer){
    while (lexer->c != '\0'){
        //  check:
        if(isalpha(lexer->c)){
            return lexer_advance_with(lexer, lexer_parse_id(lexer));

            switch (lexer->c) {
                case '=': {
                    if (lexer_peek(lexer,1) == '=')
                        return lexer_advance_with(lexer, init_token("==", TOKEN_EQ));
                    return lexer_advance_with(lexer, init_token("=", TOKEN_ASSIGN));
                } break;

            }
        }
    }
    return init_token(0, TOKEN_EOF);
}