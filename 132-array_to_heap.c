#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree
 *
<<<<<<< HEAD
 * Return: Pointer to the root node of the created
 * Binary Heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (heap_insert(&root, array[i]) == NULL)
		{
			binary_tree_delete(root);
			return (NULL);
		}
	}
	return (root);
=======
 * @array: pointer to the first element of the array
 * @size: number of element in the array
 * Return: pointer to the root node of the AVL tree
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree;
	size_t i;

	tree = NULL;

	for (i = 0; i < size; i++)
	{
		heap_insert(&tree, array[i]);
	}

	return (tree);
>>>>>>> 489e6b7fc8ce1e6f148cbffb89f113deb8f8f6d2
}
