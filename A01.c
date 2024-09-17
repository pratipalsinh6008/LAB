#include <stdio.h>

int main() {
    float principal, rate, time, interest;

    printf("Enter principal amount: ");
    scanf("%f", &principal);

    printf("Enter rate (in %): ");
    scanf("%f", &rate);

    printf("Enter time (in years): ");
    scanf("%f", &time);

    interest = (principal * rate * time) / 100;

    printf("Simple interest: %.2f\n", interest);

    return 0;
}