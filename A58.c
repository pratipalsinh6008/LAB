#include <stdio.h>

int main() {
    int arr1[10], arr2[10], arr3[10], i;

    printf("Enter 10 integers for the first array: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter 10 integers for the second array: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr2[i]);
    }

    for (i = 0; i < 10; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }

    printf("Addition of the two arrays: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}
