#include <stdio.h>
#include <stdlib.h>

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=257#1
void horse()
{
    int x1;
    int y1;
    int x2;
    int y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (abs(x1 - x2) == 2 && abs(y1 - y2) == 1 || abs(x1 - x2) == 1 && abs(y1 - y2) == 2)
    {
       printf("YES"); 
    }
    else
    {
        printf("NO");
    }
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=258#1
void chocolate()
{
    int x1;
    int x2;
    int x3;

    scanf("%d %d %d", &x1, &x2, &x3);
    if (x3 <= x2 * x1 && x3 % x1 == 0 ||
        x3 % x2 == 0 && x3 <= x2 * x1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=2959#1
void sign_number()
{
    int x1; 
    
    scanf("%d", &x1);
    if (x1 > 0)
    {
        printf("1");
    }
    else if (x1 == 0)
    {
        printf("0");
    }
    else
    {
        printf("-1");
    }
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=293#1
void max_variant()
{
    int x1;
    int x2;
    
    scanf("%d %d", &x1, &x2);
    if (x1 > x2)
    {
        printf("1");
    }
    else if (x1 < x2)
    {
        printf("2");
    }
    else
    {
        printf("0");
    }
}



// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=294#1
void max_three()
{
    int x1;
    int x2;
    int x3;
    int mx;
    
    scanf("%d %d %d", &x1, &x2, &x3);
    mx = x1; 
    if (x2 > x1)
    {
        mx = x2;
    }
    if (x3 > mx)
    {
        mx = x3;
    }
    printf("%d", mx);
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=254#1
void ladya()
{
    int x1;
    int y1;
    int x2;
    int y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (abs(y1 - y2) == 0 || abs(x1 - x2) == 0)
    {
       printf("YES"); 
    }
    else
    {
        printf("NO");
    }
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=255#1
void elephant()
{
    int x1;
    int y1;
    int x2;
    int y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (abs(y1 - y2) == abs(x1 - x2))
    {
       printf("YES"); 
    }
    else
    {
        printf("NO");
    }
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=256#1
void queen()
{
    int x1;
    int y1;
    int x2;
    int y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (abs(y1 - y2) == abs(x1 - x2) ||
        abs(x1 - x2) == 0 || abs(y1 - y2) == 0)
    {
       printf("YES"); 
    }
    else
    {
        printf("NO");
    }
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=298#1
void king()
{
    int x1;
    int y1;
    int x2;
    int y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (abs(y1 - y2) <= 1 && abs(x1 - x2) <= 1)
    {
       printf("YES"); 
    }
    else
    {
        printf("NO");
    }
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=259#1
void chips()
{
    int x1;

    scanf("%d", &x1);
    if (x1 % 4 == 0 || x1 == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
 }

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=262#1
void change()
{
    int price_rub;
    int price_kop;
    int pay_rub;
    int pay_kop;
    
    scanf("%d %d %d %d",
            &price_rub, &price_kop, &pay_rub, &pay_kop);
    price_kop += 100 * price_rub;
    pay_kop += 100 * pay_rub;
    pay_kop -= price_kop;
    printf("%d %d", pay_kop / 100, pay_kop % 100);
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=266#1
void coordinate_quarters()
{
    int x1;
    int y1;
    int x2;
    int y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 * x2 > 0 && y1 * y2 > 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=295#1
void triangle()
{
    int a;
    int b;
    int c;

    scanf("%d %d %d", &a, &b, &c);
    if (a < b + c && b < a + c && c < b + a)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=296#1
void equal_from_three()
{
    int k;
    int m;
    int n;

    scanf("%d %d %d", &k, &m, &n);
    printf("%d", (k == m) + (k == n) + (m == n));
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=292#1
void mx()
{
    int x;
    int y;
    int max;

    scanf("%d%d", &x, &y);
    if (x > y)
    {
        max = x;
    }
    else
    {
        max = y;
    }
    printf("%d", max); // max = (x > y) ? x : y;
    return 0;
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=303#1
int cows()
{
    int x1;
    int r10;
    int r100;

    scanf("%d", &x1);
    r10 = x1 % 10;
    r100 = x1 % 100;
    if (r10 == 1 && r100 != 11)
    {
        printf("%d korova", x1);
    }
    else if (2 <= r10 && r10 <= 4 && r100 / 10 != 1) // 1 + 2 + 3
    {
        printf("%d korovy", x1);
    }
    else
    {
        printf("%d korov", x1);
    }
    return 0;
}

// https://informatics.msk.ru/mod/statements/view.php?id=276&chapterid=302#1
int triangle_type()
{
    int k;
    int m;
    int n;
    int temp;

    scanf("%d %d %d", &k, &m, &n);
    if (k > m)
    {
        temp = k;
        k = m;
        m = temp;
    }
    if (m > n)
    {
        temp = n;
        n = m;
        m = temp;
    }
    if (k > m)
    {
        temp = k;
        k = m;
        m = temp;
    }

    if (n < m + k && m < n + k && k < m + n)
    {
        k *= k;
        m *= m;
        n *= n;

        if (n == k + m)
        {
            printf("right");
        }
        if (n < k + m)
        {
            printf("acute");
        }
        else
        {
            printf("obtuse");
        }
    }
    else
    {
        printf("impossible");
    }
}
