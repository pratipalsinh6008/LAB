#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node
{
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to display the linked list
void displayList(struct Node *head)
{
  if (head == NULL)
  {
    printf("The list is empty.\n");
    return;
  }
  printf("Linked list elements: ");
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Main function
int main()
{
  struct Node *head = NULL;
  int choice, data;

  do
  {
    printf("\nMenu:\n");
    printf("1. Insert node at beginning\n");
    printf("2. Display list\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      insertAtBeginning(&head, data);
      break;
    case 2:
      displayList(head);
      break;
    case 3:
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid choice! Please try again.\n");
    }
  } while (choice != 3);

  return 0;
}