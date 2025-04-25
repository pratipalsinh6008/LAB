#include <stdio.h>

int main() {
    int arr[100], n, i, key, found = 0;
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
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Key found at index %d", i);
    } else {
        printf("Key not found");
    }
    return 0;
}
