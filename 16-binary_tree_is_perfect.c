#include "binary_trees.h"

/**
 * is_leaf - determines whether a given node is a leaf in a binary tree
 * @node: pointer to the node to examine
 *
 * Return: 1 if node is a leaf, 0 otherwise
 */
static inline unsigned char is_leaf(const binary_tree_t *node)
{
	return (node->left == NULL && node->right == NULL);
}

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree to measure the depth
 *
 * Return: the depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return (tree->parent ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * binary_tree_find_leaf - finds the leftmost leaf in a binary tree
 * @tree: pointer to the root node of the tree to search
 *
 * Return: pointer to the leftmost leaf node in the tree, or NULL if
 * the tree is empty
 */
const binary_tree_t *binary_tree_find_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree))
		return (tree);

	if (tree->left)
		return (binary_tree_find_leaf(tree->left));

	return (binary_tree_find_leaf(tree->right));
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
	/* If the node is a leaf, it must be at the expected level. */
	if (is_leaf(tree))
		return (level == leaf_depth);

	/* If the node is not a leaf, both children must exist. */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Both children must also be perfect at the next level down. */
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

	const size_t leaf_depth = binary_tree_depth(binary_tree_find_leaf(tree));

	return (is_perfect_recursively(tree, leaf_depth, 0));
}
