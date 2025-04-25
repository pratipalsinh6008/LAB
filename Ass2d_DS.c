// To accept two matrices and check whether they are equal

#include <stdio.h>
int main()
{
    printf("Enter the rows and columns of first matrix\n");
    int n1;
    printf("Enter number of rows=");
    scanf("%d", &n1);
    int m1;
    printf("Enter number of columns=");
    scanf("%d ", &m1);

    int arr[n1][m1];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Enter the rows and columns of second matrix\n");
    int n2;
    printf("Enter number of rows=");
    scanf("%d", &n2);
    int m2;
    printf("Enter number of columns=");
    scanf("%d", &m2);

    int brr[n2][m2];
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            scanf("%d", &brr[i][j]);
        }
    }
    if (n1 != n2 || m1 != m2)
    {
        printf("Matrix dimension are not equal");
        return 0;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            if (arr[i][j] != brr[i][j])
            {
                printf("Matrix are not equal");
                return 0;
            }
           
        }
    }
     
            
                printf("Matrix are equal");
            

    return 0;
}