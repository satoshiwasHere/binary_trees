#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - checks if a given node is a leaf node or not
 * @node: pointer to subject node
 * Return: 1 if node is a leaf,
 * 0 - otherwise. 0 - If node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL &&
		node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height -  calculates 8 returns the height of a binary tree
 * @tree: pointer to the subject tree root node of the tree
 *
 * Return: tree height. 0 - if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left =
		binary_tree_height(tree->left);
	right =
		binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the subject tree root node
 *
 * Return: 1 if perfect, 0 - otherwise, 0 - if NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *v, *x;

	if (tree == NULL)
		return (1);
	v =
		tree->left;
	x =
		tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (v == NULL || x == NULL)
		return (0);
	if (binary_tree_height(v)
	== binary_tree_height(x))
	{
		if (binary_tree_is_perfect(v) && binary_tree_is_perfect(x))
			return (1);
	}
	return (0);
}
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: pointer to the subject tree root node
 *
 * Return: if complete - 1, otherwise - 0 . 0 - if NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_height, r_height;
	binary_tree_t *v, *x;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	v =
		tree->left;
	x =
		tree->right;
	l_height = binary_tree_height(v);
	r_height = binary_tree_height(x);
	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(v) && binary_tree_is_complete(x))
			return (1);
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(v) && binary_tree_is_perfect(x))
			return (1);
	}
	return (0);
}
