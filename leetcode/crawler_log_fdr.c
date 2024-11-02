#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    int content;
    int min;
    struct s_list *next;
    
} t_list;

typedef struct stack {
    t_list *head;
    t_list *min;
} MinStack;

MinStack* minStackCreate() {
    MinStack *temp = malloc(sizeof(MinStack));
    
    if (temp)
    {
        temp->head = NULL;
        temp->min = 0;
    }
    return temp;
}

t_list *ft_lstnew(int val)
{
    t_list *item =(t_list*)malloc(sizeof(t_list));

    if (item)
        item->content = val;
    return item;
}

void minStackPush(MinStack* obj, int val) {
    t_list * item = ft_lstnew(val);
    item->next = obj->head;
    obj->head = item;
}

void minStackPop(MinStack* obj) {
    t_list *x = obj->head;
    obj->head = x->next;

    free(x);
}

int minStackTop(MinStack* obj) {
    // if (!obj->head)
    if (obj == NULL || obj->head == NULL) {
        return 0;
    }
    return obj->head->content;
}

int minStackGetMin(MinStack* obj) {
    t_list *x = obj->head;
    int c = obj->head->content;
    while (x != NULL)
    {
        if (x->content < c)
        {
            c = x->content;
        }
        x = x->next;
    }
    return c;
}

void stackprint(MinStack* obj)
{
    t_list *temp = obj->head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->content);
        temp = temp->next;
    }
    printf("NULL\n");
}

void minStackFree(MinStack* obj) {
    t_list *temp = obj->head;
    while (obj->head != NULL)
    {
        obj->head = temp->next;
        free(temp);
        temp = obj->head;
    }
}

int main()
{
    MinStack *x = minStackCreate();
    minStackPush(x, 2);
    minStackPush(x, 7);
    printf("%d \n",minStackTop(x));
    printf("%d \n", minStackGetMin(x));
    stackprint(x);
    minStackFree(x);
    stackprint(x);

}

// https://leetcode.com/problems/min-stack/description/