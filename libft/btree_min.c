#include "libft.h"

t_btree *btree_min(t_btree *root)
{
  if (!root)
    return (NULL);
  while (root->left)
    root = root->left;
  return (root);
}
