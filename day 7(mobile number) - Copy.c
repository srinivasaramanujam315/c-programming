#include <stdio.h>

struct structure{
   long int  mobnum;
    int amount;
} ;
int main(){
struct structure per1;
per1.mobnum=6369307659 ;
per1.amount=250 ;

printf("the mobnum is %ld and the amount is %d",per1.mobnum,per1.amount);


    return 0;
}