#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *find_leaf(const binary_tree_t *tree);
int is_perfect_recursively(const binary_tree_t *tree,
						   size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Checks if a node is a leaf in a binary tree.
 * @node: A pointer to the node to examine.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Finds the depth of a given node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of the node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * find_leaf - Finds and returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf node.
 */
const binary_tree_t *find_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? find_leaf(tree->left) : find_leaf(tree->right));
}

/**
 * is_perfect_recursively - Determines whether a binary
 *  tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: The level of the current node.
 *
 * Recursively checks if a binary tree is perfect,
 *  meaning that it is a complete
 * binary tree where all leaves are at the same depth,
 *  and all nodes at that depth
 * have as many children as they can hold.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int is_perfect_recursively(const binary_tree_t *tree,
						   size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursively(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursively(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Determines whether a binary tree is a perfect tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * A perfect binary tree is a binary tree where all of its leaves have the same
 * depth, and all nodes at that depth have as many children as they can hold.
 *
 * Return: If @tree is NULL or not a perfect tree, the function
 *			returns 0; otherwise, it returns 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	const size_t leaf_depth = depth(find_leaf(tree));

	return (is_perfect_recursively(tree, leaf_depth, 0));
}
