int linear_equation(double a, double b, double *x)
{
    if (a != 0)
    {
        *x = -b / a;
        return 1;
    }
    if (b == 0)
        return 2;
    return 0;
}