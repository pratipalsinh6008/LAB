#include <stdio.h>

int main() {
    int N;

    printf("Enter a positive integer: ");
    scanf("%d", &N);

    printf("Squares from 1 to %d:\n", N);
    for (int i = 1; i <= N; i++) {
        printf("%d ", i * i);
    }

    return 0;
}
