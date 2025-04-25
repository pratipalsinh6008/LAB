#include <stdio.h>

int main() {
    float consumption, amount;

    printf("Enter the consumption in units: ");
    scanf("%f", &consumption);

    if (consumption <= 200) {
        amount = consumption * 0.50;
    } else if (consumption <= 400) {
        amount = 100 + (consumption - 200) * 0.65;
    } else if (consumption <= 600) {
        amount = 230 + (consumption - 400) * 0.80;
    } else {
        amount = 425 + (consumption - 600) * 1.25;
    }

    printf("Amount to be paid: Rs. %.2f\n", amount);

    return 0;
}