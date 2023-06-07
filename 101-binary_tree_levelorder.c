#include "binary_trees.h"

/**
 * binary_tree_height - evaluates height of binary tree
 * @tree: pointer to the root node of subject tree
 *
 * Return: tree height . 0 if NULL
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
 * binary_tree_level - level-order traverse function on binary tree
 * @tree: pointer to subject tree root
 * @l: specific tree level
 * @func: pointer to call function to node
 *
 * Return: 0
 */
void binary_tree_level(const binary_tree_t *tree, size_t l, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (l == 1)
		func(tree->n);
	else if (l > 1)
	{
		binary_tree_level(tree->left,
			l - 1, func);
		binary_tree_level(tree->right,
			l - 1, func);
	}
}

/**
 * binary_tree_levelorder - traverses binary tree using level-order traversal
 * @tree: pointer to the root node of subject tree
 * @func: function pointer to call for each node.
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
        size_t height, j;

        if (tree == NULL || func == NULL)
                return;

        height = binary_tree_height(tree);
        for (j = 1; j <= height; j++)
                binary_tree_level(tree, j, func);
}

