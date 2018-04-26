#include "libft.h"

t_btree *btree_right_rotate(t_btree *node)
{
  t_btree *x;
  t_btree *y;

  x = node->left;
  y = x->right;
  x->right = node;
  node->left = y;
  return (x);
}
