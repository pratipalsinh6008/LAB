/*Implement a queue using a linked list with two pointers: front and
rear. Elements can only be inserted via the rear pointer and deleted via the front
pointer. The queue has the following basic operations:
● enqueue() – Insert an element in the queue.
● dequeue() – Remove the element from the queue.
● peek() – Return the element
● ment at the front node of the queue
● isFull() – Validates if the queue is full or not.
● isEmpty() – Checks if the queue is empty.*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to add an element to the queue
void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}

// Function to get the front element of the queue
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

// Function to check if the queue is full (always returns false for linked list implementation)
bool isFull(struct Queue* q) {
    return false;
}

// Function to display the elements of the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue implementation with user input
int main() {
    struct Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) {
                    printf("Dequeued element is %d\n", value);
                }
                break;
            case 3:
                value = peek(q);
                if (value != -1) {
                    printf("Front element is %d\n", value);
                }
                break;
            case 4:
                display(q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}