#include <stdio.h>
#define MAX_USERS 3

struct user {
    int id;
    char name[100];
    int bal;
};

// Function to credit a user's account
void credit(struct user* u, int amount) {
    u->bal += amount;
    printf("User %d credited with %d. New balance: %d\n", u->id, amount, u->bal);
}

// Function to debit a user's account
void debit(struct user* u, int amount) {
    if (u->bal >= amount) {
        u->bal -= amount;
        printf("User %d debited with %d. New balance: %d\n", u->id, amount, u->bal);
    } else {
        printf("User %d does not have enough balance to debit %d.\n", u->id, amount);
    }
}

int main() {
    struct user users[MAX_USERS];

    // Input user information
    for (int i = 0; i < MAX_USERS; i++) {
        printf("Enter the id for user %d: ", i + 1);
        scanf("%d", &users[i].id);
        printf("Enter the name for user %d: ", i + 1);
        scanf("%s", users[i].name);
        printf("Enter the initial balance for user %d: ", i + 1);
        scanf("%d", &users[i].bal);
    }

    // Perform credit and debit operations
    int userId, amount, operation;
    while (1) {
        printf("\nChoose operation:\n");
        printf("1. Credit\n");
        printf("2. Debit\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &operation);

        if (operation == 3) break;

        printf("Enter user id (1-%d): ", MAX_USERS);
        scanf("%d", &userId);

        if (userId < 1 || userId > MAX_USERS) {
            printf("Invalid user id! Try again.\n");
            continue;
        }

        printf("Enter amount: ");
        scanf("%d", &amount);

        if (operation == 1) {
            credit(&users[userId - 1], amount);  // Credit the selected user
        } else if (operation == 2) {
            debit(&users[userId - 1], amount);   // Debit the selected user
        } else {
            printf("Invalid operation! Try again.\n");
        }
    }

    // Display user balances at the end
    printf("\nFinal Balances:\n");
    for (int i = 0; i < MAX_USERS; i++) {
        printf("User %d (%s): Balance = %d\n", users[i].id, users[i].name, users[i].bal);
    }

    return 0;
}
