#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define MAX_SIZE 100

#define DEFINE_STACK_TYPE(type)                 \
    typedef struct Stack                        \
    {                                           \
        type items[MAX_SIZE];                   \
        int top;                                \
    } Stack;                                    \
                                                \
    void initialize(Stack *stack)               \
    {                                           \
        stack->top = -1;                        \
    }                                           \
                                                \
    int isEmpty(Stack *stack)                   \
    {                                           \
        return stack->top == -1;                \
    }                                           \
                                                \
    int isFull(Stack *stack)                    \
    {                                           \
        return stack->top == MAX_SIZE - 1;      \
    }                                           \
                                                \
    void push(Stack *stack, type value)         \
    {                                           \
        if (isFull(stack))                      \
        {                                       \
            printf("Stack overflow\n");         \
        }                                       \
        else                                    \
        {                                       \
            stack->items[++stack->top] = value; \
        }                                       \
    }                                           \
                                                \
    type pop(Stack *stack)                      \
    {                                           \
        if (isEmpty(stack))                     \
        {                                       \
            printf("Stack underflow\n");        \
            return (type)-1;                    \
        }                                       \
        else                                    \
        {                                       \
            return stack->items[stack->top--];  \
        }                                       \
    }                                           \
                                                \
    type peek(Stack *stack)                     \
    {                                           \
        if (isEmpty(stack))                     \
        {                                       \
            printf("Stack is empty\n");         \
            return (type)-1;                    \
        }                                       \
        else                                    \
        {                                       \
            return stack->items[stack->top];    \
        }                                       \
    }

#endif // STACK_H
