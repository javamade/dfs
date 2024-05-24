// Write a C program to convert Infix expression to Postfix expression
/*
Infix : [{A+(B*C)}-(D*E)]
Postfix : ABC*+DE*-
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "header/stack.h"

DEFINE_STACK_TYPE(char)

int isOperator(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return 1;
    default:
        return 0;
    }
}

int IsOpeningParentheses(char ch)
{
    return (ch == '(' || ch == '{' || ch == '[');
}

int IsClosingParentheses(char ch)
{
    return (ch == ')' || ch == '}' || ch == ']');
}

int getOperatorPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int HasHigherPrec(char op1, char op2)
{
    int prec1 = getOperatorPrecedence(op1);
    int prec2 = getOperatorPrecedence(op2);

    return prec1 >= prec2;
}

char *InfixToPostfix(char exp[])
{
    Stack S;
    initialize(&S);
    char *res = (char *)malloc(100 * sizeof(char)); // Allocate memory for the result
    int j = 0;

    for (int i = 0; i < strlen(exp); i++)
    {
        if (isalnum(exp[i]))
        {
            res[j++] = exp[i];
        }
        else if (isOperator(exp[i]))
        {
            while (!isEmpty(&S) && !IsOpeningParentheses(peek(&S)) && HasHigherPrec(peek(&S), exp[i]))
            {
                res[j++] = pop(&S);
            }
            push(&S, exp[i]);
        }
        else if (IsOpeningParentheses(exp[i]))
        {
            push(&S, exp[i]);
        }
        else if (IsClosingParentheses(exp[i]))
        {
            while (!isEmpty(&S) && !IsOpeningParentheses(peek(&S)))
            {
                res[j++] = pop(&S);
            }
            pop(&S);
        }
    }

    while (!isEmpty(&S))
    {
        res[j++] = pop(&S);
    }

    // Null-terminate the result string
    res[j] = '\0';

    return res;
}

int main()
{
    char exp[100];
    printf("Enter an infix expression: ");
    scanf("%[^\n]s", exp);

    char *res;
    res = InfixToPostfix(exp);

    printf("Postfix expression: %s\n", res);

    // Free the allocated memory for the result string
    free(res);

    return 0;
}