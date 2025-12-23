#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node *next;
};

typedef struct node* NODE;

NODE insertRear(NODE first);
void display(NODE first);
NODE sortList(NODE first);
NODE reverseList(NODE first);
NODE concatenate(NODE first1, NODE first2);

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

NODE sortList(NODE first) {
    if (first == NULL || first->next == NULL) {
        return first;
    }
    NODE i, j;
    int temp;
    for (i = first; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
    printf("List sorted successfully\n");
    return first;
}

NODE reverseList(NODE first) {
    NODE prev = NULL, cur = first, next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    printf("List reversed successfully\n");
    return prev;
}

NODE concatenate(NODE first1, NODE first2) {
    if (first1 == NULL) return first2;
    if (first2 == NULL) return first1;

    NODE cur = first1;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = first2;
    printf("Lists concatenated successfully\n");
    return first1;
}

int main() {
    NODE first1 = NULL, first2 = NULL;
    int choice;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert into List1\n");
        printf("2. Insert into List2\n");
        printf("3. Display List1\n");
        printf("4. Display List2\n");
        printf("5. Sort List1\n");
        printf("6. Reverse List1\n");
        printf("7. Concatenate List1 and List2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: first1 = insertRear(first1); break;
            case 2: first2 = insertRear(first2); break;
            case 3: display(first1); break;
            case 4: display(first2); break;
            case 5: first1 = sortList(first1); break;
            case 6: first1 = reverseList(first1); break;
            case 7: first1 = concatenate(first1, first2);
                    printf("After concatenation, List1: ");
                    display(first1);
                    break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
