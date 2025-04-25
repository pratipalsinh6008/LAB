/*Given an array arr[], Sort the array using the Quick sort algorithm.
Examples: Input: arr[] = [64, 25, 12, 22, 11]
Output: [11, 12, 22, 25, 64 ]*/

#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to divide the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;       // Pointer for the smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to display the array
void displayArray(int arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");
}

// Main function
int main()
{
    int n;

    // Taking user input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Taking user input for array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Displaying the original array
    printf("Original array: ");
    displayArray(arr, n);

    // Sorting the array using Quick Sort
    quickSort(arr, 0, n - 1);

    // Displaying the sorted array
    printf("Sorted array: ");
    displayArray(arr, n);

    

    return 0;
}