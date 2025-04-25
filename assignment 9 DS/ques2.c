/*Implement Double ended queue for the following operations:
a) Insert an element at Front
b) Insert an element at Rear
c) Delete an element from Front
d) Delete an element from Rear
e) Check Empty
f) Check Full*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  
// Structure to represent a deque
typedef struct {
    int arr[SIZE];
    int front, rear;
} Deque;

// Function to initialize the deque
void initialize(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Function to check if the deque is empty
int isEmpty(Deque *dq) {
    return (dq->front == -1);
}

// Function to check if the deque is full
int isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == SIZE - 1) || (dq->front == dq->rear + 1));
}

// Function to insert an element at the front
void insertFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert at front.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = SIZE - 1;
    } else {
        dq->front--;
    }

    dq->arr[dq->front] = value;
    printf("Inserted %d at front.\n", value);
}

// Function to insert an element at the rear
void insertRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert at rear.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == SIZE - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->arr[dq->rear] = value;
    printf("Inserted %d at rear.\n", value);
}

// Function to delete an element from the front
void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from front.\n");
        return;
    }

    printf("Deleted %d from front.\n", dq->arr[dq->front]);

    if (dq->front == dq->rear) { // Only one element was present
        dq->front = dq->rear = -1;
    } else if (dq->front == SIZE - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

// Function to delete an element from the rear
void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from rear.\n");
        return;
    }

    printf("Deleted %d from rear.\n", dq->arr[dq->rear]);

    if (dq->front == dq->rear) { // Only one element was present
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = SIZE - 1;
    } else {
        dq->rear--;
    }
}

// Function to display the deque
void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function to test the deque operations
int main() {
    Deque dq;
    initialize(&dq);

    int choice, value;
    
    while (1) {
        printf("\nDeque Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Check Empty\n");
        printf("6. Check Full\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                printf(isEmpty(&dq) ? "Deque is empty.\n" : "Deque is not empty.\n");
                break;
            case 6:
                printf(isFull(&dq) ? "Deque is full.\n" : "Deque is not full.\n");
                break;
            case 7:
                display(&dq);
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}