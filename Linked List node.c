#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL;
    struct node *n1, *n2, *n3;

    n1 = (struct node*)malloc(sizeof(struct node));
    n2 = (struct node*)malloc(sizeof(struct node));
    n3 = (struct node*)malloc(sizeof(struct node));

    if (n1 == NULL || n2 == NULL || n3 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("n1=%p, address of n1 variable=%p\n", (void*)n1, (void*)&n1);
    printf("n2=%p, address of n2 variable=%p\n", (void*)n2, (void*)&n2);
    printf("n3=%p, address of n3 variable=%p\n", (void*)n3, (void*)&n3);

    head = n1;
    n1->data = 12;
    n1->next = n2;

    n2->data = 22;
    n2->next = n3;

    n3->data = 63;
    n3->next = NULL; // End of list

    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    free(n1);
    free(n2);
    free(n3);

    return 0;
}

