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
    while (*)
}

int main()
{
    t_tree *root = /* NULL; */
    btree_node_new(7,
        btree_node_new(5, 
            btree_node_new(2, NULL, NULL),
            btree_node_new(6, NULL, NULL)),
        btree_node_new(14,
                        btree_node_new(9, NULL, NULL),
                        NULL));
    
    // btree_node_insert(&root, 7);
    // btree_node_insert(&root, 5);
    // btree_node_insert(&root, 14);
    // btree_node_insert(&root, 2);
    // btree_node_insert(&root, 6);
    // btree_node_insert(&root, 9);
    btree_node_insert(&root, 8);

    return 0;
}
