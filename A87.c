// Displaying Students with Marks > 500
#include <stdio.h>

struct Student
{
  int rollNo;
  char name[50];
  int marks;
};

void displayStudents(struct Student students[], int n)
{
  for (int i = 0; i < n; i++)
  {
    if (students[i].marks > 500)
    {
      printf("Roll No: %d\n", students[i].rollNo);
      printf("Name: %s\n", students[i].name);
      printf("Marks: %d\n", students[i].marks);
      printf("\n");
    }
  }
}

int main()
{
  struct Student students[10];

  for (int i = 0; i < 10; i++)
  {
    printf("Enter details for student %d:\n", i + 1);
    printf("Roll No: ");
    scanf("%d", &students[i].rollNo);
    printf("Name: ");
    scanf("%s", students[i].name);
    printf("Marks: ");
    scanf("%d", &students[i].marks);
  }

  displayStudents(students, 10);

  return 0;
}
