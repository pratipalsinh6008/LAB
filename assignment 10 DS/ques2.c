/*Given an array arr[], Sort the array using the selection sort algorithm.
Examples: Input: arr[] = [64, 25, 12, 22, 11]
Output: [11, 12, 22, 25, 64 ]*/

#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int minIndex, temp;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Main function
int main() {
    int n;

    // Taking user input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Taking user input for array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Displaying the original array
    printf("Original array: ");
    displayArray(arr, n);

    // Sorting the array using Selection Sort
    selectionSort(arr, n);

    // Displaying the sorted array
    printf("Sorted array: ");
    displayArray(arr, n);

    return 0;
}