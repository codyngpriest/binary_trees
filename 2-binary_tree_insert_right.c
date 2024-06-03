#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the parent node
 * @value: The value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *new_right_child = NULL;

if (!parent)
return (NULL);

new_right_child = calloc(1, sizeof(binary_tree_t));
if (!new_right_child)
return (NULL);

new_right_child->n = value;
new_right_child->parent = parent;
new_right_child->left = NULL;

if (parent->right)
{
new_right_child->right = parent->right;
new_right_child->right->parent = new_right_child;
}
else
{
new_right_child->right = NULL;
}

parent->right = new_right_child;

return (new_right_child);
}
