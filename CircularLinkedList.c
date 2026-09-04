#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

// Insert at end
void insert() {
    int value;
    struct Node *newNode;

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("Inserted successfully.\n");
}

// Delete from beginning
void deleteNode() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    if (temp == last) {
        last = NULL;
    } else {
        last->next = temp->next;
    }

    free(temp);
    printf("Deleted successfully.\n");
}

// Display list
void display() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first)\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
