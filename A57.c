#include <stdio.h>

int main() {
    int n, i, max, secondMax;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = secondMax = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        } 
    }

    printf("Maximum element: %d\n", max);
    printf("Second maximum element: %d\n", secondMax);
 
 
  return 0;
}
