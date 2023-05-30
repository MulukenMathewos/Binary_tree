#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
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
}

/**
 * get_insertion_parent - Finds the parent node to insert a new node
 * @root: Root node of the Heap
 *
 * Return: Pointer to the parent node
 */
heap_t *get_insertion_parent(heap_t *root)
{
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
}

/**
 * heapify_up - Restores the Max Heap property by swapping nodes upward
 * @node: Node to start the heapify process
 */
void heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_values(&node->n, &node->parent->n);
        node = node->parent;
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
}
