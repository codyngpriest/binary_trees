#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: input binary tree
 * Return: depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth = 0;

while (tree)
{
depth++;
tree = tree->parent;
}

return (depth);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 * Return: pointer to lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
binary_tree_t *node_a = (binary_tree_t *)first;
binary_tree_t *node_b = (binary_tree_t *)second;
size_t depth_a, depth_b;

if (!first || !second)
return (NULL);

depth_a = binary_tree_depth(node_a);
depth_b = binary_tree_depth(node_b);

for (; depth_b > depth_a; depth_b--)
node_b = node_b->parent;

for (; depth_a > depth_b; depth_b--)
node_a = node_a->parent;

while (node_a && node_b)
{
if (node_a == node_b)
return (node_a);

node_a = node_a->parent;
node_b = node_b->parent;
}

return (NULL);
}
