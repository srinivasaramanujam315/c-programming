#include <stdio.h>
#include<stdlib.h>
struct rollno{
    int number;
    struct rollno *next ;
} ;
int main() {
struct rollno*no1 = (struct rollno*)malloc(sizeof(struct rollno));
struct rollno*no2 = (struct rollno*)malloc(sizeof(struct rollno));

scanf("%d\n",&no1->number);
scanf("%d\n",&no2->number);

no1->next = no2;

no2->next = NULL;
struct rollno *head = no1;
while(head != NULL){
    printf("Roll %d -> ",head->number);
    head = head->next;
}
printf("NULL");
    return 0;
}