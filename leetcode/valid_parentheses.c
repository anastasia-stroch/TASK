#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

typedef struct s_stack 
{
    t_list *head;
    // size_t size;
    // size_t capacity;
} t_stack;

t_list *ft_lstnew(void *content)
{
    t_list *item =(t_list*)malloc(sizeof(t_list));

    if (item)
        item->content = content;
    return item;
}

void ft_lstadd_front(t_list **lst, t_list *new) 
{
    new->next = *lst;
    *lst = new;
}

void push(t_stack *st, void *new) {
    t_list *item = ft_lstnew(new);
    ft_lstadd_front(&(st->head), item);
}

void pop(t_stack *st) {
    if (st == NULL || st->head == NULL)
        return;
    t_list *temp = st->head;
    st->head = temp->next;
    free(temp);
}

bool isValid(char* s)
{
    t_stack stack = { .head = NULL };
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(&stack, (void*)(s + i));
        }
        else
        {
            if (stack.head != NULL &&
                ((s[i] == ')' && *(char*)(stack.head->content) == '(') ||
                (s[i] == ']' && *(char*)(stack.head->content) == '[') ||
                (s[i] == '}' && *(char*)(stack.head->content) == '{')))
            {
                pop(&stack);
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    return stack.head == NULL;
}

int main() {
    printf("%d\n", isValid("()"));
    return 0;
}

// https://leetcode.com/problems/valid-parentheses/description/