#include <stdio.h>

int main() {
    int matrix[3][3], i, j, sum;

    printf("Enter elements of the 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Sum of each row:\n");
    for (i = 0; i < 3; i++) {
        sum = 0;
        for (j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
        printf("Row %d: %d\n", i + 1, sum);
    }

    return 0;
}
