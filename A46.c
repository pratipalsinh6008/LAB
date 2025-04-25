#include <stdio.h>
#include <stdbool.h>

int main() {
    // Hat size chart (circumference in inches, size)
    int hatSizes[][2] = {
        {6.5, 6.5},
        {6.75, 6.75},
        {7, 7},
        {7.25, 7.25},
        {7.5, 7.5},
        {7.75, 7.75},
        {7.875, 7.875}
    };

    int numSizes = sizeof(hatSizes) / sizeof(hatSizes[0]);

    float headCircumference;

    printf("Enter your head circumference in inches: ");
    scanf("%f", &headCircumference);

    bool found = false;
    for (int i = 0; i < numSizes; i++) {
        if (headCircumference >= hatSizes[i][0] && headCircumference < hatSizes[i][1]) {
            printf("Your hat size is %.2f\n", hatSizes[i][1]);
  found = true;
            break;
        }
    }

    if (!found) {
        printf("Your head circumference is outside the standard range.\n");
    }

    return 0;
}