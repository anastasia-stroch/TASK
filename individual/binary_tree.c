#include <stdlib.h>

typedef struct s_tree
{
    int value;
    struct s_tree *left;
    struct s_tree *right;
} t_tree;

t_tree *btree_node_new(int value, t_tree *left, t_tree *right)
{
    t_tree *node = (t_tree*)malloc(sizeof(t_tree));
    if (node)
    {
        node->value = value;
        node->right = right;
        node->left = left;
    }
    return node;
}

void btree_node_insert(t_tree **root, int value)
{
    t_tree *prev;
    t_tree *walker;
    t_tree *node;

    if (root == NULL)
    {
        return ;
    }

    walker = *root;
    node = btree_node_new(value, NULL, NULL);
    if (walker == NULL)
    {
        *root = node;
        return ;
    }
    while (walker != NULL)
    {
        prev = walker;
        if (value > walker->value)
        {
            walker = walker->right;
        }
        else if (value < walker->value)
        {
            walker = walker->left;
        }
    }
    if (value > prev->value)
    {
        prev->right = node;
    }
    else if (value < prev->value)
    {
        prev->left = node;
    }
}
