'''2. Write a Python program to create a class representing a queue data structure. Include methods 
for enqueueing and dequeuing elements.'''

class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, item):
        # Add an element to the rear of the queue
        self.queue.append(item)
        print(f"Enqueued: {item}")

    def dequeue(self):
        # Remove and return the front element of the queue.
        if not self.is_empty():
            removed_item = self.queue.pop(0)
            print(f"Dequeued: {removed_item}")
            return removed_item
        else:
            print("Queue is empty. Cannot dequeue.")
            return None

    def is_empty(self):
        # Check if the queue is empty.
        return len(self.queue) == 0

    def display(self):
        # Display the queue elements.
        print("Queue:", self.queue)

# Example Usage
q = Queue()
x =int(input("enter the element you want to enter:: "))
for i in range (0,x):
    y=int(input(f"{1+i}) enter the number-> "))
    q.enqueue(y)
q.display()
q.dequeue()
q.display()