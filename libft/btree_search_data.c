#include "libft.h"

t_btree *btree_search_data(t_btree *root, void *data, int (*cmpf)(void *, void *))
{
  if (!root)
    return (NULL);
  if (cmpf(data, root->data) < 0)
    return (btree_search_data(root->left, data, cmpf));
  else if (cmpf(data, root->data) > 0)
    return (btree_search_data(root->right, data, cmpf));
  else
    return (root);
  return (NULL);
  
}
