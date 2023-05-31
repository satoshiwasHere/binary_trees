#include "binary_trees.h"

/**
 * binary_tree_height - evaluates the height of a binary tree
 * @tree: pointer to root node to draw height of tree
 *
 * Return: tree height or 0 if NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t x, y;

		x = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		y = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		if (x > y)
			return (x);
		else
			return (y);
	}
	return (0);
}
