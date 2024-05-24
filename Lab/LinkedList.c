#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList(int);
void insertAtBeginning();
void insertAtEnd();
void deleteFromLast();
void reverseLinks();
void display();

int main() {
    int choice = 0, num_of_nodes = 0;
    do {
        printf("\n------------- MENU -----------\n");
        printf("1. Create list\n2. Insert beginning\n3. Insert end\n4. Delete end\n5. Reverse\n6. Display\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter num of nodes: ");
                scanf("%d", &num_of_nodes);
                createList(num_of_nodes);
                break;
            case 2:
                insertAtBeginning();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                deleteFromLast();
                break;
            case 5:
                reverseLinks();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}

void createList(int num_of_nodes) {
    if (num_of_nodes <= 0) {
        printf("Enter a valid number (> 0)\n");
        return;
    }

    struct node *temp = NULL;
    for (int i = 0; i < num_of_nodes; i++) {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &ptr->data);
        ptr->next = NULL;

        if (head == NULL)
            head = ptr;
        else
            temp->next = ptr;

        temp = ptr;
    }
    printf("List created\n");
}

void insertAtBeginning() {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->next = head;
    head = ptr;
    printf("Node inserted\n");
}

void insertAtEnd() {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    if (head == NULL)
        head = ptr;
    else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
    printf("Node inserted\n");
}

void deleteFromLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted\n");
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    printf("Node deleted\n");
}

void reverseLinks() {
    struct node *prev = NULL;
    struct node *current = head;
    while (current != NULL) {
        struct node *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
    printf("Links reversed\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *ptr = head;
    printf("List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}