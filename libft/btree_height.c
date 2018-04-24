#include "libft.h"

int btree_height(t_btree *root)
{
  t_btree *aux;

  aux = (t_btree *)malloc(sizeof(t_btree));
  ft_memmove(aux, root);
  if (!root)
    return (0);  
}
