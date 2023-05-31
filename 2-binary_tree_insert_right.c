#include "binary_trees.h"

/**
 * binary_tree_insert_right - function Inserts a node as the right-child
 * @parent: pointer to the node to insert the right-child in.
 * @value: value to store in the new node.
 *
 * Return: pointer to new node, or NULL on faliure
 *
 * Description: If right-child exists for parent, the new node
 * takes its place and the old right-child is set as the
 * right-child of the new node.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		node->right = parent->right;
		parent->right->parent = node;
	}
	parent->right = node;

	return (node);
}
