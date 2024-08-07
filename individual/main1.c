#include<stdio.h>

struct Rect 
{
    int x;      
    int y;      
    int width;  
    int height;
};
void move(struct Rect * p, int dx)
{
    p->x = p->x + dx;
}
int main()
{
    int a;
    int b;
    int c;
    int d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    struct Rect t = {a, b, c, d};
    int dx;
    scanf("%d", &dx);
    printf("%d %d %d %d + %d = ",t.x,t.y,t.width,t.height,dx);
    move(&t,dx);
    printf("%d %d %d %d",t.x,t.y,t.width,t.height);
    return 0;
}
