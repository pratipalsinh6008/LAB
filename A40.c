#include <stdio.h>

int main() {
    int num, sum = 0;

    printf("Enter numbers (enter a negative number to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num < 0) {
            break;
        }
        sum += num;
    }

    printf("Sum of the entered numbers: %d\n", sum);

    return 0;
}

