// Write a C program to evaluate a Postfix expression using Stack.
/*
Compile using : gcc -o EvaluatePostfix EvaluatePostfix.c -lm

Postfix Expression: 6 5 2 3 + 8 * + 3 + *
Value => 288
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "header/stack.h"

// Define a stack of integers
DEFINE_STACK_TYPE(int)

int isOperator(char ch)
{
    switch (ch)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    case '^':
        return 1;
        break;
    default:
        return 0;
    }
}

int performOperation(char opr, int op1, int op2)
{
    switch (opr)
    {
    case '+':
        return (op1 + op2);
        break;
    case '-':
        return (op1 - op2);
        break;
    case '*':
        return (op1 * op2);
        break;
    case '/':
        return (op1 / op2);
        break;
    case '^':
        return (pow(op1, op2));
        break;
    default:
        return '\0';
    }
}

int isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int evaluatePostfix(char exp[])
{
    Stack myStack;
    initialize(&myStack);

    for (int i = 0; i < strlen(exp);)
    {
        if (isDigit(exp[i]))
        {
            // Handle multi-digit numbers
            int operand = 0;
            while (isDigit(exp[i]))
            {
                operand = operand * 10 + (exp[i] - '0');
                i++;
            }
            push(&myStack, operand);
        }
        else if (isOperator(exp[i]))
        {
            int op2 = pop(&myStack);
            int op1 = pop(&myStack);
            int result = performOperation(exp[i], op1, op2);
            push(&myStack, result);
            i++; // Move to the next character after the operator
        }
        else
            i++; // Ignore non-digit and non-operator characters
    }
    return peek(&myStack);
}

int main()
{
    char exp[100];
    printf("Enter a Postfix Expression (with space b/w each character): ");
    scanf("%[^\n]s", exp);

    int eval = evaluatePostfix(exp);
    printf("Value : %d\n", eval);

    return 0;
}