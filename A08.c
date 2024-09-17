#include <stdio.h>

int main() {
    int seconds, days, hours, minutes;

    printf("Enter the number of seconds: ");
    scanf("%d", &seconds);

    days = seconds / (60 * 60 * 24);
    seconds %= (60 * 60 * 24);
    hours = seconds / (60 * 60);
    seconds %= (60 * 60);
    minutes = seconds / 60;
    seconds %= 60;

    printf("given seconds is equal to %d days, %d hours, %d minutes, and %d seconds\n", days, hours, minutes, seconds);

    return 0;
}