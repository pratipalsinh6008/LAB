#include <stdio.h>

int main()
{
    double sales, commission;

    printf("Enter sales amount: ");
    scanf("%lf", &sales);

    if (sales <= 500)
    {
        commission = sales * 0.05;
    }
    else if (sales <= 2000)
    {
        commission = 35 + (sales - 500) * 0.1;
    }
    else if (sales <= 5000)
    {
        commission = 185 + (sales - 2000) * 0.12;
    }
    else
    {
        commission = sales * 0.125;
    }

    printf("Commission: Rs. %.2f\n", commission);

    return 0;
}