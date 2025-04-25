// To merge two arrays of the same size sorted in descending order
#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of array=");
    scanf("%d", &n);

    int arr[n];
    int brr[n];
    int merged[2 * n];

    printf("Enter elements of first array=\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter elements of second array=\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &brr[i]);
    }


    for (int i = 0; i < n; i++)
    {
        merged[i] = arr[i];
    }

  
    for (int j = 0; j < n; j++)
    {
        merged[n + j] = brr[j];
    }
for (int i = 0; i < (2*n)-1; i++)
{
    for (int j = 0; j < (2*n)-1-i; j++)
    {
        if(merged[j]<merged[j+1]){
            int temp=merged[j];
            merged[j]=merged[j+1];
            merged[j+1]=temp;

        }
    }
    
}
//print
for (int i = 0; i < 2*n; i++)
{
  printf("%d ",merged[i]);
} 


    

    return 0;
}