#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to root of tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t *new_node = NULL, *current_node;

if (tree == NULL)
return (NULL);

new_node = calloc(1, sizeof(bst_t));
if (new_node == NULL)
return (NULL);
new_node->n = value;

if (*tree == NULL)
{
*tree = new_node;
return (new_node);
}

current_node = *tree;
while (1)
{
if (value == current_node->n)
{
free(new_node);
return (NULL);
}
if (value < current_node->n)
{
if (current_node->left == NULL)
{
new_node->parent = current_node;
return (current_node->left = new_node);
}
current_node = current_node->left;
} 
else
{
if (current_node->right == NULL)
{
new_node->parent = current_node;
return (current_node->right = new_node);
}
current_node = current_node->right;
}
}
}
