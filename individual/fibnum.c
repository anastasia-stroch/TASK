#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int x = 1;
    int y = 1;
    int n = 0;
    int z = 0;

    scanf("%d", &n);
    n = n - 2;

    while (n > 0)
    {
        z = x;
        x += y;
        y = z;
        n--;
    }
    printf("%d", x);

    return 0;
}
