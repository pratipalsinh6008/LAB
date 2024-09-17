#include <stdio.h>

int main() {
    int n;
    float x, y;

    printf("Enter the values of x and n: ");
    scanf("%f %d", &x, &n);

    if (n == 1) {
        y = 1 + x;
    } else if (n == 2) {
        y = 1 + x / n;
    } else if (n == 3) {
        y = 1 + x * n;
    } else if (n > 3 || n < 1) {
        y = 1 + n * x;
    } else {
        printf("Invalid value of n\n");
        return 1;
    }

    printf("Y(x, n) = %.2f\n", y);

    return 0;
}