#include <stdio.h>

int main() {
    int arr1[10], arr2[10], temp, i;

    printf("Enter 10 integers for the first array: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter 10 integers for the second array: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr2[i]);
    }

    // Swap the arrays
    for (i = 0; i < 10; i++) {
        temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }

    printf("Swapped arrays:\n");
    printf("First array: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n"); 
    
    printf("Second array: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
