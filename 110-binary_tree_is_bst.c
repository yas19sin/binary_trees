#include "binary_trees.h"
#include "limits.h"

/**
 * bst_checker - Recursive function to check if a subtree is a valid BST.
 * @tree: A pointer to the root node of the subtree to check.
 * @low: The minimum value allowed in the subtree.
 * @high: The maximum value allowed in the subtree.
 *
 * Return: 1 if the subtree rooted at @tree is a valid BST with all values
 * between @low and @high (inclusive), and 0 otherwise.
 */
int bst_checker(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (bst_checker(tree->left, low, tree->n - 1) &&
				bst_checker(tree->right, tree->n + 1, high));
	}

	return (1);
}

/**
 * binary_tree_is_bst - Check if a binary tree is a valid BST
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST (i.e. all values are between INT_MIN
 * and INT_MAX, and for any node, all values in the left subtree are less than
 * the node's value, and all values in the right subtree are greater than the
 * node's value), and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_checker(tree, INT_MIN, INT_MAX));
}
