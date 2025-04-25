#include <stdio.h>

struct Employee
{
  int empNumber;
  char name[50];
  float basicPay;
};

int main()
{
  struct Employee emp;

  printf("Enter Employee Number: ");
  scanf("%d", &emp.empNumber);

  printf("Enter Employee Name: ");
  scanf(" %s", &emp.name);

  printf("Enter Basic Pay: ");
  scanf("%f", &emp.basicPay);

  // Print employee details
  printf("\nEmployee Details:\n");
  printf("Employee Number: %d\n", emp.empNumber);
  printf("Employee Name: %s\n", emp.name);
  printf("Basic Pay: %.2f\n", emp.basicPay);

  return 0;
}