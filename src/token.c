//
// Created by MohammadMojtabaRoshani on 4/14/2021 AD.
//
#include "include/token.h"
#include <stdlib.h>

token_T* init_token(char* value , int type){
    //  set located memory to zero and then allocate requested memory and set pointer to it
    token_T* token = calloc(1,sizeof (struct TOKEN_STRUCT));
    token->value = value;
    token->type = type;

    return token;
}