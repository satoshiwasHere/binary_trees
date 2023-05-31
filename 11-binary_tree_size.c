/**
 * binary_tree_size - evaluates the size of a binary tree
 * @tree: pointer to binary root tree node
 *
 * Return: size of the tree, 0 - null
 *
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	return ((tree) ? (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1) : 0);
}
