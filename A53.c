#include<stdio.h>
 
int  main()
{
    int i,j,n;
 
    printf("Enter no of lines of * to be printed\n");
    scanf("%d", &n);
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=n;i>=1;i--)
    {
        for(j=1; j<i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}