/*Write a C program to hold two integer pointers as structure members. Allocate space
for the structure and its data members during runtime. Get one array as input. In the
second array copy the elements of the first array and replace the odd positioned
elements by the product of its adjacent elements. Access the array elements and
structures using pointers instead of subscript notation.
First Array (Input)
1 2 3 4 5 6
Second Array (Input)
1 3 3 15 5 6
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure with two integer pointers
typedef struct {
    int *array1;
    int *array2;
} Arrays;

int main() {
    int n;

    // Prompt user for the size of the arrays
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the structure
    Arrays *arrays = (Arrays *)malloc(sizeof(Arrays));
    if (arrays == NULL) {
        printf("Memory allocation failed for structure.\n");
        return 1;
    }

    // Dynamically allocate memory for the two arrays
    arrays->array1 = (int *)malloc(n * sizeof(int));
    arrays->array2 = (int *)malloc(n * sizeof(int));
    if (arrays->array1 == NULL || arrays->array2 == NULL) {
        printf("Memory allocation failed for arrays.\n");
        free(arrays);
        return 1;
    }

    // Input elements for the first array
    printf("Enter %d elements for the first array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (arrays->array1 + i));
    }

    // Process the second array
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { // Even index (odd position)
            if (i == 0) {
                *(arrays->array2 + i) = *(arrays->array1 + i) * *(arrays->array1 + i + 1);
            } else if (i == n - 1) {
                *(arrays->array2 + i) = *(arrays->array1 + i - 1) * *(arrays->array1 + i);
            } else {
                *(arrays->array2 + i) = *(arrays->array1 + i - 1) * *(arrays->array1 + i + 1);
            }
        } else { // Odd index (even position)
            *(arrays->array2 + i) = *(arrays->array1 + i);
        }
    }

    // Display the second array
    printf("Second array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arrays->array2 + i));
    }
    printf("\n");

    // Free allocated memory
    free(arrays->array1);
    free(arrays->array2);
    free(arrays);

    return 0;
}