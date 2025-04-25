//To separate odd and even integers in separate arrays

#include<stdio.h>
    int main(){
 int n;
    printf("Enter size of array=");
    scanf("%d", &n);

    int arr[n];
     printf("Enter elements of array=\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
  int even[n];
  int odd[n];
  int evenIndex=0,oddIndex=0;
  for (int i = 0; i < n; i++)
  {
   if(arr[i]%2==0){
    even[evenIndex]=arr[i];
    evenIndex++;
   }
   else{
     odd[oddIndex]=arr[i];
     oddIndex++;

   }
  }
  //print
  printf("Even numbers=");

  for (int i = 0; i < evenIndex; i++)
  {
           printf("%d ",even[i]);
  }
  
   printf("\n");
 printf("Odd numbers=");
 
  for (int i = 0; i < oddIndex; i++)
  {
           printf("%d ",odd[i]);
  }
  
        return 0;

    }