/*Given an array, arr[]. Sort the array using Insertion sort algorithm.
Examples : Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]*/

#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int key, j;

    for (int i = 1; i < n; i++) {
        key = arr[i];  // Store the current element
        j = i - 1;

        // Shift elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    // Sorting the array using Insertion Sort
    insertionSort(arr, n);

    // Displaying the sorted array
    printf("Sorted array: ");
    displayArray(arr, n);

    return 0;
}