#include <stdio.h>

int main() {
    int arr[10], i, oddCount = 0, evenCount = 0, elements[10] = {0};

    printf("Enter 10 integers: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 != 0) {
            oddCount++;
        } else {
            evenCount++;
        }
        
    }

    printf("Number of odd elements: %d\n", oddCount);
    printf("Number of even elements: %d\n", evenCount);

    

    return 0;
}