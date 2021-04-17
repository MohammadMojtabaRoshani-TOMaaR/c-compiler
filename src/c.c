//
// Created by MohammadMojtabaRoshani on 4/17/2021 AD.
//

#include "include/c.h"
#include "include/lexer.h"
#include "include/io.h"
#include <stdlib.h>

void c_compiler(char* src){
    lexer_T* lexer = init_lexer(src);
    token_T* token = 0;
    short int token_counter = 1;
    while ((token = lexer_next_token(lexer))->type != TOKEN_EOF){
        printf("%d:\t%s\n", token_counter++, token_to_str(token));
    }
}
void c_compiler_file(const char* filename){

    char* src = c_read_file(filename);
    c_compiler(src);
    free(src);
}