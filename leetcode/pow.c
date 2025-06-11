#include <stdio.h>
#include <stdlib.h> 

double myPow(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0 && n > 0)
    {
        double y = myPow(x, n / 2);
        return y * y;
    }
    else if (n < 0 && n != -2147483648)
    {
        return 1 / myPow(x, -n);
    }
    else if (n < 0 && n == -2147483648)
    {
        return 1 / (x * myPow(x, -(n + 1)));
    }
    else
    {
        return x * myPow(x, n - 1);
    }
    return 0;
}