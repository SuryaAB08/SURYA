#include <stdio.h>

int main() {
    int numDrinks;


    printf("Enter the number of drinks for the bachelor party: ");
    scanf("%d", &numDrinks);


    char drinks[numDrinks][50];


    printf("Enter the names of the drinks:\n");
    for (int i = 0; i < numDrinks; i++) {
        printf("Drink %d: ", i + 1);
        scanf(" %[^\n]s", drinks[i]);
    }


    printf("\nDrinks for the Bachelor Party:\n");
    for (int i = 0; i < numDrinks; i++) {
        printf("%d. %s\n", i + 1, drinks[i]);
    }

    return 0;
}
