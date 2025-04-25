#include <stdio.h>

int main() {
    int arr[100], n, i, key, count = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            count++;
        }
    }
    printf("Key occurred %d times", count);
    return 0;
}


