#include "libft.h"

void btree_print_level(t_btree *root, int level)
{
  if (root)
    {
      if (level == 1)
	  ft_putstr(root->data);
      else if (level > 1)
	{
	  btree_print_level(root->left, level - 1);
	  btree_print_level(root->right, level - 1);
	}
    }
  else
      ft_putstr("(null)");
}
