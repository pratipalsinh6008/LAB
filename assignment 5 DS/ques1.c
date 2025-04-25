/*
1. Write a C program to create an Undo and redo functionality using a circular linked list
and perform the following operations on it.
1) Insert an element into a user-specific index
2) Insert an element at the beginning of the linked list
3) Insert an element at the last index of the linked list
4) Delete an element from a user-specific index
5) Delete an element from the beginning of the linked list
6) Delete an element from last index of the linked list
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

int lastValue = 0;     
int lastPosition = 0;   
int lastAction = 0;     

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* createInitialList() {
    struct Node* head = NULL;
    int n, data;
    
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of nodes\n");
        return NULL;
    }
    
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    head->next = head;  
    
    struct Node* temp = head;
    
    for(int i = 1; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        temp->next = newNode;
        newNode->next = head;  
        temp = newNode;
    }
    
    printf("Initial circular linked list created successfully!\n");
    return head;
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("head\n");
}

// Function to insert at beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;
        lastValue = data;
        lastPosition = 0;
        lastAction = 1;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
        
    temp->next = newNode;
    newNode->next = head;
    lastValue = data;
    lastPosition = 0;
    lastAction = 1;
    return newNode;
}

// Function to insert at end
struct Node* insertAtEnd(struct Node* head, int data) {
    if (head == NULL)
        return insertAtBeginning(head, data);
        
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int position = 0;
    
    while (temp->next != head) {
        temp = temp->next;
        position++;
    }
    
    temp->next = newNode;
    newNode->next = head;
    lastValue = data;
    lastPosition = position + 1;
    lastAction = 1;
    return head;
}

// Function to insert at position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return head;
    }
    
    if (position == 0)
        return insertAtBeginning(head, data);
        
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int currentPos = 0;
    
    do {
        if (currentPos == position - 1) {
            newNode->next = temp->next;
            temp->next = newNode;
            lastValue = data;
            lastPosition = position;
            lastAction = 1;
            return head;
        }
        temp = temp->next;
        currentPos++;
    } while (temp != head && currentPos < position);
    
    printf("Position out of range\n");
    free(newNode);
    return head;
}

// Function to delete from beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    if (head->next == head) {
        lastValue = head->data;
        lastPosition = 0;
        lastAction = 2;
        free(head);
        return NULL;
    }
    
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
        
    struct Node* toDelete = head;
    head = head->next;
    temp->next = head;
    lastValue = toDelete->data;
    lastPosition = 0;
    lastAction = 2;
    free(toDelete);
    return head;
}

// Function to delete from end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    if (head->next == head)
        return deleteFromBeginning(head);
        
    struct Node* temp = head;
    struct Node* prev = NULL;
    int position = 0;
    
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
        position++;
    }
    
    prev->next = head;
    lastValue = temp->data;
    lastPosition = position;
    lastAction = 2;
    free(temp);
    return head;
}

// Function to delete from position
struct Node* deleteFromPosition(struct Node* head, int position) {
    if (head == NULL || position < 0) {
        printf("Invalid deletion\n");
        return head;
    }
    
    if (position == 0)
        return deleteFromBeginning(head);
        
    struct Node* temp = head;
    struct Node* prev = NULL;
    int currentPos = 0;
    
    do {
        if (currentPos == position) {
            prev->next = temp->next;
            lastValue = temp->data;
            lastPosition = position;
            lastAction = 2;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
        currentPos++;
    } while (temp != head);
    
    printf("Position out of range\n");
    return head;
}

// Function to undo last operation
struct Node* undo(struct Node* head) {
    if (lastAction == 0) {
        printf("Nothing to undo\n");
        return head;
    }
    
    int tempValue = lastValue;
    int tempPosition = lastPosition;
    
    if (lastAction == 1) {  
        head = deleteFromPosition(head, lastPosition);
    } else {  
        head = insertAtPosition(head, lastValue, lastPosition);
    }
    
    lastValue = tempValue;
    lastPosition = tempPosition;
    lastAction = 0;  
    return head;
}

// Function to redo last undone operation
struct Node* redo(struct Node* head) {
    if (lastAction != 0) {
        printf("Nothing to redo\n");
        return head;
    }
    
    if (lastValue != 0) {  
        if (lastPosition == 0) {
            head = insertAtBeginning(head, lastValue);
        } else {
            head = insertAtPosition(head, lastValue, lastPosition);
        }
    }
    
    return head;
}

int main() {
    printf("\n=== Circular Linked List Creation ===\n");
    struct Node* head = createInitialList();
    printf("\nInitial ");
    displayList(head);
    
    int choice, data, position;
    
    while (1) {
        printf("\nCircular Linked List Operations:");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. Delete from beginning");
        printf("\n5. Delete from end");
        printf("\n6. Delete from position");
        printf("\n7. Display list");
        printf("\n8. Undo");
        printf("\n9. Redo");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
                
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
                
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                head = insertAtPosition(head, data, position);
                break;
                
            case 4:
                head = deleteFromBeginning(head);
                break;
                
            case 5:
                head = deleteFromEnd(head);
                break;
                
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
                
            case 7:
                displayList(head);
                break;
                
            case 8:
                head = undo(head);
                displayList(head);
                break;
                
            case 9:
                head = redo(head);
                displayList(head);
                break;
                
            case 10:
                // Free memory before exiting
                while (head != NULL && head->next != head) {
                    head = deleteFromBeginning(head);
                }
                if (head != NULL) free(head);
                return 0;
                
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}