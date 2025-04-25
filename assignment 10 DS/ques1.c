/*Given an array, arr[]. Sort the array using bubble sort algorithm.
Examples : Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]*/

#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int temp;
    int swapped; // To optimize the sorting process

    for (int i = 0; i < n - 1; i++) {
        swapped = 0;  // Reset swapped flag

        // Last i elements are already sorted, so no need to check them
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { 
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Mark swap happened
            }
        }

        // If no swapping happened in this pass, the array is already sorted
        if (swapped == 0)
            break;
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

    // Sorting the array using Bubble Sort
    bubbleSort(arr, n);

    // Displaying the sorted array
    printf("Sorted array: ");
    displayArray(arr, n);

    return 0;
}
