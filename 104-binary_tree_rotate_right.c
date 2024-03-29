#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a tree to the right
 *
 * @tree: Pointer to the node to rotate
 *
 * Return: Pointer to the new root of the tree or NULL if the tree is NULL or
 * the left child is NULL
 *
 * Description: Rotates a tree to the right.
 * The left child of @tree becomes the new root of the tree.
 * The right child of the new root becomes @tree's left child.
 * Updates the parent pointers accordingly.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp, *temp2;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	temp = tree->left;
	temp2 = temp->right;
	temp->right = tree;
	tree->left = temp2;

	if (temp2 != NULL)
		temp2->parent = tree;

	temp2 = tree->parent;
	tree->parent = temp;
	temp->parent = temp2;

	if (temp2 != NULL)
	{
		if (temp2->left == tree)
			temp2->left = temp;
		else
			temp2->right = temp;
	}

	return (temp);
}
