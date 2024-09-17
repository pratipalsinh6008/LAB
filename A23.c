#include <stdio.h>

int main() {
    int base, exponent, result = 1;

    printf("Enter the base number: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    if (exponent < 0) {
        printf("Exponent cannot be negative\n");
    } else {
        for (int i = 1; i <= exponent; i++) {
            result *= base;
        }
        printf("%d raised to the power of %d is %d\n", base, exponent, result);
    }

    return 0;
}