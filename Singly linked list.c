#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node* NODE;

// Function prototypes
NODE insertFront(NODE first);
NODE insertRear(NODE first);
NODE deleteFront(NODE first);
NODE deleteRear(NODE first);
void display(NODE first);

NODE insertFront(NODE first) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Insufficient memory\n");
        return first;
    }
    printf("Enter element to be inserted: ");
    scanf("%d", &temp->info);
    temp->next = first;
    first = temp;
    return first;
}

NODE insertRear(NODE first) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Insufficient memory\n");
        return first;
    }
    printf("Enter element to be inserted: ");
    scanf("%d", &temp->info);
    temp->next = NULL;

    if (first == NULL) {
        return temp;
    }

    NODE cur = first;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = temp;
    return first;
}

NODE deleteFront(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    NODE temp = first;
    first = first->next;
    printf("Deleted element: %d\n", temp->info);
    free(temp);
    return first;
}

NODE deleteRear(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (first->next == NULL) {
        printf("Deleted element: %d\n", first->info);
        free(first);
        return NULL;
    }
    NODE cur = first;
    NODE prev = NULL;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }
    printf("Deleted element: %d\n", cur->info);
    free(cur);
    prev->next = NULL;
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE cur = first;
    printf("List elements: ");
    while (cur != NULL) {
        printf("%d -> ", cur->info);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main() {
    NODE first = NULL;
    int choice;
    while (1) {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: first = insertFront(first); break;
            case 2: first = insertRear(first); break;
            case 3: first = deleteFront(first); break;
            case 4: first = deleteRear(first); break;
            case 5: display(first); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
