#include "binary_trees.h"

/**
 * max - Finds the maximum node in a tree.
 * @tree: The pointer to the root of the tree.
 * Return: The node with the maximum value.
 */
heap_t *max(heap_t *tree)
{
<<<<<<< HEAD
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;

	/* If the root is the only node in the heap */
	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* Find the last level-order node to replace the root */
	heap_t *last_node = get_last_node(*root);

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	/* Replace the root with the last node */
	last_node->parent = NULL;
	last_node->left = (*root)->left;
	last_node->right = (*root)->right;
	if ((*root)->left)
		(*root)->left->parent = last_node;
	if ((*root)->right)
		(*root)->right->parent = last_node;

	free(*root);
	*root = last_node;

	/* Restore the Max Heap property */
	heapify_down(*root);
	return (value);
=======
	heap_t *curr_max, *left_max, *right_max;

	if (!tree->left)
		return (tree);
	left_max = max(tree->left);
	if (left_max->n > tree->n)
		curr_max = left_max;
	else
		curr_max = tree;
	if (tree->right)
	{
		right_max = max(tree->right);
		if (right_max->n > curr_max->n)
			curr_max = right_max;
		else
			curr_max = tree;
	}
	return (curr_max);
>>>>>>> 489e6b7fc8ce1e6f148cbffb89f113deb8f8f6d2
}

/**
 * recurse_extract - Recursively extracts the max from the tree.
 * @tree: The pointer to the root of the tree.
 */
void recurse_extract(heap_t *tree)
{
<<<<<<< HEAD
	size_t height = binary_tree_height(root);
	size_t index;

	/* Find the last level-order node */
	for (index = 1; index < height; index++)
	{
		size_t mask = 1 << (height - index - 1);

		if (root->left && !(index & mask))
			root = root->left;
		else if (root->right && (index & mask))
			root = root->right;
	}
	return (root);
=======
	heap_t *sub_max, *right_max = NULL;

	if (!tree->left)
		return;
	sub_max = max((tree)->left);
	if (tree->right)
		right_max = max(tree->right);
	if (right_max && right_max->n > sub_max->n)
		sub_max = right_max;
	tree->n = sub_max->n;
	if (!sub_max->left)
	{
		if (sub_max->parent && sub_max->parent->left == sub_max)
			sub_max->parent->left = NULL;
		if (sub_max->parent && sub_max->parent->right == sub_max)
			sub_max->parent->right = NULL;
		free(sub_max);
	}
	else
		recurse_extract(sub_max);
>>>>>>> 489e6b7fc8ce1e6f148cbffb89f113deb8f8f6d2
}

/**
 * heap_extract - Extracts the root from a Binary Heap.
 * @root: The pointer to the root of the tree.
 * Return: The value of the extracted node.
 */
<<<<<<< HEAD
void heapify_down(heap_t *node)
{
	heap_t *max_child;

	while (1)
	{
		if (node->left == NULL)
			break;

		max_child = node->left;

		if (node->right != NULL && node->right->n > node->left->n)
			max_child = node->right;
		if (max_child->n <= node->n)
			break;

		swap_values(&node->n, &max_child->n);
		node = max_child;
	}
}

/**
 * swap_values - Swaps two integer values
 * @a: Pointer to the first value
 * @b: Pointer to the second value
 */
void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
=======
int heap_extract(heap_t **root)
{
	int value;

	if (!*root)
		return (0);
	value = (*root)->n;
	if (!(*root)->left)
	{
		value = (*root)->n;
		free(*root);
		*root = NULL;
		return (value);
	}
	recurse_extract(*root);
	return (value);
>>>>>>> 489e6b7fc8ce1e6f148cbffb89f113deb8f8f6d2
}
