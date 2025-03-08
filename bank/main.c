#include <stdio.h>
#include<stdlib.h>
#define max_user 2
#include "features.h"
struct user{
    int id;
    char name[50];
    float balance;
    char address[150];
};
struct user user[max_user];
void main(){
    int choice,a=0,b;
    while(1){
        printf("select one of the following\n");
        printf("1.create user\n 2.update user\n 3.delete user\n 4.credit money\n 5.debit money\n 6.transfer money\n 7.view account details\n 8.exit\n");
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            a=create_user(a);
            break;
        case 2:
            printf("\n enter the user ID to update the account : ");
            scanf("%d",&b);
            update_user(b);
            break;
        case 3:
            b=delete_user();
            a=b-1;
            printf("current number of accounts registered is %d\n",a+1);
            break;
        case 4:
            credit_money();
            break;
        case 5:
            debit_money();
            break;
        case 6:
            transfer_money();
            break;
        case 7:
            account_details();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("invalid choice");
        }
    }
}
