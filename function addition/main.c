#include <stdio.h>

int add(int num1, int num2);

int main() {
    int num1, num2, result;


    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    result = add(num1, num2);

    printf("The sum of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
int add(int num1, int num2) {
    return num1 + num2;
}


