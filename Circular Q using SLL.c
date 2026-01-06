#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node* NODE;

NODE enqueue(NODE front, NODE *rear);
NODE dequeue(NODE front, NODE *rear);
void displayQueue(NODE front, NODE rear);

int main() {
    NODE front = NULL, rear = NULL;
    int choice;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Enqueue (Circular Queue)\n");
        printf("2. Dequeue (Circular Queue)\n");
        printf("3. Display Circular Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                front = enqueue(front, &rear);
                break;
            case 2:
                front = dequeue(front, &rear);
                break;
            case 3:
                displayQueue(front, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Enqueue operation
NODE enqueue(NODE front, NODE *rear) {
    int item;
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return front;
    }
    printf("Enter item to enqueue: ");
    scanf("%d", &item);
    newNode->data = item;

    if (front == NULL) {
        front = newNode;
        *rear = newNode;
        newNode->next = front;  // circular link
    } else {
        newNode->next = front;   // new node points to front
        (*rear)->next = newNode; // old rear points to new node
        *rear = newNode;         // update rear
    }
    printf("%d enqueued into circular queue\n", item);
    return front;
}

// Dequeue operation
NODE dequeue(NODE front, NODE *rear) {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return front;
    }

    if (front == *rear) {  // only one node
        printf("Dequeued item: %d\n", front->data);
        free(front);
        front = NULL;
        *rear = NULL;
    } else {
        NODE temp = front;
        printf("Dequeued item: %d\n", temp->data);
        front = front->next;
        (*rear)->next = front;  // maintain circular link
        free(temp);
    }
    return front;
}

// Display operation
void displayQueue(NODE front, NODE rear) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    NODE temp = front;
    printf("Circular Queue (Front -> Rear): ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}