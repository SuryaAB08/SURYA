#include <stdio.h>

// Function prototype
int addNumbersExcludingCertainDigits();
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool isPrime(int num);
int addNumbersExcludingPrimes();

int main() {
    int result;

    // Call the function and store the result
    result = addNumbersExcludingPrimes();

    // Print the result
    printf("The sum of the first 100 numbers excluding prime numbers is: %d\n", result);

    return 0;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // Found a divisor, not prime
        }
    }
    return true; // Number is prime
}

// Function to add numbers excluding prime numbers
int addNumbersExcludingPrimes() {
    int sum = 0;

    // Loop through numbers from 1 to 100
    for (int i = 1; i <= 100; i++) {
        // Add number if it's not prime
        if (!isPrime(i)) {
            sum += i;
        }
    }

    return sum;
}

