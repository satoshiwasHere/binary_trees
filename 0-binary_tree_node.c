#include "binary_trees.h"

/**
 * binary_tree_node - creates new binary tree node
 *
 * @parent: pointer to parent binary trees
 * @value: value of new node
 * Return: null on faliure, success = new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (value == '\0')

		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)

		return (NULL);

	node->parent = parent;
	node->n = value;
	node->right = NULL;
	node->left = NULL;

	return (node);
}
