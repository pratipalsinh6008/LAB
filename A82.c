// NCR Calculation
#include <stdio.h>

int factorial(int n)
{
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

int ncr(int n, int r)
{
  int ncr = factorial(n) / (factorial(r) * factorial(n - r));
  return ncr;
}

int main()
{
  int n, r;

  printf("Enter n and r: ");
  scanf("%d %d", &n, &r);

  printf("NCR = %d\n", ncr(n, r));

  return 0;
}
