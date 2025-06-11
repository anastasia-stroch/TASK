// https://leetcode.com/problems/search-in-a-binary-search-tree/

typedef struct s_tree
{
    int value;
    struct s_tree *left;
    struct s_tree *right;
} t_tree;

t_tree* searchBST(t_tree* root, int val) {
    while (root != NULL && root->value != val)
    {
        root = (root->value > val) ? root->left : root->right;
    }
    return root;
}
