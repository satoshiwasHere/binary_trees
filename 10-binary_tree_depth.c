/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 - if NULL, else return the depth.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
	{
	return (1 + binary_tree_depth(tree->parent));
	}
	else
	{
		return (0);
	}
}
