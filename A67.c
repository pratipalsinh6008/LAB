#include <stdio.h>

int main() {
    int matrix1[3][3], matrix2[3][3], difference[3][3], i, j;

    printf("Enter elements of the first 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of the second 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Subtract matrices
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

 printf("Difference of the two matrices:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", difference[i][j]);
        }
        printf("\n");
    }

    return 0;
}
