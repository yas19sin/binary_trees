#include "binary_trees.h"

/**
 * compute_binary_tree_height - Computes the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height of.
 *
 * Returns the height of the binary tree, or 0 if the tree is empty.
 */
size_t compute_binary_tree_height(const binary_tree_t *tree)
{
	size_t left_subtree_height, right_subtree_height;

	if (tree == NULL)
		return (0);

	left_subtree_height = compute_binary_tree_height(tree->left);
	right_subtree_height = compute_binary_tree_height(tree->right);

	return (1 + (left_subtree_height > right_subtree_height
					 ? left_subtree_height
					 : right_subtree_height));
}

/**
 * traverse_binary_tree_level_order - Performs a function on
 * nodes at a specific level of a binary tree.
 * @tree: Pointer to the root of the tree.
 * @level: Level of the tree to perform a function on.
 * @func: Function to perform.
 *
 * Calls the given function on each node in the tree at the given level.
 */
void traverse_binary_tree_level_order(const binary_tree_t *tree, size_t level,
									  void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		traverse_binary_tree_level_order(tree->left, level - 1, func);
		traverse_binary_tree_level_order(tree->right, level - 1, func);
	}
}

/**
 * traverse_binary_tree_in_level_order - Traverses a binary tree
 * using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 *
 * Calls the given function on each node in the tree in level-order.
 */
void binary_tree_levelorder(const binary_tree_t *tree,
							void (*func)(int))
{
	size_t tree_height, level;

	if (tree == NULL || func == NULL)
		return;

	tree_height = compute_binary_tree_height(tree);

	for (level = 1; level <= tree_height; level++)
		traverse_binary_tree_level_order(tree, level, func);
}
