#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function rotates binary tree right
 * @tree: pointer to the subject tree root node
 * Return: pointer to the new root node post rotation.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node, *xy;

	if (tree == NULL ||
	tree->left == NULL)
		return (NULL);

	node =
		tree->left;
	xy =
		node->right;
	node->right = tree;
	tree->left = xy;
	if (xy != NULL)
		xy->parent = tree;
	xy =
		tree->parent;
	tree->parent = node;
	node->parent = xy;
	if (xy != NULL)
	{
		if (xy->left == tree)
			xy->left = node;
		else
			xy->right = node;
	}

	return (node);
}
