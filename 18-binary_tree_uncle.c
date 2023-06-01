#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of binary tree node
 * @node: pointer to the node to find the uncle
 *
 * Return: 0 - NULL or has no uncle,
 * pointer to the uncle node - otherwise
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
