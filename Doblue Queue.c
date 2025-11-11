#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 10

int queue[SIZE];
int rear = SIZE / 2, front = SIZE / 2;

void enQueueRear() {
    int value;
    char ch;
    if (front == SIZE) {
        printf("\nQueue is full at rear");
        return;
    }
    do {
        printf("\nEnter the value to be inserted at rear: ");
        scanf("%d", &value);
        queue[front] = value;
        front++;
        printf("Do you want to continue insertion Y/N: ");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
}

void enQueueFront() {
    int value;
    char ch;
    if (rear == 0) {
        printf("\nQueue is full at front");
        return;
    }
    do {
        printf("\nEnter the value to be inserted at front: ");
        scanf("%d", &value);
        rear--;
        queue[rear] = value;
        printf("Do you want to continue insertion Y/N: ");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
}

int deQueueRear() {
    int deleted;
    if (front == rear) {
        printf("\nQueue is empty");
        return 0;
    }
    front--;
    deleted = queue[front];
    return deleted;
}

int deQueueFront() {
    int deleted;
    if (front == rear) {
        printf("\nQueue is empty");
        return 0;
    }
    deleted = queue[rear];
    rear++;
    return deleted;
}

void display() {
    int i;
    if (front == rear) {
        printf("\nQueue is empty");
    } else {
        printf("\nQueue elements are: ");
        for (i = rear; i < front; i++) {
            printf("%d\t", queue[i]);
        }
    }
}

int main() {
    char ch;
    int choice1, choice2, value;

    printf("\n****Type of double ended queue****\n");
    do {
        printf("\n1.Input-restricted deque");
        printf("\n2.Output-restricted deque");
        printf("\nEnter your choice of queue type: ");
        scanf("%d", &choice1);

        switch (choice1) {
        case 1:
            do {
                printf("\nSelect the operation");
                printf("\n1.Insert");
                printf("\n2.Delete from rear");
                printf("\n3.Delete from front");
                printf("\n4.Display\n");
                scanf("%d", &choice2);

                switch (choice2) {
                case 1:
                    enQueueRear();
                    display();
                    break;
                case 2:
                    value = deQueueRear();
                    printf("\nThe value deleted is %d", value);
                    display();
                    break;
                case 3:
                    value = deQueueFront();
                    printf("\nThe value deleted is %d", value);
                    display();
                    break;
                case 4:
                    display();
                    break;
                default:
                    printf("Wrong choice");
                }

                printf("\nDo you want to perform another operation (Y/N): ");
                ch = getch();
            } while (ch == 'y' || ch == 'Y');
            break;

        case 2:
            do {
                printf("\nSelect the operation");
                printf("\n1.Insert at rear");
                printf("\n2.Insert at front");
                printf("\n3.Delete");
                printf("\n4.Display\n");
                scanf("%d", &choice2);

                switch (choice2) {
                case 1:
                    enQueueRear();
                    display();
                    break;
                case 2:
                    enQueueFront();
                    display();
                    break;
                case 3:
                    value = deQueueFront();
                    printf("\nThe value deleted is %d", value);
                    display();
                    break;
                case 4:
                    display();
                    break;
                default:
                    printf("Wrong choice");
                }

                printf("\nDo you want to perform another operation (Y/N): ");
                ch = getch();
            } while (ch == 'y' || ch == 'Y');
            break;

        default:
            printf("Invalid queue type");
        }

        printf("\nDo you want to choose another queue type (Y/N): ");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
