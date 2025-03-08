#include <stdio.h>

// Function prototype
int addNumbersExcludingCertainDigits();

int main() {
    int result;

    // Call the function and store the result
    result = addNumbersExcludingCertainDigits();

    // Print the result
    printf("The sum of the first 100 numbers excluding those with last digit 3, 5, or 7 is: %d\n", result);

    return 0;
}

// Function definition
int addNumbersExcludingCertainDigits() {
    int sum = 0;

    // Loop through numbers from 1 to 100
    for (int i = 1; i <= 100; i++) {
        int lastDigit = i % 10;  // Get the last digit of the number

        // Check if the last digit is 3, 5, or 7
        if (lastDigit != 3 && lastDigit != 5 && lastDigit != 7) {
            sum += i;  // Add the number if it doesn't end in 3, 5, or 7
        }
    }
    return sum;
}
