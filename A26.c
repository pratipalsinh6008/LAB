#include <stdio.h>

int main() {
    int n, i, sumOdd = 0, sumEven = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sumEven += i;
        } else {
            sumOdd += i;
        }
    }

    printf("Sum of odd numbers: %d\n", sumOdd);
    printf("Sum of even numbers: %d\n", sumEven);

    return 0;
}