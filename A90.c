// C program to find length of string
// using pointer
#include <stdio.h>

int string_length(char *given_string)
{

    int length = 0;
    while (*given_string != '\0')
    {
        length++;
        given_string++;
    }

    return length;
}

int main()
{

    char given_string[] = "pratipal";

    printf("Length of the String: %d",
           string_length(given_string));
    return 0;
}