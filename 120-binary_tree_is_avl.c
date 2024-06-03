#include "binary_trees.h"

int is_avl_recursive(const binary_tree_t *tree, const binary_tree_t *min,
const binary_tree_t *max);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (is_avl_recursive(tree, NULL, NULL));
}

/**
 * is_avl_recursive - recursively checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the current node being checked
 * @min: pointer to the minimum node in the subtree
 * @max: pointer to the maximum node in the subtree
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int is_avl_recursive(const binary_tree_t *tree, const binary_tree_t *min,
const binary_tree_t *max)
{
int left_height, right_height;

if (tree == NULL)
return (1);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

if (abs(left_height - right_height) <= 1 &&
is_avl_recursive(tree->left, min, tree) &&
is_avl_recursive(tree->right, tree, max))
{
if ((min == NULL || tree->n > min->n) &&
(max == NULL || tree->n < max->n))
return (1);
}

return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (tree == NULL)
return (0);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return (MAX(left_height, right_height) + 1);
}
