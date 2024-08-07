#include <stdio.h>
#include <math.h>

int main()
{
    int x1;
    int c;
    int i;

    scanf("%d", &x1);
    c = 1;
    for (i = 2; i <= sqrt(x1); i++)
    {
        if (x1 % i == 0)
        {
            c = i;
            break;
        }
    }
    printf("%d", c);
    return 0;
}