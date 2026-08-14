#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert() {
    struct Node *newNode, *temp;
    int x;

    newNode = malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &x);

    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

void delete() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted\n");
}

void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
