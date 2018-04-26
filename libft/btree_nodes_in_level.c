#include "libft.h"

void btree_nodes_in_level(t_btree **dest, t_btree *root, int level)
{
  static int i = 0;
  
  if (root)
    {
      if (level == 1)
	{
	  *(dest + i) = root;
	  i++;
	}
      btree_nodes_in_level(dest, root->left, level - 1);
      btree_nodes_in_level(dest, root->right, level - 1);
    }
}
