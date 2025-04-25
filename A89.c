// WRITE A PROGRAM  TO COPY  ONE ARRAY INTO ANOTHER ARRAY .ORDER OF ELEMENTS OF
// SECOND ARRAY SHOULD BE OPPOSITE TO FIRST ARRAY.

#include <stdio.h>
int main()
{
    int n;

    printf("Enter a number=");
    scanf("%d", &n);
    int arr[n];
    int brr[n];

    int *ptr1;
    int *ptr2;
    ptr1 = arr;
    ptr2 = brr;

    printf("Enter elements=\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr1 + i);
    }
    printf("first array=\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr1 + i));
    }

    for (int i = 0; i < n; i++)
    {
        *(ptr2 + i) = *(ptr1 + n - i - 1);
    }
    printf("Second array=");

    printf("\nsecond array=\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr2 + i));
    }

    return 0;
}