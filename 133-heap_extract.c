#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
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
}

/**
 * get_last_node - Finds the last node in the heap in level-order traversal
 * @root: Root node of the Heap
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
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
}

/**
 * heapify_down - Restores the Max Heap property by swapping nodes downward
 * @node: Node to start the heapify process
 */
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
}
