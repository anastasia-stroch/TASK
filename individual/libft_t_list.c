#include <stdlib.h>
#include <stdio.h>

typedef struct  s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

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

int ft_lstsize(t_list *lst)
{
    int size = 0;

    while (lst != NULL)
    {
        lst = lst->next;
        size++;
    }
    return size;
}
t_list *ft_lstlast(t_list *lst) 
{
    while(lst->next != NULL) {
        lst=lst->next;
    }
    return lst;
}
void ft_lstadd_back(t_list **lst, t_list *new) 
{
    t_list *head =(t_list *)malloc(sizeof(t_list *));
    head->next = *lst;
    while(head->next != NULL) 
    {
        head = head->next;
    }
    head->next = new;
}

void ft_lstforeach(t_list *lst, void (*f)(void *))
{}

int main()
{
    t_list *x1 = malloc(sizeof(t_list));

    x1->next = malloc(sizeof(t_list));
    x1->next->next = malloc(sizeof(t_list));
    x1->next->next->next = NULL;

    printf("START LIST\n");
    t_list *walker = x1;
    while (walker != NULL)
    {
        printf("%p\n----------------\n%p\n%p\n----------------\n\n", walker, walker->content, walker->next);
        walker = walker->next;
    }
    printf("END LIST\n\n");

    t_list *new = (t_list*)malloc(sizeof(t_list));
    new->content = malloc(sizeof(int));
    *(int*)(new->content) = 235;
    ft_lstadd_front(&x1, new);

    printf("START LIST\n");
    walker = x1;
    while (walker != NULL)
    {
        printf("%p\n----------------\n%p -> %d\n%p\n----------------\n\n",
                walker, walker->content,
                (walker->content == NULL) ? -1 : *(int*)(walker->content),
                walker->next);
        walker = walker->next;
    }
    printf("END LIST\n\n");    
    t_list *walker1 = x1;
    printf("%p", ft_lstlast(walker1));
    t_list *new1 = (t_list*)malloc(sizeof(t_list));
    ft_lstadd_back(&x1, new1);
    printf("START LIST\n");
    walker = x1;
    while (walker != NULL)
    {
        printf("%p\n----------------\n%p -> %d\n%p\n----------------\n\n",
                walker, walker->content,
                (walker->content == NULL) ? -1 : *(int*)(walker->content),
                walker->next);
        walker = walker->next;
    }

}
