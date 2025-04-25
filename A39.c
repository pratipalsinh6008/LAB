#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int N;

    printf("Enter a positive integer: ");
    scanf("%d", &N);

    printf("Series sum from 1 to %d:\n", N);
    double sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += (double)i / factorial(i);
    }
    printf("%.2f\n", sum);

    return 0;
}