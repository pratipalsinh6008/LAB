// WRITE A C PROGRAM  USING POINTER TO COUNT THE NUMBERS OF WORDS IN A GIVEN STRING.
#include <stdio.h>
int main()
{
    char c[200];
    char *ptr;
    ptr = c;

    printf("Enter string=");
    gets(c);
    int word = 1;

    while (*ptr != '\0')
    {
        if (*ptr == ' ' && *(ptr + 1) != ' ')
        {
            word++;
        }
        ptr++;
    }

    printf("Number of words=%d", word);

    return 0;
}