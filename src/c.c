//
// Created by MohammadMojtabaRoshani on 4/17/2021 AD.
//

#include "include/c.h"
#include "include/lexer.h"
#include "include/io.h"
#include <stdlib.h>

void c_compiler(char* src){
    lexer_T* lexer = init_lexer(src);
    token_T* tok = 0;
    while ((tok = lexer_next_token(lexer))->type != TOKEN_EOF){
        printf("MESSAGE[token]: value = %s\ttype = %d \n", tok->value, tok->type);
    }
}
void c_compiler_file(const char* filename){

    char* src = c_read_file(filename);
    c_compiler(src);
    free(src);
}