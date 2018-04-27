#include "libft.h"

static	t_btree	*rotate_left_right(t_btree **ptr)
{
	(*ptr)->left = btree_left_rotate((*ptr)->left);
	return (*ptr = btree_right_rotate((*ptr)));
}

static	t_btree	*rotate_right_left(t_btree **ptr)
{
	(*ptr)->right = btree_right_rotate((*ptr)->right);
	return (*ptr = btree_left_rotate((*ptr)));
}

static int btree_node_balance(t_btree *root)
{
  return (btree_height(root->left) - btree_height(root->right));
}

t_btree *btree_deletenode_avl(t_btree **root, void *data, int (*cmpf)(void *, void *), void (*del)(void *))
{
  int balance;
  t_btree *temp;

  if (!(*root))
    return (NULL);
  if ((*cmpf)(data, (*root)->data) < 0)
    (*root)->left = btree_deletenode_avl(&((*root)->left), data, cmpf, del);
  else if ((*cmpf)(data, (*root)->data) > 0)
    (*root)->right = btree_deletenode_avl(&((*root)->right), data, cmpf, del);
  else
    {
      if ((*root)->left == NULL || (*root)->right == NULL)
	{
	  temp = (((*root)->left) ? ((*root)->left) : ((*root)->right));
	  if (!temp)
	    {
	      temp = *root;
	      *root = NULL;
	    }
	  else
	    ft_memmove(*root, temp, sizeof(t_btree));
	  free(temp->data);
	  del(temp);
	}
      else
	{
	  temp = btree_min((*root)->right);
	  ft_memmove((*root)->data, temp->data, temp->data_size);	 
	  (*root)->right = btree_deletenode_avl(&(*root)->right, temp->data, cmpf, del);
	}
    }
  if (!(*root))
    return (*root);
  balance = btree_height((*root)->left) - btree_height((*root)->right);
  if (balance > 1 && btree_node_balance((*root)->left) >= 0)
    return (*root = btree_right_rotate((*root)));
  if (balance > 1 && btree_node_balance((*root)->left) < 0)
    return (rotate_left_right(root));
  if (balance < -1 && btree_node_balance((*root)->right) <= 0)
    return (*root = btree_left_rotate((*root)));
  if (balance < -1 && btree_node_balance((*root)->right) > 0)
    return (rotate_right_left(root));
  return (*root);
}
