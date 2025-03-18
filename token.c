#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
struct token* create_token(char token[64], enum TOKEN_TYPE type){
    struct token* t = malloc(sizeof(struct token));
    strcpy(t->token, token);
    t->type = type;
    return t;
};

char* to_string(struct token* token){
    return token->token;
};

void print_token(struct token token){
    int i = 0;
    while(token.token[i] != '\0'){
        printf("%c", token.token[i]);
        i++;                              
    }                                     
};