/*Question 1: Write a C/C++ program to convert an infix to a postfix
expression using a stack, handling the operators +, -, *, /, and
parentheses.
Example:
Input: A*(B+C*D)+E
Output: ABCD*+*E+*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[20];
int top=-1;

//function to push the character
void push(char x)
{
    if( top == 19)
    {
        printf("overflow");
        return;
    }
    stack[++top]=x;
}

//function to remove the character
char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else{
        return stack[top--];
    }
}

//function to check the priority of the character
int priority(char x)
{
    if (x == '(')
    {
        return 0;
    }
    if( x == '+' || x == '-')
    {
        return 1;
    }
    if ( x == '/' || x == '*')
    {
        return 2 ;
    }
    return -1;
}

//main function 
int main()
{
    char str[20];
    char *ex,x;
    printf("enter the expression: ");
    scanf("%s",str);
    ex=str;
    printf("\"POSTFIX EXPRESSION IS :: ");
    while( *ex != '\0')
    {
        if(isalnum(*ex))
        {
            printf("%c",*ex);
        }
        else if(*ex == '(')
        {
            push(*ex);
        }
        else if(*ex == ')')
        {
            while((x=pop())!= '(')
            {
                printf("%c",x);
            }
        }
        else {
            while(top != -1 && priority(stack[top]) >= priority(*ex) )
            {
                printf("%c",pop());
            }
            push(*ex);
        }
        ex++;
    }
    //display the postfix character
    while(top!=-1)
    {
        printf("%c",pop());
    }
}