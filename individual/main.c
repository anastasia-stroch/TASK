#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//        m
// ............................ X ........... Y
// max_profit
// X - a[m]

int maxProfit(int* prices, int pricesSize)
{
    int max_profit = 0;
    int min_el = prices[0];

    for (int i = 0; pricesSize; i++)
    {
        if (prices[i] - min_el > max_profit)
        {
            max_profit = prices[i] - min_el;
        }
        if (prices[i] < min_el)
        {
            min_el = prices[i];
        }
    }
    return max_profit;
}

int gcd(int a, int b)
{
    int t;

    while (b != 0)
    {
        t = a;
        a = b;
        b = t % b;
    }
    return a;
}

struct s_list
{
    int data;
    struct s_list *next;
};

typedef struct s_list t_list;

list_push_front(t_list **head, int data)
{
    
}

int main()
{
    t_list *head = NULL;

    list_push_front(&head, 12);
    return 0;
}
