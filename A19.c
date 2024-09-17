#include <stdio.h>

int main() {
    char character;

    printf("Enter a character: ");
    scanf("%c", &character);

    if (character >= 'a' && character <= 'z') {
        printf("%c is a small case letter\n", character);
    } else {
        printf("%c is not a small case letter\n", character);
    }

    return 0;
}