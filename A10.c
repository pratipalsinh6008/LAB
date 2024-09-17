#include <stdio.h>

int main() {
    float mathMarks, physicsMarks, chemistryMarks, entranceMarks, cutOffMark;

    printf("Enter the marks in Mathematics, Physics, Chemistry, and Entrance Examination: ");
    scanf("%f %f %f %f", &mathMarks, &physicsMarks, &chemistryMarks, &entranceMarks);

    cutOffMark = (mathMarks / 2) + (physicsMarks / 2) + (chemistryMarks / 2) + entranceMarks;

    printf("The cut-off mark is: %.2f\n", cutOffMark);

    return 0;
}