#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as right-child of another node.
 * @parent: Is a pointer to the node to insert the right-child in.
 * @value: Is the value to store in the new.
 *
 * Return: a pointer to the created node
 *         Otherwise - NULL on failure or if parent is NULL
 *
 * Description: If parent already has a right-child, the new node
 *              takes its place and the old right-child is set as
 *              the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
