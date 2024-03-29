#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a tree to the left
 *
 * @tree: Pointer to the node to rotate
 *
 * Return: Pointer to the new root of the tree or NULL if the tree is NULL or
 * the right child is NULL
 *
 * Description: Rotates a tree to the left.
 * The right child of @tree becomes the new root of the tree.
 * The left child of the new root becomes @tree's right child.
 * Updates the parent pointers accordingly.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *temp2;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	temp = tree->right;
	temp2 = temp->left;
	temp->left = tree;
	tree->right = temp2;

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
