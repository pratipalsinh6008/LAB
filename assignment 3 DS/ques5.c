#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to convert a linked list to an array
int* linkedListToArray(struct Node* head, int* size) {
    *size = 0;
    struct Node* temp = head;

    // Calculate the size of the linked list
    while (temp != NULL) {
        (*size)++;
        temp = temp->next;
    }

    if (*size == 0) {
        return NULL;
    }

    // Allocate memory for the array
    int* arr = (int*)malloc((*size) * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Copy elements from the linked list to the array
    temp = head;
    for (int i = 0; i < *size; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    return arr;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked list elements: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, size;
    int* array;

    do {
        printf("\nMenu:\n");
        printf("1. Append node\n");
        printf("2. Display linked list\n");
        printf("3. Convert linked list to array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                appendNode(&head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                array = linkedListToArray(head, &size);
                if (array == NULL) {
                    printf("The linked list is empty, no array to display.\n");
                } else {
                    printf("Array elements: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", array[i]);
                    }
                    printf("\n");
                    free(array); // Free the allocated memory for the array
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}