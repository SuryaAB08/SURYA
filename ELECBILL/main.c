#include <stdio.h>

void calculate_bill(int consumption, char customer_name[], char customer_id[]) {

    int fixed_charge = 100;


    int rate_1 = 5;
    int rate_2 = 7;
    int rate_3 = 10;

    float bill = 0;

    if (consumption <= 100) {
        bill = fixed_charge + (consumption * rate_1);
    } else if (consumption <= 300) {
        bill = fixed_charge + (100 * rate_1) + ((consumption - 100) * rate_2);
    } else {
        bill = fixed_charge + (100 * rate_1) + (200 * rate_2) + ((consumption - 300) * rate_3);
    }


    if (bill > 1000) {
        float surcharge = bill * 0.05;
        bill += surcharge;
    }


    printf("\nCustomer Details:\n");
    printf("Customer Name: %s\n", customer_name);
    printf("Customer ID: %s\n", customer_id);
    printf("Total Consumption: %d units\n", consumption);
    printf("Total Bill: %.2f rupees\n", bill);
}

int main() {
    char customer_name[50];
    char customer_id[20];
    int consumption;


    printf("Enter customer name: ");
    fgets(customer_name, sizeof(customer_name), stdin);
    customer_name[strcspn(customer_name, "\n")] = 0;
    printf("Enter customer ID: ");
    fgets(customer_id, sizeof(customer_id), stdin);
    customer_id[strcspn(customer_id, "\n")] = 0;
    printf("Enter total consumption (in units): ");
    scanf("%d", &consumption);


    calculate_bill(consumption, customer_name, customer_id);

    return 0;
}
