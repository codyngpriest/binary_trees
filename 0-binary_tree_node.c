#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new_node = NULL;

new_node = calloc(1, sizeof(binary_tree_t));

if (new_node == NULL)
return (NULL);

new_node->parent = parent;
new_node->n = value;

return (new_node);
}
