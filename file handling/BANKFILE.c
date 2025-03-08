#include <stdio.h>
int main() {
    FILE *file;
    char type[10];
    float amount;
    file = fopen("Bank.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;}
    printf("Credit or Debit ");
    scanf("%s", type);
    printf("Enter amount: ");
    scanf("%f", &amount);
    fprintf(file, "%s: %.2f\n", type, amount);
    fclose(file);
    printf("Transaction success.\n");
    return 0; }


