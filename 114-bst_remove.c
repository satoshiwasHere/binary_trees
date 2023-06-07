#include "binary_trees.h"
/**
 * successor - returns min value of BST
 * @node: tree to be check
 *
 * Return: the minimum value of the tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)

		{
			return (node->n);
		}
		return (left);
	}
}
/**
 * two_children - gets the next successor
 * value in the right-side subtree,
 * replace the node value for successor
 * @root: node that has 2 children
 *
 * Return: value found
 */
int two_children(bst_t *root)
{
	int new_v = 0;

	new_v = successor(root->right);
	root->n = new_v;
	return (new_v);
}
/**
 * remove_type - removes a node depending on children
 * @root: node to be removed
 *
 * Return: 0 - if no children, alternative value
 */
int remove_type(bst_t *root)
{
	if (!root->left &&
			!root->right)
	{
		if
			(root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) ||
			(!root->right && root->left))
	{
		if
			(!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);

		return (0);
	}
	else
		return (two_children(root));
}
/**
 * bst_remove - deletes node from a tree
 * @root: pointer to root node
 * @value: node with the value to be removed
 *
 * Return: tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int ty = 0;

	if
		(root == NULL)
		return (NULL);
	if
		(value < root->n)
		bst_remove(root->left, value);
	else if
		(value > root->n)
		bst_remove(root->right, value);
	else if
		(value == root->n)
	{
		ty = remove_type(root);
		if (ty != 0)
			bst_remove(root->right, ty);
	}
	else
		return (NULL);
	return (root);
}
