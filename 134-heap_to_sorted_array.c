#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the Heap
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t heap_size, i;

	if (heap == NULL || size == NULL)
		return (NULL);

	heap_size = binary_tree_size(heap);
	sorted_array = malloc(heap_size * sizeof(int));
	if (sorted_array == NULL)
		return (NULL);

	for (i = 0; i < heap_size; i++)
	{
		sorted_array[i] = heap->n;
		heap_extract(&heap);
	}
	*size = heap_size;
	return (sorted_array);
}
