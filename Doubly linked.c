#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink;  
    struct node *rlink;   
};
typedef struct node* NODE;

NODE insertFront(NODE first);
NODE insertRear(NODE first);
NODE deleteFront(NODE first);
NODE deleteRear(NODE first);
void display(NODE first);

int main() {
    NODE first = NULL;
    int choice;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                first = insertFront(first);
                break;
            case 2:
                first = insertRear(first);
                break;
            case 3:
                first = deleteFront(first);
                break;
            case 4:
                first = deleteRear(first);
                break;
            case 5:
                display(first);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

NODE insertFront(NODE first) {
    int item;
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return first;
    }
    printf("Enter the item to insert at front: ");
    scanf("%d", &item);
    newNode->info = item;
    newNode->llink = NULL;
    newNode->rlink = first;

    if (first != NULL) {
        first->llink = newNode;
    }
    return newNode;
}

NODE insertRear(NODE first) {
    int item;
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return first;
    }
    printf("Enter the item to insert at rear: ");
    scanf("%d", &item);
    newNode->info = item;
    newNode->rlink = NULL;

    if (first == NULL) {
        newNode->llink = NULL;
        return newNode;
    }

    NODE temp = first;
    while (temp->rlink != NULL) {
        temp = temp->rlink;
    }
    temp->rlink = newNode;
    newNode->llink = temp;
    return first;
}

NODE deleteFront(NODE first) {
    if (first == NULL) {
        printf("List is empty. Cannot delete from front.\n");
        return first;
    }
    NODE temp = first;
    first = first->rlink;
    if (first != NULL) {
        first->llink = NULL;
    }
    printf("Deleted item from front: %d\n", temp->info);
    free(temp);
    return first;
}

NODE deleteRear(NODE first) {
    if (first == NULL) {
        printf("List is empty. Cannot delete from rear.\n");
        return first;
    }
    NODE temp = first;
    if (temp->rlink == NULL) {
        printf("Deleted item from rear: %d\n", temp->info);
        free(temp);
        return NULL;
    }
    while (temp->rlink != NULL) {
        temp = temp->rlink;
    }
    printf("Deleted item from rear: %d\n", temp->info);
    temp->llink->rlink = NULL;
    free(temp);
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    NODE temp = first;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->rlink;
    }
    printf("\n");
}
