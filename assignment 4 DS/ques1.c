#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head = NULL;

void insert(int data, int position)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;

  if (position == 1)
  {
    newNode->next = head;
    head = newNode;
    return;
  }

  struct Node *temp = head;
  for (int i = 1; i < position - 1 && temp != NULL; i++)
  {
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("Position out of range\n");
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

void delete(int position)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = head;

  if (position == 1)
  {
    head = head->next;
    free(temp);
    return;
  }

  for (int i = 1; i < position - 1 && temp != NULL; i++)
  {
    temp = temp->next;
  }

  if (temp == NULL || temp->next == NULL)
  {
    printf("Position out of range\n");
    return;
  }

  struct Node *nodeToDelete = temp->next;
  temp->next = nodeToDelete->next;
  free(nodeToDelete);
}

void display()
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main()
{
  insert(10, 1);
  insert(20, 2);
  insert(30, 3);
  display();

  delete (2);
  display();

  insert(20, 2);
  display();

  return 0;
}