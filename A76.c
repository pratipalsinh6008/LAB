#include<stdio.h>
void evenodd(int a);
int main()
{
    int a;
    printf("Enter the Number = ");
    scanf("%d",&a);
    
    evenodd(a);
    
}

void evenodd(int a)
{
    if(a%2==0)
    {
        printf("Number is Even");
    }
    
    else
    {
        printf("Number is Odd");
    }
}