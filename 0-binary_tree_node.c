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
	binary_tree_t *new;

	if (value == '\0')

		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	new>parent = parent;
	new->n = value;
	new->right = NULL;
	new->left = NULL;

	return (new);
}
