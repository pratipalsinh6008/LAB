#include<stdio.h>
int x,n;
int rotate(int a[]);
int factor(int a[] , int n );
int main()
{
    printf("Enter the size of array = ");
    scanf("%d",&x);

    printf("Enter factor to rotate the array = ");
    scanf("%d",&n);

    int a[x];

    printf("\nEnter Array = ");
    
    for(int i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\n Unrotated array = ");

    for(int i=0;i<5;i++)
    {
        printf("\n%d",a[i]);
    }

    //rotate(a);

    factor(a,n);

    printf("\n Rotated array = ");

    for(int i=0;i<5;i++)
    {
        printf("\n%d",a[i]);
    }

}

int factor(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        rotate(a);
    }
}

int rotate(int a[])
{
    int z = a[x-1];

    for(int i=x-2;i>=0;i--)
    {
        a[i+1]=a[i];
    }

    a[0]=z;
}