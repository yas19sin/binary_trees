#include "binary_trees.h"

/**
 * binary_tree_insert_right - Adds a node as right child of another node.
 * @parent: Parent node.
 * @value: Value to store in the new node.
 *
 * Returns: New node if successful, or NULL on failure.
 *
 * Description: If @parent already has a right child, the new node becomes
 * its right child and the old right child becomes the right child of the new
 * node. Otherwise, the new node is inserted as the right child of @parent.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);

	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}

	parent->right = new;

	return (new);
}
