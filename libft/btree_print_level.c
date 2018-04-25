#include "libft.h"

/*static void print_spaces(int n)
{
  int i;

  i = ft_power(2, n);
  if (n == 0)
    return ;
  while(i > 0)
    {
      ft_putstr(" ");
      i--;
    }
    }*/

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
