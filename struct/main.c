#include <stdio.h>

// Define a structure called 'User'
struct User {
    char name[50];
    int age;
    float balance;
};

int main() {
    int n;  // Number of users

    // Ask for the number of users
    printf("Enter the number of users: ");
    scanf("%d", &n);

    // Create an array of 'User' structures
    struct User users[n];

    // Input information for each user
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for user %d:\n", i + 1);

        // Input user's name
        printf("Enter your name: ");
        getchar();  // To consume the leftover newline character
        fgets(users[i].name, sizeof(users[i].name), stdin);  // Read name with spaces

        // Input user's age
        printf("Enter your age: ");
        scanf("%d", &users[i].age);

        // Input user's balance
        printf("Enter your account balance: ");
        scanf("%f", &users[i].balance);
    }

    // Display the information of all users
    printf("\nUser Information:\n");
    for (int i = 0; i < n; i++) {
        printf("\nUser %d:\n", i + 1);
        printf("Name: %s", users[i].name);  // Print name
        printf("Age: %d\n", users[i].age);  // Print age
        printf("Account Balance: %.2f\n", users[i].balance);  // Print balance
    }

    return 0;
}

