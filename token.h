#include <stdio.h>
#ifndef TOKEN_H
#define TOKEN_H
enum TOKEN_TYPE { PLUS, MINUS, MULT, DIV, LEFT_PAREN, RIGHT_PAREN, NUMBER };

struct token {
    char token[64];
    enum TOKEN_TYPE type;
};

char* to_string(struct token* t);

void print_token(struct token token);

struct token* create_token(char token[64], enum TOKEN_TYPE type);
#endif