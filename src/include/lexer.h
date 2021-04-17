//
// Created by MohammadMojtabaRoshani on 4/14/2021 AD.
//

#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H
#include "token.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct LEXER_STRUCT {
    char* src;
    size_t src_size;
    char c;         //  current charechter
    unsigned int i; //  index
    bool str_flag;
} lexer_T;

lexer_T* init_lexer(char* src);
void lexer_advance(lexer_T* lexer);
char lexer_peek(lexer_T* lexer, int offset);
token_T* lexer_advance_with(lexer_T* lexer, token_T* token);
token_T* lexer_advance_current(lexer_T* lexer, int type);
void lexer_skip_whitespaces(lexer_T* lexer);
void lexer_skip_comment(lexer_T* lexer);
void lexer_skip_other_language(lexer_T* lexer);
void lexer_string_finder(lexer_T* lexer);
token_T* lexer_parse_id(lexer_T* lexer);
token_T* lexer_parse_number(lexer_T* lexer);
token_T* lexer_next_token(lexer_T* lexer);
#endif //COMPILER_LEXER_H
