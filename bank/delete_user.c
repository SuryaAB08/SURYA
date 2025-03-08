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
int delete_user(){
    int a,i;
    printf("\n enter the account ID to be deleted : ");
    scanf("%d",&a);
    for(i=0;i<max_user;i++){
        if(a==user[i].id){
            user[i].id=NULL;
            printf("account successfully deleted\n");
            return 1;
        }
    }
    printf("no account created\n");
    return 0;
}

