#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is the root of its tree
 *
 * @node: Pointer to the node to check
 *
 * Return: 1 if @node is the root of its tree, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
