#include <stdio.h>

int main() {
    int totalSeconds, hours, minutes, seconds;

    printf("Enter the total number of seconds: ");
    scanf("%d", &totalSeconds);

    hours = totalSeconds / (60 * 60);
    totalSeconds %= (60 * 60);
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;

    printf("%d seconds is equal to %d hours, %d minutes, and %d seconds\n", totalSeconds, hours, minutes, seconds);

    return 0;
}