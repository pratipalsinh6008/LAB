/*Implement Priority queue for the following operations:
a) Insert an elements
b) Delete an element from any position
c) Peeking from the Priority Queue (Find max/min without deleting an
element)
d) Extract-Max/Min from the Priority Queue(after deleting an element)*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  
// Structure to represent a Priority Queue
typedef struct {
    int value;
    int priority;
} PriorityQueue;


PriorityQueue pq[SIZE];
int count = 0;  

// Function to check if the queue is empty
int isEmpty() {
    return count == 0;
}

// Function to check if the queue is full
int isFull() {
    return count == SIZE;
}

// Function to insert an element into the priority queue
void insert(int value, int priority) {
    if (isFull()) {
        printf("Priority Queue is full! Cannot insert.\n");
        return;
    }

    pq[count].value = value;
    pq[count].priority = priority;
    count++;

    printf("Inserted value: %d with priority: %d\n", value, priority);
}

// Function to find the index of the highest-priority element
int findMax() {
    if (isEmpty()) {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    int maxIndex = 0;
    for (int i = 1; i < count; i++) {
        if (pq[i].priority > pq[maxIndex].priority) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to find the index of the lowest-priority element
int findMin() {
    if (isEmpty()) {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    int minIndex = 0;
    for (int i = 1; i < count; i++) {
        if (pq[i].priority < pq[minIndex].priority) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to delete an element from any position
void deleteAtPosition(int pos) {
    if (isEmpty() || pos < 0 || pos >= count) {
        printf("Invalid position or Queue is empty!\n");
        return;
    }

    printf("Deleted value: %d with priority: %d\n", pq[pos].value, pq[pos].priority);

    // Shift elements to fill the gap
    for (int i = pos; i < count - 1; i++) {
        pq[i] = pq[i + 1];
    }
    count--;
}

// Function to peek at the maximum element without deleting it
void peekMax() {
    int maxIndex = findMax();
    if (maxIndex != -1) {
        printf("Max Element: %d with Priority: %d\n", pq[maxIndex].value, pq[maxIndex].priority);
    }
}

// Function to peek at the minimum element without deleting it
void peekMin() {
    int minIndex = findMin();
    if (minIndex != -1) {
        printf("Min Element: %d with Priority: %d\n", pq[minIndex].value, pq[minIndex].priority);
    }
}

// Function to extract and delete the maximum element
void extractMax() {
    int maxIndex = findMax();
    if (maxIndex != -1) {
        printf("Extracted Max: %d with Priority: %d\n", pq[maxIndex].value, pq[maxIndex].priority);
        deleteAtPosition(maxIndex);
    }
}

// Function to extract and delete the minimum element
void extractMin() {
    int minIndex = findMin();
    if (minIndex != -1) {
        printf("Extracted Min: %d with Priority: %d\n", pq[minIndex].value, pq[minIndex].priority);
        deleteAtPosition(minIndex);
    }
}

// Function to display the priority queue
void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < count; i++) {
        printf("Value: %d, Priority: %d\n", pq[i].value, pq[i].priority);
    }
}

// Main function to test priority queue operations
int main() {
    int choice, value, priority, position;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element from Any Position\n");
        printf("3. Peek Max\n");
        printf("4. Peek Min\n");
        printf("5. Extract Max\n");
        printf("6. Extract Min\n");
        printf("7. Display Queue\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter priority: ");
                scanf("%d", &priority);
                insert(value, priority);
                break;
            case 2:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 3:
                peekMax();
                break;
            case 4:
                peekMin();
                break;
            case 5:
                extractMax();
                break;
            case 6:
                extractMin();
                break;
            case 7:
                display();
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