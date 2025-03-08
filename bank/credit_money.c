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
void credit_money(){
    int s,t;
    float amount;
    printf("\n enter the account ID to credit money : ");
    scanf("%d",&s);
    for(t=0;t<max_user;t++){
        if(s==user[t].id){
                printf("\n enter the amount to be credited : ");
                scanf("%f",&amount);
                user[t].balance=user[t].balance+amount;
                printf("\n Rs%f is credited successfully \n The bank balance is Rs%f\n",amount,user[t].balance);
                return;
        }
    }
    printf("no account created to credit amount");
    return;

}
