#include <stdio.h>

int main()
{
int n,r;
n = 3;
printf("enter any r ");
scanf("%d",&r);
if (n==r)
{
    printf("true\n");
}
else 
{
    printf("false \n");
}
while(n!=r)
{
    printf("enter the r ");
    scanf("%d",&r);
   
  }
 printf("num = %d");
}
    