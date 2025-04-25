#include <stdio.h>

int main() {
    int numbers[10];
    int sum = 0;

    // Read 10 integers from the user
    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i]; // Add each number to the sum
    }

    // Print the sum
    printf("The sum of the numbers is: %d\n", sum);

    return 0;
}