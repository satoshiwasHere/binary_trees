#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with atleast 1 child in a binary tree
 * @tree: pointer to the root node
 *
 * Return: 0 - NULL, number of counted nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t items = 0;

	if (tree)
	{
		items += (tree->left || tree->right) ? 1 : 0;
		items += binary_tree_nodes(tree->left);
		items += binary_tree_nodes(tree->right);
	}
	return (items);
}
