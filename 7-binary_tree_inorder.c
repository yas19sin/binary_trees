#include "binary_trees.h"

/**
 * binary_tree_inorder - Calls a function for each element of a binary tree
 * in in-order (LNR)
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Function to call on each element
 *
 * Traverses a binary tree in in-order (LNR), calling @func on each node
 * with its value as its sole argument. If @tree is NULL, does nothing.
 * If @func is NULL, behavior is undefined.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
