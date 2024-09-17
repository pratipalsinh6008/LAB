#include <stdio.h>

int main() {
    int marks[5], totalMarks, averageMarks;

    printf("Enter marks for five subjects: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &marks[i]);
    }

    totalMarks = 0;
    for (int i = 0; i < 5; i++) {
        totalMarks += marks[i];
    }

    averageMarks = totalMarks / 5;

    if (averageMarks >= 90) {
        printf("Division: First\n");
    } else if (averageMarks >= 75) {
        printf("Division: Second\n");
    } else if (averageMarks >= 60) {
        printf("Division: Third\n");
    } else if (averageMarks >= 40) {
        printf("Division: Pass\n");
    } else {
        printf("Division: Fail\n");
    }

    return 0;
}