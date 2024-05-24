#include <stdio.h>
#include <string.h>
#include "header/stack.h"

DEFINE_STACK_TYPE(char);

char getMatchingOpening(char closing)
{
    if (closing == ')') return '(';
    if (closing == '}') return '{';
    if (closing == ']') return '[';
    return '\0';
}

int CheckBalancedParentheses(char exp[]) {
    int n = strlen(exp);
    Stack myStack;
    initialize(&myStack);

    for (int i = 0; i < n; i++) {

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[' ) {
            push(&myStack, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(&myStack) || peek(&myStack) != getMatchingOpening(exp[i])) {
                return 0;
            } else {
                pop(&myStack);
            }
        }
    }
    return isEmpty(&myStack) ? 1 : 0;
}

int main() {
    char exp[100];
    
    printf("Enter a String (with parentheses): ");
    scanf("%[^\n]s", exp);

    int result = CheckBalancedParentheses(exp);

    if (result) {
        printf("Expression is balanced.\n");
    } else {
        printf("Expression is unbalanced!!!\n");
    }

    return 0;
}
