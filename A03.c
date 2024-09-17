#include <stdio.h>

int main() {
    float basic_salary, allowance, gross_salary;

    printf("Enter basic salary: ");
    scanf("%f", &basic_salary);

    allowance = basic_salary * 0.2; // assume 20% allowance
    gross_salary = basic_salary + allowance;

    printf("Gross salary: %.2f\n", gross_salary);

    return 0;
