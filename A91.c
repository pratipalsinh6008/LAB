// WRITE A PROGRAM TO CALCULATE THE SQUARE AND CUBE OF AN ENTERED NUMBER USING
// POINTER OF A VARIABLE CONTAINING THE ENTERED NUMBER.
#include <stdio.h>
int main()
{
    int a;

    printf("Enter the Number = ");
    scanf("%d", &a);

    int *p = &a;

    printf("\nSqure of the number = %d", (*p) * (*p));

    printf("\nCube of the number = %d", (*p) * (*p) * (*p));

    return 0;
}