#include <stdio.h>

int main() {
    int numDrinks;

    // Ask user for the number of drinks
    printf("Enter the number of drinks for the bachelor party: ");
    scanf("%d", &numDrinks);

    // Declare an array of strings to store the drink names
    char drinks[numDrinks][50];  // Array to store 'numDrinks' strings of maximum length 50

    // Get drink names from the user
    printf("Enter the names of the drinks:\n");
    for (int i = 0; i < numDrinks; i++) {
        printf("Drink %d: ", i + 1);
        scanf(" %[^
]s", drinks[i]);  // Using " %[^
]s" to allow spaces in drink names
    }

    // Display the list of drinks
    printf("\nDrinks for the Bachelor Party:\n");
    for (int i = 0; i < numDrinks; i++) {
        printf("%d. %s\n", i + 1, drinks[i]);
    }

    return 0;
}
