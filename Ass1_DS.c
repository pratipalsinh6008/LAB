 /*Create five arrays of integers for five different cities of India. Each array
 stores the temperature data of a city for 365 days varying from 20 degrees
 Celsius to 40 degrees Celsius. You can generate temperature values
 randomly using an inbuilt function in C. Write a program to display the
 average temperature of each city and the overall average temperature
 combining data from all cities for five years.*/


 #include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int a[365], b[365], c[365], d[365], e[365];
    srand(time(NULL));
    int min = 20;
    int max = 40;
    int sum_a = 0, sum_b = 0, sum_c = 0, sum_d = 0, sum_e = 0;

    for (int i = 0; i < 365; i++)
    {
        a[i] = (rand() % (max - min + 1)) + min;
        b[i] = (rand() % (max - min + 1)) + min;
        c[i] = (rand() % (max - min + 1)) + min;
        d[i] = (rand() % (max - min + 1)) + min;
        e[i] = (rand() % (max - min + 1)) + min;

        sum_a += a[i];
        sum_b += b[i];
        sum_c += c[i];
        sum_d += d[i];
        sum_e += e[i];
    }

    int average_a = sum_a / 365;
    int average_b = sum_b / 365;
    int average_c = sum_c / 365;
    int average_d = sum_d / 365;
    int average_e = sum_e / 365;

    printf("The average temperature of city a is %d\n", average_a);
    printf("The average temperature of city b is %d\n", average_b);
    printf("The average temperature of city c is %d\n", average_c);
    printf("The average temperature of city d is %d\n", average_d);
    printf("The average temperature of city e is %d\n", average_e);

    
}