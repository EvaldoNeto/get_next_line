#include "libft.h"

int btree_node_level(t_btree *root, t_btree *node, int level)
{
  if (root)
    {
      if (root == node)
	return (level);
      if (btree_node_level(root->left, node, level + 1))
	return btree_node_level(root->left, node, level + 1);
      if (btree_node_level(root->right, node, level + 1))
	return btree_node_level(root->right, node, level + 1);
    }
  return (0);
}
