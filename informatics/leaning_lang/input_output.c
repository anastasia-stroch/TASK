#include <stdio.h>

// https://informatics.msk.ru/mod/statements/view.php?id=2296#1
void next_and_prev()
{
    int c;

    scanf("%d", &c);
    printf("The next number for the number %d is %d.\n", c, c + 1);
    printf("The previous number for the number %d is %d.\n", c, c - 1);
}

// https://informatics.msk.ru/mod/statements/view.php?id=2296&chapterid=2938#1
void div_apple1()
{
    int x;
    int y;

    scanf("%d%d", &x, &y);
    printf("%d", y / x);
}

// https://informatics.msk.ru/mod/statements/view.php?id=2296&chapterid=2939#1
void div_apple2()
{
    int x;
    int y;

    scanf("%d%d", &x,&y);
    printf("%d", y % x);
}

// https://informatics.msk.ru/mod/statements/view.php?id=2296&chapterid=2940#1
void mkad()
{
    int v;
    int t;
    
    scanf("%d %d", &v, &t);
    printf("%d\n", (109 + t * v % 109) % 109);
}

// https://informatics.msk.ru/mod/statements/view.php?id=2296&chapterid=2947#1
void clock1()
{
    int minutes;
    int hours;

    scanf("%d", &minutes);
    
    minutes %= 1440;
    hours = minutes / 60;
    minutes %= 60;

    printf("%d %d\n", hours, minutes);
}

// https://informatics.msk.ru/mod/statements/view.php?id=2296&chapterid=2958#1
void max2()
{
    int a;
    int b;
    int max;

    scanf("%d%d", &a, &b);
    max = (a * (a / b) + b * (b / a)) /
            (a / b + b / a);
    printf("%d", max);
}
