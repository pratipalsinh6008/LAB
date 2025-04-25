#include <stdio.h>
int main()
{
    int a[100], n;

    printf("Enter N = ");
    scanf("%d", &n);

    printf(" \nEnter Integers = ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\n Integers Before Sorting = ");

    for (int i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }

    int *p = &a[0];

    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if ((*(p + j)) > (*(p + j + 1)))
            {
                int temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }

    int *q = &a[0];

    printf("\n Integers After Sorting = ");

    for (int i = 0; i < n; i++)
    {
        printf("\t%d", *(q + i));
    }

    return 0;
}