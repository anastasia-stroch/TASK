#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int            content;
    struct s_list   *next;
}                   t_list;

typedef struct s_stack 
{
    t_list *head;
} t_stack;

t_list *ft_lstnew(int content)
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

void pop(t_stack *st) 
{
    t_list *temp = st->head;
    temp->next=st->head;
    free(temp);
}

void push(t_stack *st, int new) {
    t_list *item = ft_lstnew(new);
    ft_lstadd_front(&(st->head), item);
}
 
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    if (root == NULL)
    {
        return NULL;
    }
    int i = 0;
    struct TreeNode *walker = root;
    t_stack *count = (t_stack *)malloc(sizeof(t_stack));
    push(count, walker->val);
    while (count != NULL)
    {
        while (walker->left != NULL)
        {
            push(count, walker->left->val);
            walker = walker->left;
        }
        returnSize[i] = count->head->content;
        i++;
        pop(count);
        if (walker->right != NULL)
        {
            push(count, walker->right->val);
            walker = walker->right;
        }
    }
    return returnSize;
}
//не до конца закончено

// https://leetcode.com/problems/binary-tree-inorder-traversal/description/?envType=problem-list-v2&envId=binary-tree