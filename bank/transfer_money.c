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
void transfer_money(){
    int a,b,i;
    float amount;
    printf("\n enter the account ID to transfer amount from : ");
    scanf("%d",&a);
    printf("\n enter the account ID to receive amount to : ");
    scanf("%d",&b);
    printf("\n enter the amount to be transferred : ");
    scanf("%f",&amount);
    for(i=0;i<max_user;i++){
        if(a==user[i].id){
            if(amount<=user[i].balance){
                    user[i].balance-=amount;
                    break;
            }else{
                printf("\n amount to be transferred is much greater than the balance!!\n");
                return NULL;
            }
        }
    }
    if(i==max_user){
        printf("\n no account exists to transfer amount, create account first\n");
        return NULL;
    }else{
        for(i=0;i<max_user;i++){
            if(b==user[i].id){
                user[i].balance+=amount;
                printf("\n Rs%f is successfully transferred from account ID %d to account ID %d\n ",amount,a,b);
                return NULL;
            }
        }
        printf("no account found to receive amount\n");
        return NULL;
    }

}
