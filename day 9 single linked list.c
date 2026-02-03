#include <stdio.h>
#include<stdlib.h>
struct contact{
    long int number;
    struct contact *next;
    struct contact *previous;
};
int main() {
struct contact *ct1 = (struct contact*)malloc(sizeof(struct contact));
struct contact *ct2 = (struct contact*)malloc(sizeof(struct contact));
struct contact *ct3 = (struct contact*)malloc(sizeof(struct contact));
ct1->number = 9789941229;
ct2->number = 7845274004;
ct3->number = 8122120092;
ct1->previous = NULL;
ct1->next = ct2;
ct2->previous = ct1;
ct2->next = ct3;
ct3->previous = ct2;
ct3->next = NULL;
struct contact *head = ct1;
printf("Contact:\n");
while(head != NULL){
    printf("%ld<---->",head->number);
    head = head->next;
}
printf("Finish");
    return 0;
}