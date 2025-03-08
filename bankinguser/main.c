#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for User
struct User {
    int user_id;
    char name[100];
    double balance;
    char address[200];  // Add address field
};

// Function to create a new user
void create_user(struct User** users, int* num_users) {
    // Dynamically allocate memory for one more user
    *users = realloc(*users, (*num_users + 1) * sizeof(struct User));

    printf("Enter user ID: ");
    scanf("%d", &(*users)[*num_users].user_id);
    printf("Enter user name: ");
    scanf(" %[^\n]", (*users)[*num_users].name);  // Read full name with spaces
    printf("Enter initial balance: ");
    scanf("%lf", &(*users)[*num_users].balance);
    printf("Enter user address: ");
    scanf(" %[^\n]", (*users)[*num_users].address);  // Read full address with spaces

    (*num_users)++;  // Increase the number of users
    printf("User %s created with balance $%.2f and address: %s.\n", (*users)[*num_users - 1].name, (*users)[*num_users - 1].balance, (*users)[*num_users - 1].address);
}

// Function to update user's details (name, balance, and address)
void update_user(struct User* users, int num_users) {
    int user_id, found = 0;
    printf("Enter user ID to update: ");
    scanf("%d", &user_id);

    for (int i = 0; i < num_users; i++) {
        if (users[i].user_id == user_id) {
            found = 1;
            printf("Enter new name: ");
            scanf(" %[^\n]", users[i].name);
            printf("Enter new balance: ");
            scanf("%lf", &users[i].balance);
            printf("Enter new address: ");
            scanf(" %[^\n]", users[i].address);
            printf("User %s updated: Balance: $%.2f, Address: %s.\n", users[i].name, users[i].balance, users[i].address);
            break;
        }
    }

    if (!found) {
        printf("User ID %d not found.\n", user_id);
    }
}

// Function to delete a user
void delete_user(struct User** users, int* num_users) {
    int user_id, found = 0;
    printf("Enter user ID to delete: ");
    scanf("%d", &user_id);

    for (int i = 0; i < *num_users; i++) {
        if ((*users)[i].user_id == user_id) {
            found = 1;
            // Shift all elements after the deleted user to the left
            for (int j = i; j < *num_users - 1; j++) {
                (*users)[j] = (*users)[j + 1];
            }
            // Reallocate memory to shrink the array
            *users = realloc(*users, (*num_users - 1) * sizeof(struct User));
            (*num_users)--;  // Decrease the number of users
            printf("User ID %d deleted.\n", user_id);
            break;
        }
    }

    if (!found) {
        printf("User ID %d not found.\n", user_id);
    }
}

// Function to credit money to a user's account
void credit_money(struct User* users, int num_users) {
    int user_id, found = 0;
    double amount;
    printf("Enter user ID to credit money: ");
    scanf("%d", &user_id);
    printf("Enter amount to credit: ");
    scanf("%lf", &amount);

    for (int i = 0; i < num_users; i++) {
        if (users[i].user_id == user_id) {
            found = 1;
            if (amount > 0) {
                users[i].balance += amount;
                printf("Credited $%.2f to User %s. New Balance: $%.2f\n", amount, users[i].name, users[i].balance);
            } else {
                printf("Amount to credit must be positive.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("User ID %d not found.\n", user_id);
    }
}

// Function to debit money from a user's account
void debit_money(struct User* users, int num_users) {
    int user_id, found = 0;
    double amount;
    printf("Enter user ID to debit money: ");
    scanf("%d", &user_id);
    printf("Enter amount to debit: ");
    scanf("%lf", &amount);

    for (int i = 0; i < num_users; i++) {
        if (users[i].user_id == user_id) {
            found = 1;
            if (amount > 0 && users[i].balance >= amount) {
                users[i].balance -= amount;
                printf("Debited $%.2f from User %s. New Balance: $%.2f\n", amount, users[i].name, users[i].balance);
            } else {
                printf("Insufficient balance or invalid amount.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("User ID %d not found.\n", user_id);
    }
}

// Function to transfer money between two users
void transfer_money(struct User* users, int num_users) {
    int from_user_id, to_user_id, found_from = 0, found_to = 0;
    double amount;
    printf("Enter from user ID: ");
    scanf("%d", &from_user_id);
    printf("Enter to user ID: ");
    scanf("%d", &to_user_id);
    printf("Enter amount to transfer: ");
    scanf("%lf", &amount);

    for (int i = 0; i < num_users; i++) {
        if (users[i].user_id == from_user_id) {
            found_from = 1;
        }
        if (users[i].user_id == to_user_id) {
            found_to = 1;
        }
    }

    if (found_from && found_to) {
        for (int i = 0; i < num_users; i++) {
            if (users[i].user_id == from_user_id) {
                if (amount > 0 && users[i].balance >= amount) {
                    users[i].balance -= amount;
                    printf("Transferred $%.2f from %s. New balance for %s: $%.2f\n", amount, users[i].name, users[i].name, users[i].balance);
                } else {
                    printf("Insufficient balance or invalid amount.\n");
                }
            }
            if (users[i].user_id == to_user_id) {
                users[i].balance += amount;
                printf("Transferred $%.2f to %s. New balance for %s: $%.2f\n", amount, users[i].name, users[i].name, users[i].balance);
            }
        }
    } else {
        if (!found_from) {
            printf("From user ID %d not found.\n", from_user_id);
        }
        if (!found_to) {
            printf("To user ID %d not found.\n", to_user_id);
        }
    }
}

int main() {
    struct User* users = NULL;  // Pointer to store users dynamically
    int num_users = 0;  // Variable to track number of users
    int choice;

    do {
        // Display menu
        printf("\nBanking System Menu:\n");
        printf("1. Create User\n");
        printf("2. Credit Money\n");
        printf("3. Debit Money\n");
        printf("4. Transfer Money\n");
        printf("5. Update User\n");
        printf("6. Delete User\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_user(&users, &num_users);  // Create a new user
                break;
            case 2:
                credit_money(users, num_users);  // Credit money to a user
                break;
            case 3:
                debit_money(users, num_users);  // Debit money from a user
                break;
            case 4:
                transfer_money(users, num_users);  // Transfer money between two users
                break;
            case 5:
                update_user(users, num_users);  // Update user details
                break;
            case 6:
                delete_user(&users, &num_users);  // Delete a user
                break;
            case 7:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    // Free allocated memory for users
    free(users);

    return 0;
}
