// Write a C program to implement two Stacks in an Array optimally

#include <stdio.h>
#include <stdlib.h>

typedef struct TwoStacks
{
    int *arr;
    int size;
    int top1, top2;
} TwoStacks;

void initialize(TwoStacks *ts, int n)
{
    ts->size = n;
    ts->arr = (int *)calloc(n, sizeof(int));
    ts->top1 = -1;
    ts->top2 = n;
}

void push1(TwoStacks *ts, int x)
{
    if (ts->top2 - ts->top1 > 1)
    {
        ts->top1++;
        ts->arr[ts->top1] = x;
    }
    else
    {
        printf("Stack1 Overflow!!!");
    }
}

void push2(TwoStacks *ts, int x)
{
    if (ts->top2 - ts->top1 > 1)
    {
        ts->top2--;
        ts->arr[ts->top2] = x;
    }
    else
    {
        printf("Stack2 Overflow!!!");
    }
}

int pop1(TwoStacks *ts)
{
    if (ts->top1 >= 0)
    {
        int x = ts->arr[ts->top1];
        ts->top1--;
        printf("\nPopped element from Stack 1");
        return x;
    }
    else
    {
        printf("Stack Underflow!!!");
        return -1;
    }
}

int pop2(TwoStacks *ts)
{
    if (ts->top2 < ts->size)
    {
        int x = ts->arr[ts->top2];
        ts->top2++;
        printf("\nPopped element from Stack 2");
        return x;
    }
    else
    {
        printf("Stack Underflow!!!");
        return -1;
    }
}

int main()
{
    int size = 0;
    TwoStacks ts;

    printf("Enter size of array: ");
    scanf("%d", &size);

    initialize(&ts, size);

    int choice, value;

    while (1)
    {
        printf("\n\nChoose operation:\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stacks\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push to Stack 1: ");
            scanf("%d", &value);
            push1(&ts, value);
            break;

        case 2:
            printf("Enter value to push to Stack 2: ");
            scanf("%d", &value);
            push2(&ts, value);
            break;

        case 3:
            pop1(&ts);
            break;

        case 4:
            pop2(&ts);
            break;

        case 5:
            printf("Stack 1: ");
            for (int i = 0; i <= ts.top1; i++)
                printf("%d ", ts.arr[i]);

            printf("\nStack 2: ");
            for (int i = ts.top2; i < ts.size; i++)
                printf("%d ", ts.arr[i]);

            printf("\n");
            break;

        case 6:
            free(ts.arr); // Free the dynamically allocated array before exiting
            exit(0);

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}