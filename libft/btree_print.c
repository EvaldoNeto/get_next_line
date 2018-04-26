#include "libft.h"

static void print_spaces(int n)
{
  int i;

  while (i < n)
    {
      ft_putstr(" ");
      i++;
    }
}

void btree_print(t_btree *root, int n, void (*print)(void *))
{
  static int spaces = 10;
  
  if (root)
    {
      n += spaces;
      btree_print(root->right, n, print);
      ft_putstr("\n");
      print_spaces(n - spaces);
      (*print)(root->data);
      ft_putstr("\n");
      btree_print(root->left, n, print);
    }
}
