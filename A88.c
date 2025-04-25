#include <stdio.h>
int main()
{
    int a[100], b[100], n;

    printf("Number of elements in array A and B = ");
    scanf("%d", &n);

    printf(" \nEnter Elements of Array A = ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int *p = &a[0];

    for (int i = 0; i < n; i++)
    {
        b[i] = *(p + i); // Copied from Array A
    }

    printf(" \nArray B Copied from Array A = ");

    for (int i = 0; i < n; i++)
    {
        printf("\n%d", b[i]);
    }

    return 0;
}