// program to findout max and secondmax from N numbers
#include <stdio.h>
int main()
{
    int x; // variablr for total number of element input
    printf("enter how many number input:");
    scanf("%d", &x);
    int arr[x];
    for (int i = 0; i < x; i++)
    {
        printf("\nenter the number:");
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for (int i = 1; i < x; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int secmax = arr[0];
    for (int i = 1; i < x; i++)
    {
        if (max > arr[i] && arr[i] > secmax)
        {
            secmax = arr[i];
        }
    }
    printf(" \nmax number is %d",max);
    printf("\nsecmax number is %d",secmax);
    return 0;
}