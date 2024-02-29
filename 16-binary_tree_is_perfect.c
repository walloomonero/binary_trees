#include "binary_trees.h"


const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
							size_t leaf_depth, size_t level);
unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);							
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - This Checks if a node is a leaf of a binary tree.
 * @node: is a pointer to the node to check.
 *
 * Returns: If the node is a leaf, return 1
 *			 otherwise, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - To return the depth of a given
 *         node in a binary tree.
 * @tree: Is a pointer to the node to measure the depth of.
 *
 * Returns: Depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - To return a leaf of a binary tree.
 * @tree: Is a pointer to the root node of the tree to find a leaf in.
 *
 * Returns: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - This checks if a binary tree is perfect recursively.
 * @tree: Is a pointer to the root node of the tree to check.
 * @leaf_depth: Is the depth of one leaf in the binary tree.
 * @level: The level of the current node.
 *
 * Returns: If the tree is perfect, rertun 1
 * 			otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - A function that checks if a binary tree is perfect
 * @tree: Is a pointer to the root node of the tree to check
 *
 * Returns: If tree is NULL, your function must return 0 
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
