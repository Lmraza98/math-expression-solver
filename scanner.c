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
    }
    if (arr->capacity == arr->size)
    {
        arr->t = (struct token *)realloc(arr->t, arr->capacity * 2 * sizeof(struct token *));
    }
    arr->t[arr->size] = *t;
    arr->size++;
};

struct token_array *scan_tokens(char *tokens)
{
    struct token_array arr = {NULL, 0, 0};
    arr.t = (struct token *)malloc(arr.capacity * sizeof(struct token *));
    struct token_array *arrPtr = &arr;
    int i = 0;
    while (*tokens != '\0')
    {
        struct token *t;

        if ((tokens[i]) == '(')
        {
            char *leftParen;
            leftParen = "(";
            t = create_token(leftParen, LEFT_PAREN);
            printf("token: ");
            print_token(*t);
            printf("\n");
            push(arrPtr, t);
            tokens++;
        }
        else if (*tokens == ')')
        {
            char *rightParen;
            rightParen = ")";
            t = create_token(rightParen, RIGHT_PAREN);
            printf("token: ");
            print_token(*t);
            printf("\n");
            push(arrPtr, t);
            tokens++;
        }
        else if (*tokens == '/')
        {
            char *div;
            div = "/";
            t = create_token(div, DIV);
            printf("token: ");
            print_token(*t);
            printf("\n");
            push(arrPtr, t);
            tokens++;
        }
        else if (*tokens == '*')
        {
            char *mult;
            mult = "*";
            t = create_token(mult, MULT);
            printf("token: ");
            print_token(*t);
            printf("\n");
            push(arrPtr, t);
            tokens++;
        }
        else if (*tokens == '+')
        {
            char *plus;
            plus = "+";
            t = create_token(plus, PLUS);
            printf("token: ");
            print_token(*t);
            printf("\n");
            push(arrPtr, t);
            tokens++;
        }
        else if (*tokens == '-')
        {
            char *minus;
            minus = "-";
            t = create_token(minus, MINUS);
            printf("token: ");
            print_token(*t);
            printf("\n");
            push(arrPtr, t);
            tokens++;
        }
        else if (isdigit(*tokens))
        {
            int dLength = 0;
            int capacity = 1;
            char *c = (char *)malloc(capacity * sizeof(char));
            while (*tokens != '\0' && isdigit(*tokens))
            {
                if (capacity == dLength)
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
            t = create_token(c, NUMBER);
            printf("token: ");
            print_token(*t);
            printf("\n");
            push(arrPtr, t);
            free(c);
        }
        else if(isspace(*tokens) || isblank(*tokens))
        {
            tokens++;
        }
    }
    return arrPtr;
};
int main(int argc, char *argv[])
{
    char *t = argv[1];
    scan_tokens(t);
};