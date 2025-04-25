#include <stdio.h>

int main() {
    int N;

    printf("Enter a positive integer: ");
    scanf("%d", &N);

    printf("Odd numbers from 1 to %d:\n", N);
    for (int i = 1; i <= N; i += 2) {
        printf("%d ", i);
    }

    return 0;
}

