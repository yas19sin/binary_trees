#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a binary tree and its nodes
 *
 * @tree: Pointer to the root node of the tree to delete
 *
 * Traverses the tree in pre-order, deleting each node and all of its
 * children. Once the tree is empty, the root node is freed.
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
}
