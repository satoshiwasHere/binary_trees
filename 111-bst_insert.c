#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in node of a Binary Search Tree.
 * @tree: double pointer to the root of the BST to add the value.
 * @value: value to be stored in the node
 * Return: pointer to the new node, NULL - on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *ab, *dc;

	if (tree != NULL)
	{
		ab = *tree;

		if (ab == NULL)
		{
			dc = binary_tree_node(ab, value);
			if (dc == NULL)
				return (NULL);

			return (*tree = dc);
		}

		if (value < ab->n)
		{
			if (ab->left != NULL)
				return (bst_insert(&ab->left, value));

			dc = binary_tree_node(ab, value);
			if (dc == NULL)
				return (NULL);
			return (ab->left = dc);
		}
		if (value > ab->n)
		{
			if (ab->right != NULL)
				return (bst_insert(&ab->right, value));

			dc = binary_tree_node(ab, value);
			if (dc == NULL)
				return (NULL);

			return (ab->right = dc);
		}
	}
	return (NULL);
}
