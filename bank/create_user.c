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
int create_user(int a){
    int i=a;
    if(i<max_user){
          printf("enter your new user ID : ");
          scanf("%d",&user[i].id);
          printf("\nenter your name : ");
          scanf("%s",&user[i].name);
          printf("\nenter your residential address - ");
          scanf("%s",&user[i].address);
          printf("\nenter your bank balance : ");
          scanf("%f",&user[i].balance);
          return i+1;

}
else{
        printf("maximum user already registered! can't create an account\n");
        return max_user;

}



}
