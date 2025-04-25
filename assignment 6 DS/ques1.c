/*
1. Implement stack using array and with the following operations
a) Adding an element onto the stack (push operation)
b) Deletion of an element from a stack (Pop operation)
c) Visiting each element of the stack (Peek operation)
*/

#include<stdio.h>
#include<stdlib.h>

# define Max_Size 100

//Function to push elemetnt into stack 
int push(int *top, int arr[]){
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    if(*top == Max_Size - 1){   //Overflow
        printf("Stack is Full!\n"); 
        return 1;
    }

    arr[++*top] = data;
    return 0;
}

//Function to pop element from stack
void pop(int *top, int arr[]){
    int data;

    if(*top == -1){     //Underflow
        printf("Stack is Empty!\n"); 
    }

    else{
        data = arr[*top];
        *top -= 1;
        printf("Popped element: %d\n", data);
    }
}

//Function to print elements in stack
int peek(int top, int arr[]){
    if(top == -1){
        printf("Stack is Empty!\n");
        return -1;
    }

    return arr[top];
}

//Function to print elements in stack
void display(int top, int arr[]){
    if(top == -1){
        printf("Stack is Empty!\n");
    }

    else{
        printf("Stack contains: ");
        while(top != -1){           //Printing elements from top to bottom
        printf("%d ", arr[top]);
        top--;
    }
    printf("\n");
    }
}

int main(){
    int Top = -1, choice;
    int stack[Max_Size];

    while(1){
        printf("\nStack Operations:\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: if(!push(&Top, stack))
                        printf("Element is sucessfully pushed into stack!\n");
                    break;
            
            case 2: pop(&Top, stack);
                    break;
            
            case 3: printf("Top element: %d\n", peek(Top, stack));
                    break;

            case 4: display(Top, stack);
                    break;

            case 5: return 0;

            default: printf("Invalid Choice!");
        }
    }

    return 0;
}