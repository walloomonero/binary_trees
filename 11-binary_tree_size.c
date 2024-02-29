#include "binary_trees.h"

/**
 * binary_tree_size - A function that measures the size of a binary tree. 
 * @tree: Is a pointer to the root node of the tree to measure the size. 
 *
 * Returns: If tree is NULL, the function must return 0
 *			otherwise - size of a binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}
