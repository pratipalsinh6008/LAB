#include <stdio.h>

int main()
{
  char original[] = "SVNITJAVA";
  char reversed[100];
  char *ptrOriginal = original;
  char *ptrReversed = reversed;

  while (*ptrOriginal)
  {
    ptrOriginal++;
  }

  ptrOriginal--;

  while (ptrOriginal >= original)
  {
    *ptrReversed = *ptrOriginal;
    ptrReversed++;
    ptrOriginal--;
  }

  *ptrReversed = '\0';

  printf("Reversed string: %s\n", reversed);

  return 0;
}