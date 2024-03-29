#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	const binary_tree_t *temp, *temp2;

	if (first == NULL || second == NULL)
		return (NULL);

	temp = first;
	temp2 = second;

	while (temp != temp2)
	{
		temp = temp->parent ? temp->parent : second;
		temp2 = temp2->parent ? temp2->parent : first;
	}

	return ((binary_tree_t *)temp);
}
