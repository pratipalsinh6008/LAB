#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 10
#define MAX_LENGTH 50

int main()
{
  char strings[MAX_STRINGS][MAX_LENGTH];
  int n;

  // Input number of strings
  printf("Enter number of strings (max %d): ", MAX_STRINGS);
  scanf("%d", &n);

  // Input strings
  printf("Enter %d strings:\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf(" %[^\n]", strings[i]);
  }

  // Sort strings
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (strcmp(strings[j], strings[j + 1]) > 0)
      {
        char temp[MAX_LENGTH];
        strcpy(temp, strings[j]);
        strcpy(strings[j], strings[j + 1]);
        strcpy(strings[j + 1], temp);
      }
    }
  }

  // Output sorted strings
  printf("\nSorted strings:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%s\n", strings[i]);
  }

  return 0;
}