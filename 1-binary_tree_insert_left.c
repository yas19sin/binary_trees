#include "binary_trees.h"

/**
 * binary_tree_insert_left - Adds a node as left child of another node.
 * @parent: Parent node.
 * @value: Value to store in the new node.
 *
 * Return: New node if successful, or NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);

	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}

	parent->left = new;

	return (new);
}
