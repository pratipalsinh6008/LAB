#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int luckyNumber, guess, attempts = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random lucky number between 1 and 100
    luckyNumber = rand() % 100 + 1;

    printf("I've picked a random number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == luckyNumber) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        } else if (guess < luckyNumber) {
            printf("Your guess is too low.\n");
        } else {
            printf("Your guess is too high.\n");
        }
    } while (guess != luckyNumber);

    return 0;
}

