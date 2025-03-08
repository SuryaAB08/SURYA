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
void debit_money(){
    int s,t;
    float amount;
    printf("\n enter the account ID to debit money : ");
    scanf("%d",&s);
    for(t=0;t<max_user;t++){
        if(s==user[t].id){
                printf("\n enter the amount to be debited : ");
                scanf("%f",&amount);
                if(amount<=user[t].balance){
                        user[t].balance=user[t].balance-amount;
                        printf("\n Rs%f is debited successfully \n The bank balance is Rs%f\n",amount,user[t].balance);
                        return;
                }else{
                    printf("!!WARNING!! amount is less in your account can't debit anymore!!");
                    return;
                }
        }
    }
    printf("no account created to debit amount");
    return;

}

