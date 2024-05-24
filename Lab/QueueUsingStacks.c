// Write a C program to implement Queue using two Stacks (push & pop operations)

#include <stdio.h>
#include <stdlib.h> // for exit(0)
#include "header/stack.h"

DEFINE_STACK_TYPE(int)

Stack S1, S2;

void enqueue(int x)
{
    push(&S1, x);
}

int dequeue()
{
    // removing element from Stack S1 until it is empty,
    // pushing to Stack S2
    while (!isEmpty(&S1))
    {
        push(&S2, pop(&S1));
    }
    int ans = pop(&S2);
    while (!isEmpty(&S2))
    {
        push(&S1, pop(&S2));
    }
    return ans;
}

void display()
{
    // Display elements in Stack S1
    for (int i = S1.top; i >= 0; i--)
    {
        printf("%d ", S1.items[i]);
    }

    printf("\n");
}

int main()
{
    initialize(&S1);
    initialize(&S2);

    do
    {
        printf("\nChoose what operation you want:-\n");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");

        int choice = 0;
        int data = 0;

        printf("\n\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter element: ");
            scanf("%d", &data);
            enqueue(data);
            printf("Element enqueued\n");
            break;
        case 2:
            printf("Element dequeued!\n");
            dequeue();
            break;
        case 3:
            printf("\nQueue : ");
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid input!!! Try again\n");
        }

    } while (1);

    return 0;
}