#include "binary_trees.h"

/**
 * binary_tree_is_leaf - function checks if a node is a leaf
 * @node: node to be checked
 * return: if node is a leaf - 1, alternitely - 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (0);

	return (1);
}
