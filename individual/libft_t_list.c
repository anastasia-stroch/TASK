#include <stdlib.h>
#include <stdio.h>

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
    if (lst == NULL)
        return NULL;
    while (lst->next != NULL) {
        lst = lst->next;
    }
    return lst;
}

void ft_lstadd_back(t_list **lst, t_list *new) 
{
    t_list *head = *lst;
    if (head == NULL)
    {
        head = new;
        return ;
    }
    while(head->next != NULL) 
    {
        head = head->next;
    }
    head->next = new;
}

void inc_int(void *content)
{
    *((int*)content) += 1;
}

void ft_lstforeach(t_list *lst, void (*f)(void *))
{
    if (f = NULL)
    {
        return;
    }
    while (lst != NULL)
    {
        f(lst->content);
        lst = lst->next;
    }
}

void ft_lstpop_front(t_list **lst, void (*free_content)(void *)) {
    if (lst == NULL || *lst == NULL) {
        return;
    }
    t_list *temp = *lst;
    *lst = temp->next;
    if (free_content) {
        free_content(temp->content);
    }
    free(temp);
}

void ft_lstpop_back(t_list **lst, void (*free_content)(void *)) {
}

void push(t_stack *st, void *new) {
    t_list *item = ft_lstnew(new);
    ft_lstadd_front(&(st->head), item);
}

void pop(t_stack *st) {
    t_list *temp = st->head;
    temp->next=st->head;
    free(temp);
}


int main()
{
    int size = 4;
    t_list *head = NULL;

    for (int i = 0; i < size; i++)
    {
        t_list *temp = ft_lstnew(malloc(sizeof(int)));
        if (temp != NULL && temp->content != NULL)
        {
            *(int*)(temp->content) = i;
            ft_lstadd_front(&head, temp);
        }
    }

    printf("START LIST\n");
    t_list *walker = head;
    while (walker != NULL)
    {
        printf("%p\n----------------\n%p\n%p\n----------------\n\n", walker, walker->content, walker->next);
        walker = walker->next;
    }
    printf("END LIST\n\n");

    t_list *new = (t_list*)malloc(sizeof(t_list));
    new->content = malloc(sizeof(int));
    *(int*)(new->content) = 235;
    ft_lstadd_front(&head, new);

    printf("START LIST\n");
    walker = head;
    while (walker != NULL)
    {
        printf("%p\n----------------\n%p -> %d\n%p\n----------------\n\n",
                walker, walker->content,
                (walker->content == NULL) ? -1 : *(int*)(walker->content),
                walker->next);
        walker = walker->next;
    }
    printf("END LIST\n\n");    
    t_list *walker1 = head;
    printf("%p", ft_lstlast(walker1));
    t_list *new1 = (t_list*)malloc(sizeof(t_list));
    ft_lstadd_back(&head, new1);
    printf("START LIST\n");
    walker = head;
    pop(head);
    while (walker != NULL)
    {
        printf("%p\n----------------\n%p -> %d\n%p\n----------------\n\n",
                walker, walker->content,
                (walker->content == NULL) ? -1 : *(int*)(walker->content),
                walker->next);
        walker = walker->next;
    }

}

// https://github.com/evgenkarlson/ALL_SCHOOL_42/tree/master/00_Projects__(%D0%9E%D1%81%D0%BD%D0%BE%D0%B2%D0%BD%D0%BE%D0%B5_%D0%9E%D0%B1%D1%83%D1%87%D0%B5%D0%BD%D0%B8%D0%B5)/00_Global_(begin_cadet)/01____libft