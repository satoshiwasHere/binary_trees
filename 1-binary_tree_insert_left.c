i#include "binary_trees.h"

/**
 * Description: If left_child already exits for parent,
 * new node takes its place and the old left-child 
 * replaced asthe left-child of the new node.
 *
 * binary_tree_insert_left - Inserts a node as a left-child of
 * @parent: A pointer to the node inserted to the left-child in.
 * @value: The value to store in the node.
 *Return: Null on failure or new node on success
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		node->left = parent->left;
		parent->left->parent = node;
	}
	parent->left = node;

	return (node);
}
