#include "libft.h"

int btree_nodes_per_level(t_btree *root, int level)
{
  if (root)
    {
      if (level == 1)
	return (1 + btree_nodes_per_level(root, level - 1));
      if (level == 0)
	return (0);
      return (btree_nodes_per_level(root->left, level - 1) + btree_nodes_per_level(root->right, level - 1));      
    }
  return (0);
}
