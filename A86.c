// String Length
#include <stdio.h>
#include <string.h>

int main()
{
  char str[100];

  printf("Enter a string: ");
  fgets(str, 100, stdin);

  int len = strlen(str) - 1; // Remove the newline character

  printf("Length of the string: %d\n", len);

  return 0;
}
