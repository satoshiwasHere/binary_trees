#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function rotates left a binary tree.
 * @tree: pointer to the subject tree root node to rotate.
 * Return: pointer to the new root node post rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node, *xy;

	if (tree == NULL ||
	tree->right == NULL)
		return (NULL);

	node =
		tree->right;
	xy =
		node->left;
	node->left = tree;
	tree->right = xy;
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
