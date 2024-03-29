#include "binary_trees.h"

/**
 * binary_tree_preorder - Calls a function for each element of a binary tree
 * in pre-order (NLR)
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Function to call on each element
 *
 * Traverses a binary tree in pre-order (NLR), calling @func on each node
 * with its value as its sole argument. If @tree is NULL, does nothing.
 * If @func is NULL, behavior is undefined.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
