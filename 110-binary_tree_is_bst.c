#include "binary_trees.h"
#include "limits.h"
/**
 * is_bst_helper - Verifies if binary tree is a valid binary search tree
 * @tree: pointer to the root node of the tree to be examined
 * @lo: value of the lowest node traversed thus far
 * @hi: value of the highest node traversed thus far
 *
 * Return: 1 - if the tree is a legit BST; else - 0.
 */

int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo ||
		tree->n > hi)
			return (0);

		return (is_bst_helper(tree->left, lo, tree->n - 1)
			&& is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - verifies if a binary tree is a valid binary search tree
 * @tree: A pointer to the root node of the tree to be examined
 *
 * Return: 1 - if valid BST, 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
