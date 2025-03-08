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
void update_user(int b){
    int a,d;
    for(a=0;a<max_user;a++){
            if(b==user[a].id){
                while(1){
                    printf("select the following to update\n");
                    printf("1.change user name\n 2.change residential address\n 3.exit : ");
                    scanf("%d",&d);
                    switch(d){
                    case 1:
                        printf("enter new user name : ");
                        scanf("%s",&user[a].name);
                        printf("successfully updated the name as %s\n",user[a].name);
                        break;
                    case 2:
                        printf("enter new residential address : ");
                        scanf("%s",&user[a].address);
                        printf("successfully updated the address as %s\n",user[a].address);
                        break;
                    case 3:
                        return;
                        break;
                    default:
                        printf("invalid choice");
                }
            }

    }
    else
        continue;
}
printf("no account is created to update!!\n");
}
