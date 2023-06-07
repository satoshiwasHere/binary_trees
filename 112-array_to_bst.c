#include "binary_trees.h"

/**
 * array_to_bst - constructs binary search tree from an array
 * @array: pointer to the first element of the array for conversion
 * @size: no. of elements in @array.
 * Return: pointer to the created BST root node, or NULL - failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;

	size_t x, y;

	if (array == NULL)

		return (NULL);

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[y])
				break;
		}
		if (y == x)
		{
			if (bst_insert(&tree, array[x]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
