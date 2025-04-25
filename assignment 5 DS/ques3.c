/*
3. Write a C program to multiply two polynomials using linked list
Input: poly1: 3x^2 + 5x^1 + 6
poly2: 6x^1 + 8
Output: 18x^3 + 54x^2 + 76x^1 + 48
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for polynomial term
struct Term {
    int coeff;          // Coefficient
    int exp;            // Exponent
    struct Term* next;
};

// Function to create new term
struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert term into polynomial
struct Term* insertTerm(struct Term* head, int coeff, int exp) {
    
    if (coeff == 0) return head;
    
    struct Term* newTerm = createTerm(coeff, exp);
    
    // If list is empty or new term has higher exponent
    if (head == NULL || exp > head->exp) {
        newTerm->next = head;
        return newTerm;
    }
    
    // If term with same exponent exists, add coefficients
    if (exp == head->exp) {
        head->coeff += coeff;
        free(newTerm);
        
        if (head->coeff == 0) {
            struct Term* temp = head->next;
            free(head);
            return temp;
        }
        return head;
    }
    
    
    struct Term* current = head;
    while (current->next != NULL && current->next->exp > exp) {
        current = current->next;
    }
    
    // Check if next term has same exponent
    if (current->next != NULL && current->next->exp == exp) {
        current->next->coeff += coeff;
        free(newTerm);

        if (current->next->coeff == 0) {
            struct Term* temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        return head;
    }
    
    newTerm->next = current->next;
    current->next = newTerm;
    return head;
}

// Function to create polynomial
struct Term* createPolynomial() {
    struct Term* poly = NULL;
    int terms, coeff, exp;
    
    printf("Enter number of terms: ");
    scanf("%d", &terms);
    
    for (int i = 0; i < terms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        if (coeff != 0) {  
            poly = insertTerm(poly, coeff, exp);
        }
    }
    
    return poly;
}

// Function to display polynomial
void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    
    struct Term* current = poly;
    while (current != NULL) {
        // Print coefficient
        if (current != poly && current->coeff > 0) {
            printf(" + ");
        }
        printf("%d", current->coeff);
        
        // Print exponent
        if (current->exp > 0) {
            printf("x");
            if (current->exp > 1) {
                printf("^%d", current->exp);
            }
        }
        current = current->next;
    }
    printf("\n");
}

// Function to multiply two polynomials
struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* p1 = poly1;
    
    // Multiply each term of first polynomial with each term of second
    while (p1 != NULL) {
        struct Term* p2 = poly2;
        while (p2 != NULL) {
            // Multiply coefficients and add exponents
            int newCoeff = p1->coeff * p2->coeff;
            int newExp = p1->exp + p2->exp;
            // Add this term to result
            result = insertTerm(result, newCoeff, newExp);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    
    return result;
}

// Function to free polynomial
void freePolynomial(struct Term* poly) {
    struct Term* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    printf("Enter first polynomial:\n");
    struct Term* poly1 = createPolynomial();
    
    printf("\nEnter second polynomial:\n");
    struct Term* poly2 = createPolynomial();
    
    printf("\nFirst polynomial: ");
    displayPolynomial(poly1);
    
    printf("Second polynomial: ");
    displayPolynomial(poly2);
    
    struct Term* result = multiplyPolynomials(poly1, poly2);
    printf("Product of polynomials: ");
    displayPolynomial(result);
    
    // Free memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);
    
    return 0;
}