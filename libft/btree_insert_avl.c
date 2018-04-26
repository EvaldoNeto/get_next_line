#include "libft.h"

t_btree *btree_insert_avl(t_btree *root, void * data, size_t data_size, int (*cmpf)(void *, void *))
{
  int balance;

  if (!root)
    return (btree_create_node(data, data_size));
  if ((*cmpf)(data,root->data) < 0)
    root->left = btree_insert_avl(root->left, data, data_size, cmpf);
  else if((*cmpf)(data, root->data) > 0)
    root->right = btree_insert_avl(root->right, data, data_size, cmpf);
  else
    return (root);
  balance = btree_height(root->left) - btree_height(root->right);
  if (balance > 1 && (*cmpf)(data, root->left->data))
    return (btree_right_rotate(root));
  if (balance < -1 && (*cmpf)(data, root->right->data) > 0)
    return (btree_left_rotate(root));
  if (balance > 1 && (*cmpf)(data, root->left->data) > 0)
    {
      root->left = btree_left_rotate(root->left);
      return (btree_right_rotate(root));
    }
  if (balance < 1 && (*cmpf)(data, root->right->data) < 0)
    {
      root->right = btree_right_rotate(root->right);

      return (btree_left_rotate(root));
    }
  return (root);
}

