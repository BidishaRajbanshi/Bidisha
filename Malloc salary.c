#include<stdio.h>
#include<stdlib.h>

struct Employee {
     int id;
     char name[50];
     float salary;
     };

int main() {
    int N, i;
    float total = 0;
    printf("Enter number of employees: ");
    scanf("%d", &N);

    struct Employee *emp = (struct Employee *)malloc(N * sizeof(struct Employee));
    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        printf("\nEnter details of employee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Monthly Salary: ");
        scanf("%f", &emp[i].salary);

        total += emp[i].salary * 12;
    }

    printf("\nTotal Annual Salary Expenditure: %.2f\n", total);
    free(emp);
    return 0;
}



