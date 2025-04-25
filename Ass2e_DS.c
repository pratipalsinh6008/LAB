/* An array contains both positive and negative numbers in random
 order. Rearrange the array elements so that all negative numbers
 appear before all positive numbers */

 #include <stdio.h>

void rearrangeArray(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left <= right) {
        
        if (arr[left] < 0) {
            left++;
        }
        
        else if (arr[right] > 0) {
            right--;
        }
       
        else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, -2, 3, -4, 5, -6, -7, 8} ;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    rearrangeArray(arr, size);

    printf("Rearranged array: ");
    printArray(arr, size);

    return 0;
}