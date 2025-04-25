#include <stdio.h>

int main() {
    int N;

    printf("Enter a positive integer: ");
    scanf("%d", &N);

    printf("Factors of %d:\n", N);
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}

