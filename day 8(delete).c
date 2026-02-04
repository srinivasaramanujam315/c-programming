#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int amount;
    struct Node* next;
} Node;

Node* createNode(int amount) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->amount = amount;
    newNode->next = NULL;
    return newNode;
}

void insertTransaction(Node** head, int amount) {
    Node* newNode = createNode(amount);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteLatestTransaction(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
}

void displayTransactions(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->amount);
        if (temp->next != NULL) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("->NULL\n");
}

void freeList(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    
    printf("Inserting transactions: 500, 1000\n");
    insertTransaction(&head, 500);
    insertTransaction(&head, 1000);
    
    printf("Transaction list before deletion: ");
    displayTransactions(head);
    
    printf("Deleting the latest transaction...\n");
    deleteLatestTransaction(&head);
    
    printf("Expected output: 500->NULL\n");
    printf("Actual output: ");
    displayTransactions(head);
    
    freeList(&head);
    
    return 0;
}