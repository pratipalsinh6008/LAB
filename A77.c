#include<stdio.h>
void palindrome(int a);
int main()
{
    int a;
    printf("Enter the Number = ");
    scanf("%d",&a);
    
    palindrome(a);
    
}

void palindrome(int a)
{
    int temp=a,b,c=0;
   while(a>0)
   {
       b=a%10;
       c= c*10 + b;
       a=a/10;
   }
   
  if(c==temp)
   {
       printf("\n Number is  Palindrome");
   }
   else
   {
       printf("\n Number is not Palindrome");
   }
}
