#include "binary_trees.h"

/**
 * binary_tree_delete - function deletes a binary tree.
 * @tree: points to the root node of the tree to delete.
 *
 * descp: do nothing if tree = NULL
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
