#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int transfer(unsigned long long n, int numsys)
{
    int count = 0;
    int degree = 1;

    while (n > 0)
    {
        count += (n % 10) * degree;
        degree *= numsys;
        n /= 10;
    }
    return count;
}
