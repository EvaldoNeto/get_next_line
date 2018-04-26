#include "libft.h"

t_btree *btree_left_rotate(t_btree *node)
{
  t_btree *x;
  t_btree *y;

  x = node->right;
  y = x->left;
  x->left = node;
  node->right = y;
  return (x);
}
