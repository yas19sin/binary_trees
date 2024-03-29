#include "binary_trees.h"

/**
 * is_leaf - Determines whether a given node is a leaf in a binary tree
 * @node: Pointer to the node to examine
 *
 * A leaf node is a node that has no children. The NULL pointer is
 * considered a leaf node.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
int is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * binary_height - Computes the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the binary tree, or 0 if the tree is empty
 */
size_t binary_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = binary_height(tree->left);
	right = binary_height(tree->right);

	if (left >= right)
		return (1 + left);

	return (1 + right);
}

/**
 * binary_perfect - Checks if a binary tree is perfect (all levels are fully
 *                  filled and all leaves are at the same depth)
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If @tree is NULL, return 1.
 */
int binary_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (1);

	left = tree->left;
	right = tree->right;

	if (is_leaf(tree))
		return (1);

	if (left == NULL || right == NULL)
		return (0);

	if (binary_height(left) == binary_height(right))
	{
		if (binary_perfect(left) && binary_perfect(right))
			return (1);
	}

	return (0);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise. If @tree is NULL, return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t iSize, jSize;
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (0);

	if (is_leaf(tree))
		return (1);

	left = tree->left;
	right = tree->right;
	iSize = binary_height(left);
	jSize = binary_height(right);
	if (iSize == jSize)
	{
		if (binary_perfect(left) && binary_tree_is_complete(right))
			return (1);
	}
	else if (iSize == jSize + 1)
	{
		if (binary_tree_is_complete(left) && binary_perfect(right))
			return (1);
	}

	return (0);
}
