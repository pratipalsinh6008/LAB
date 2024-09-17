#include <stdio.h>

int main() {
    int hours, minutes, seconds, totalSeconds;

    printf("Enter the time in hours, minutes, and seconds: ");
    scanf("%d %d %d", &hours, &minutes, &seconds);

    totalSeconds = (hours * 60 * 60) + (minutes * 60) + seconds;

    printf("The total number of seconds is: %d\n", totalSeconds);

    return 0;
}