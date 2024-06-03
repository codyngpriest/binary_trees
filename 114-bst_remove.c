#include "binary_trees.h"

/**
 * bst_find_min - finds the minimum node in a BST
 * @tree: pointer to the root node of the BST
 * Return: pointer to the minimum node
 */
bst_t *bst_find_min(bst_t *tree)
{
while (tree->left != NULL)
tree = tree->left;
return (tree);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
bst_t *node, *successor, *temp;

if (root == NULL)
return (NULL);

node = bst_search(root, value);
if (node == NULL)
return (root);

if (node->left == NULL)
{
temp = node->right;
free(node);
return (temp);
}
if (node->right == NULL)
{
temp = node->left;
free(node);
return (temp);
}

successor = bst_find_min(node->right);
node->n = successor->n;
node->right = bst_remove(node->right, successor->n);

return (root);
}

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
if (tree == NULL)
return (NULL);

while (tree != NULL)
{
if (value == tree->n)
return ((bst_t *)tree);
else if (value < tree->n)
tree = tree->left;
else
tree = tree->right;
}

return (NULL);
}
