#include <stdio.h>

// Function prototype
int addFirstFiveNumbers();

int main() {
    int result;

    // Call the addFirstFiveNumbers function and store the result
    result = addFirstFiveNumbers();

    // Print the result
    printf("The sum of the first 5 numbers (1 + 2 + 3 + 4 + 5) is: %d\n", result);

    return 0;
}

// Function definition
int addFirstFiveNumbers() {
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += i;  // Add numbers from 1 to 5
    }
    return sum;
}

