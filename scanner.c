#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "token.h"
struct token_array
{
    struct token *t;
    int size;
    int capacity;
};

void push(struct token_array *arr, struct token *t)
{
    if (arr->capacity == 0)
    {
        arr->capacity = 1;
        arr->t = (struct token *)malloc(arr->capacity * sizeof(struct token));

    }
    if (arr->capacity == arr->size)
    {
        arr->capacity *= 2;
        arr->t = (struct token *)realloc(arr->t, arr->capacity * sizeof(struct token));
    }
    arr->t[arr->size] = *t;
    arr->size++;
};

struct token_array *scan_tokens(char *tokens)
{
    struct token_array *arr = (struct token_array *)malloc(sizeof(struct token_array)); 
    arr->t = NULL;
    arr->size = 0;
    arr->capacity = 0; 

    int i = 0;
    while (*tokens != '\0')
    {
        struct token *t;

        if ((tokens[i]) == '(')
        {
            char *leftParen;
            leftParen = "(";
            t = create_token(leftParen, LEFT_PAREN);
            push(arr, t);
            free(t); 
            tokens++;
        }
        else if (*tokens == ')')
        {
            char *rightParen;
            rightParen = ")";
            t = create_token(rightParen, RIGHT_PAREN);
            push(arr, t);
            free(t); 
            tokens++;
        }
        else if (*tokens == '/')
        {
            char *div;
            div = "/";
            t = create_token(div, DIV);
            push(arr, t);
            free(t); 
            tokens++;
        }
        else if (*tokens == '*')
        {
            char *mult;
            mult = "*";
            t = create_token(mult, MULT);
            push(arr, t);
            free(t); 
            tokens++;
        }
        else if (*tokens == '+')
        {
            char *plus;
            plus = "+";
            t = create_token(plus, PLUS);
            push(arr, t);
            free(t); 
            tokens++;
        }
        else if (*tokens == '-')
        {
            char *minus;
            minus = "-";
            t = create_token(minus, MINUS);
            push(arr, t);
            free(t); 
            tokens++;
        }
        else if (isdigit(*tokens))
        {
            int dLength = 0;
            int capacity = 1;
            char *c = (char *)malloc(capacity * sizeof(char));
            while (*tokens != '\0' && isdigit(*tokens))
            {
                if (capacity <= dLength)
                {
                    capacity *= 2;
                    char *temp = (char *)realloc(c, capacity * sizeof(char));
                    if (temp != NULL)
                    {
                        c = temp;
                    }
                    else
                    {
                        free(c);
                    }
                }
                c[dLength] = *tokens;
                tokens++;
                dLength++;
            }
            c[dLength] = '\0'; 
            t = create_token(c, NUMBER); 
            push(arr, t);
            free(c);
            free(t);
        }
        else if(isspace(*tokens) || isblank(*tokens))
        {
            tokens++;
        }
    }
    return arr;
};
int main(int argc, char *argv[])
{
    char *t = argv[1];
    struct token_array *arr = scan_tokens(t);
    for (int i = 0; i < arr->size; i++) { 
        printf("Token: %s\n", arr->t[i].token); 
    }
    free(arr->t); 
    free(arr);    
};