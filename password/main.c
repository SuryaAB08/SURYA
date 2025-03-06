#include <stdio.h>
#include<string.h>

void main()
{
char username[50],pass[50];
printf("enter the username = ");
scanf("%s",username);

printf("enter any password = ");
scanf("%s",pass);
if(strcmp(pass,username)==0)
{
    printf("correct \n");

}
else
{
 printf("not correct \n");
}
while(strcmp(pass,username)!=0)
{
    printf("enter the password");
    scanf("%s",pass);

  }
 printf("pass = %s \n");
}

