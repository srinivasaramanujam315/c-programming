#include <stdio.h>
#include <stdlib.h>


struct contact {
    long long phone;
};


struct customer {
    int accNo;
    struct contact c;
    struct customer *next;
};

int main() {
    int n, i;
    struct customer *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of customers: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct customer *)malloc(sizeof(struct customer));

        printf("\nEnter details for customer %d\n", i + 1);
        printf("Account Number: ");
        scanf("%d", &newNode->accNo);

        printf("Phone Number: ");
        scanf("%lld", &newNode->c.phone);

        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    
    printf("\nCustomer List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d - %lld -> ", temp->accNo, temp->c.phone);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}