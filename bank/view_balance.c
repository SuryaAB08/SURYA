#include "features.h"
#include<stdio.h>
#define max_user 2
struct user{
    int id;
    char name[50];
    float balance;
    char address[150];
};
struct user user[max_user];
void account_details(){
    int a,i;
    printf("\n enter the account ID to view current bank balance : ");
    scanf("%d",&a);
    for(i=0;i<max_user;i++){
        if(a==user[i].id){
            printf("\n ACCOUNT ID : %d",user[i].id);
            printf("\n ACCOUNTANT NAME - %s",user[i].name);
            printf("\n ACCOUNTANT RESIDENTIAL ADDRESS - %s",user[i].address);
            printf("\n CURRENT BANK BALANCE : %f\n",user[i].balance);
            return NULL;
        }
    }
    printf("no account exists to check account details\n");
    return NULL;
}
