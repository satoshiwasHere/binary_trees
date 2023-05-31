#include "binary_trees.h"

/**
 * binary_tree_balance - evaluate balance factor of binary tree
 * @tree: pointer to tree root node
 * Return: height or 0 - if NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0;

	if (tree)
		balance_factor = binary_tree_height(tree->left) -
			binary_tree_height(tree->right);

	return (balance_factor);
}

/**
 * binary_tree_height - evaluate height of binary tree
 * @tree: pointer to tree root node
 * Return: balanced factor, 0 - if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t x = 0, y = 0;

	if (tree != NULL)
	{
		x  = (tree->left != NULL) ? 1 + binary_tree_height(tree->left) : 1;
		y  = (tree->right != NULL) ? 1 + binary_tree_height(tree->right) : 1;
		return ((x > y) ? x : y);
	}
	return (0);
}
