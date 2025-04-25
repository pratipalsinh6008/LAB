/*2. Write a C program to add two polynomials using Linked List
Input: poly1: 5x2 + 4x1 + 2
poly2: 5x1 + 5
Output: 5x2 + 9x1 + 7
3. Write a C program to multiply two polynomials using linked list
Input: poly1: 3x2 + 5x1 + 6
poly2: 6x1 + 8
Output: 18x3 + 54x2 + 76x1 + 48*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} Node;

// function to create newnode
Node *create(int co, int ex)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->coeff = co;
    newnode->exp = ex;
    newnode->next = NULL;
    return newnode;
}

// function to insert newnode to make link list polynomial
void insert(Node **poly, int ex, int co)
{
    if (co == 0)
        return; // ignore zero coefficient
    Node *newnode = create(co, ex);
    if (*poly == NULL || (*poly)->exp < ex)
    {
        newnode->next = *poly;
        *poly = newnode;
        return;
    }
    Node *temp = *poly;
    while (temp->next != NULL && temp->next->exp > ex)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

// function to user input polynomial values
Node *polynomial()
{
    Node *poly = NULL;
    int co, ex, TERMS;
    printf("\nENTER NUMBER OF TERMS--> ");
    scanf("%d", &TERMS);
    for (int i = 0; i < TERMS; i++)
    {
        printf("enter coefficient-> ");
        scanf("%d", &co);
        printf("enter exponent-> ");
        scanf("%d", &ex);
        insert(&poly, ex, co);
    }
    return poly;
}

// function to print polynomial
void polynomial_print(Node *poly)
{
    Node *temp = poly;
    if (poly == NULL)
    {
        printf("empty polynomial");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%dx^%d", temp->coeff, temp->exp);
            temp = temp->next;
            if (temp)
            {
                printf("+");
            }
        }
    }
    printf("\n");
}

// function to add polynomial
Node *add_poly(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    while (poly1 && poly2)
    {
        if (poly1->exp > poly2->exp)
        {
            insert(&result, poly1->exp, poly1->coeff);
            poly1 = poly1->next;
        }
        else if (poly2->exp > poly1->exp)
        {
            insert(&result, poly2->exp, poly2->coeff);
            poly2 = poly2->next;
        }
        else
        {
            insert(&result, poly2->exp, poly1->coeff + poly2->coeff);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    // Insert remaining terms (if any) from poly1
    while (poly1)
    {
        insert(&result, poly1->exp, poly1->coeff);
        poly1 = poly1->next;
    }

    // Insert remaining terms (if any) from poly2
    while (poly2)
    {
        insert(&result, poly2->exp, poly2->coeff);
        poly2 = poly2->next;
    }
    return result;
}

// main function
void main()
{
    Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    // function call to make polynomial
    poly1 = polynomial();
    poly2 = polynomial();
    printf("\"FIRST POLYNOMIAL WILL BE\"--> ");
    polynomial_print(poly1);
    printf("\"SECOND POLYNOMIAL WILL BE\"--> ");
    polynomial_print(poly2);
    sum = add_poly(poly1, poly2);
    printf("\"SUM OF TWO POLYNOMIAL WILL BE\"--> ");
    polynomial_print(sum);
}