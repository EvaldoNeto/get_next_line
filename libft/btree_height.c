#include "libft.h"

int btree_height(t_btree *root)
{
  if (!root)
    return (0);
  return (1 + ft_max(btree_height(root->left), btree_height(root->right)));
}
