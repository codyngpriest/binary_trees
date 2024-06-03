#include "binary_trees.h"

avl_t *balance_subtree(avl_t *node);
avl_t *rebalance(avl_t *node, avl_t **tree);

/**
 * balance_subtree - Balances a subtree rooted at 'node'
 * @node: Pointer to the root of the subtree
 * Return: Pointer to the new root of the balanced subtree
 */
avl_t *balance_subtree(avl_t *node)
{
avl_t *new_root;

	/* Left heavy case */
if (binary_tree_balance(node) > 1)
{
if (binary_tree_balance(node->left) < 0)
node->left = binary_tree_rotate_left(node->left);
new_root = binary_tree_rotate_right(node);
}
	/* Right heavy case */
else if (binary_tree_balance(node) < -1)
{
if (binary_tree_balance(node->right) > 0)
node->right = binary_tree_rotate_right(node->right);
new_root = binary_tree_rotate_left(node);
}
/* Already balanced */
else
new_root = node;

return (new_root);
}

/**
 * rebalance - Rebalances the tree after insertion
 * @node: Pointer to the node where rebalancing is needed
 * @tree: Double pointer to the root of the tree
 * Return: Pointer to the input node
 */
avl_t *rebalance(avl_t *node, avl_t **tree)
{
avl_t *tmp, *root;
int bal;

tmp = node;
while (tmp)
{
bal = binary_tree_balance(tmp);
/* Left heavy, rebalance to right */
if (bal == 2)
{
root = balance_subtree(tmp);
if (root)
*tree = root;
}
/* Right heavy, rebalance to left */
else if (bal == -2)
{
root = balance_subtree(tmp);
if (root)
*tree = root;
}
tmp = tmp->parent;
}
return (node);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root of the tree
 * @value: Input value
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
avl_t *new_node, *node;

if (!tree)
return (NULL);

new_node = calloc(1, sizeof(avl_t));
if (!new_node)
return (NULL);

new_node->n = value;

if (!*tree)
return (*tree = new_node);

node = *tree;
while (node)
{
/* Duplicate value, return NULL */
if (value == node->n)
return (free(new_node), NULL);

if (value < node->n)
{
if (node->left == NULL)
{
node->left = new_node;
new_node->parent = node;
return (rebalance(node->left, tree));
}
node = node->left;
}
else
{
if (node->right == NULL)
{
node->right = new_node;
new_node->parent = node;
return (rebalance(node->right, tree));
}
node = node->right;
}
}
return (free(new_node), NULL);
}
