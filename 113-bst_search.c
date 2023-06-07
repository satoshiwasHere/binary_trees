#include "binary_trees.h"

/**
 * bst_search - function Searches for a value in a binary search tree.
 * @tree: pointer to the root node of the BST to search.
 * @value: Value to search for in the tree
 * Return: NULL - If the tree is null or nothing is found,
 * pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if
		(tree != NULL)
	{
		if
			(tree->n == value)
			return ((bst_t *)tree);
		if
			(tree->n > value)

			return (bst_search(tree->left, value));

		return (bst_search(tree->right, value));
	}

	return (NULL);
}
