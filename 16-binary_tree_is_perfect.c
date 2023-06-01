#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);

/**
 * is_leaf - Checks if node is a binary tree leaf.
 * @node: pointer to node to be checked
 * Return: If node is a leaf - 1 or otherwise - 0
 */

unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Returns the depth of a given node
 * @tree: pointer to the node measuring the depth
 * Return: depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * binary_tree_is_perfect - Evaluates if binary tree is perfect.
 * @tree: pointer to the root node of the tree.
 * Return: 0 if perfect or Nul, 1 - otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

/**
 * get_leaf - Returns a leaf of binary tree.
 * @tree: pointer to the root node of the tree
 * Return: pointer to the first leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == true)
		return (tree);

	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - evaluates if a binary tree is perfect recursively
 * @tree: pointer to the root node of the tree
 * @leaf_depth: depth of a leaf in the binary tree
 * @level: Level of current node
 * Return: 1 - if perfect, 0  - otherwise.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (level == leaf_depth ? 1 : 0);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}
