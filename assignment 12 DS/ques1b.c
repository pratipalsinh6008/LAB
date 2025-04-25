#include <stdio.h>
#include <stdlib.h>

void merge(float arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    float L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortIterative(float arr[], int n) {
    int width, left_start;
    for (width = 1; width < n; width *= 2) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * width) {
            int mid = left_start + width - 1;
            int right_end = (left_start + 2 * width - 1 < n - 1) ? (left_start + 2 * width - 1) : (n - 1);
            if (mid < right_end)
                merge(arr, left_start, mid, right_end);
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    mergeSortIterative(arr, n);

    printf("Sorted array (Iterative Merge Sort):\n");
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);
    return 0;
}