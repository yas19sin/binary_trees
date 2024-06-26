#include "binary_trees.h"

/**
 * is_leaf - determines whether a given node is a leaf in a binary tree
 * @node: pointer to the node to examine
 *
 * Return: 1 if node is a leaf, 0 otherwise
 */
static inline unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree to measure the depth
 *
 * Return: the depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * find_leaf - finds the leftmost leaf in a binary tree
 * @tree: pointer to the root node of the tree to search
 *
 * Return: pointer to the leftmost leaf node in the tree, or NULL if
 * the tree is empty
 */
const binary_tree_t *find_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? find_leaf(tree->left)
					   : find_leaf(tree->right));
}

/**
 * is_perfect_recursively - checks if a binary tree is perfect recursively
 *
 * @tree: the tree to check
 * @leaf_depth: the depth of the leftmost leaf
 * @level: the current level of the subtree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
static int is_perfect_recursively(const binary_tree_t *tree,
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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_perfect_recursively(tree, binary_tree_depth(find_leaf(tree)), 0));
}
