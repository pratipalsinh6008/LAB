/*Question 2: Write a C/C++ program to evaluate the postfix expression
using a stack.
Example:
Input: 2 3 1 * + 9 -
Output: - 4
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int stack[MAX];
int top = -1;

// Function to push an integer onto the stack
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Function to pop an integer from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to evaluate the postfix expression
int evaluatePostfix(char *exp) {
    char *token = strtok(exp, " ");  // Tokenize input by spaces
    int a, b, result;

    while (token != NULL) {
        if (isdigit(token[0])) {  // If token is a number, push onto stack
            push(atoi(token));  // Convert string to integer and push
        } 
        else {  // If token is an operator
            b = pop();  // Pop top element (second operand)
            a = pop();  // Pop next element (first operand)

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': 
                    if (b == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    result = a / b; 
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    return -1;
            }
            push(result);  // Push result back onto stack
        }
        token = strtok(NULL, " ");  // Get next token
    }
    return pop();  // Final result
}

int main() {
    char exp[50];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}
