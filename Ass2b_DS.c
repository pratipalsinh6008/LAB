// To print all unique elements in an array

#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of array=");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array=\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int flag;

    printf("Unique elements =");
    for (int i = 0; i < n; i++)
    {
        flag = 1;

        for (int j = 0; j < n; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}