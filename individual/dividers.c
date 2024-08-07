#include <stdio.h>

void amount_of_dividers()
{
    int number;
    int d = 1;
    scanf("%d", &number);
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            d += 1;
        }
        if (i * i == number)
        {
            d = d * 2 - 1;
        }
    }
    printf("%d", d);
}

// 2 2 3 3 3 3 11
void prime_factors()
{
    int number;
    int d = 2;

    scanf("%d", &number);
    while (number > 1)
    {
        if (number % d == 0)
        {
            printf("%d", d);
            number /= d;
        }
        else
        {
            ++d;
        }
    }
}
