#include "binary_trees.h"

/**
 * height - measures the height of a tree
 *
 * @tree: tree root
 * Return: height
 */
int height(const binary_tree_t *tree)
{
<<<<<<< HEAD
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	/* Create a new node */
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	/* If the heap is empty, make the new node the root */
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	/* Find the correct position to insert the new node */
	parent = get_insertion_parent(*root);
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	/* Restore the Max Heap property */
	heapify_up(new_node);
	return (new_node);
=======
	int left = 0;
	int right = 0;

	if (tree == NULL)
		return (-1);

	left = height(tree->left);
	right = height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
>>>>>>> 489e6b7fc8ce1e6f148cbffb89f113deb8f8f6d2
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: tree root
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
<<<<<<< HEAD
	size_t height, index;

	height = binary_tree_height(root);

	/* Find the next available position in the heap */
	for (index = 1; index <= height; index++)
	{
		size_t mask = 1 << (height - index);

		if (index == height)
			break;

		if (root->left && !(index & mask))
			root = root->left;
		else if (root->right && (index & mask))
			root = root->right;
	}
	return (root);
=======
	if (tree && height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);

		if ((tree->left && !((tree->left)->left) && !((tree->left)->right))
		    && (tree->right && !((tree->right)->left) && !((tree->right)->right)))
			return (1);

		if (tree && tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
>>>>>>> 489e6b7fc8ce1e6f148cbffb89f113deb8f8f6d2
}

/**
 * swap - swaps nodes when child is greater than parent
 *
 * @arg_node: parent node
 * @arg_child: child node
 * Return: no return
 */
void swap(heap_t **arg_node, heap_t **arg_child)
{
<<<<<<< HEAD
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(&node->n, &node->parent->n);
		node = node->parent;
=======
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *arg_node, child = *arg_child;
	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;
		node_left = child->left, node_right = child->right;
		if (left_right == 0)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		}
		else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *arg_node = child;
>>>>>>> 489e6b7fc8ce1e6f148cbffb89f113deb8f8f6d2
	}
}

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @value: value to be inserted
 * @root: tree root
 * Return: pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
<<<<<<< HEAD
	int temp = *a;
	*a = *b;
	*b = temp;
=======
	heap_t *new_node;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new_node = heap_insert(&((*root)->left), value);
			swap(root, &((*root)->left));
			return (new_node);
		}
		else
		{
			new_node = (*root)->left = binary_tree_node(*root, value);
			swap(root, &((*root)->left));
			return (new_node);
		}
	}

	if ((*root)->right)
	{
		new_node = heap_insert(&((*root)->right), value);
		swap(root, (&(*root)->right));
		return (new_node);
	}
	else
	{
		new_node = (*root)->right = binary_tree_node(*root, value);
		swap(root, &((*root)->right));
		return (new_node);
	}

	return (NULL);
>>>>>>> 489e6b7fc8ce1e6f148cbffb89f113deb8f8f6d2
}
