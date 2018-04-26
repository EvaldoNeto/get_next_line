#include "./libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int check_newline(char *str)
{
  int i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

int leading_newline(char *str)
{
  int i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (i);
      i++;
    }
  return (-1);
}

int no_newline(const int fd, char *buff, char **line, int n)
{
  int i;

  *line = ft_strdup(buff);
  if(!(n = read(fd, buff, BUFF_SIZE)))
    return (0);
  while (!check_newline(buff))
    {
      if (n != 0)
	*line = ft_strjoin(*line, ft_strsub(buff, 0, n));
      if (n < BUFF_SIZE)
	{
	  free(buff);
	  buff = NULL;
	  return (0);
	}
      if(!(n = read(fd, buff, BUFF_SIZE)))
	return (0);
    }
  i = leading_newline(buff);
  *line = ft_strjoin(*line, ft_strsub(buff, 0, i));
  if (!check_newline(buff))
    {
      free(buff);
      buff = NULL;
    }
  else
    ft_memmove(buff, buff + i + 1, ft_strlen(buff + i));
  return (1);
}

void with_newline(char *buff, char **line)
{
  int i;

  i = leading_newline(buff);
  *line = ft_strsub(buff, 0, i);
  if (!check_newline(buff))
    {
      free(buff);
      buff = NULL;
    }
  else
    ft_memmove(buff, buff + i + 1, ft_strlen(buff + i));
}

int get_next_line(const int fd, char **line)
{
  static char *buff = NULL;
  int n;
  
  n = BUFF_SIZE;
  if (!buff)
    if (!(buff = (char *)ft_memalloc(sizeof(char *) * (BUFF_SIZE + 1))))
      return (-1);
  if (!(*buff))
    if(!(n = read(fd, buff, BUFF_SIZE)))
      return (0);
  if (!check_newline(buff))
    {
      if (!no_newline(fd, buff, line, n))
	return (0);
    }
  else
      with_newline(buff, line);   
  return (1);
}

static int compare_files(void *data1, void *data2)
{
  t_file x;
  t_file y;

  x = *(t_file *)data1;
  y = *(t_file *)data2;
  if (x.fd < y.fd)
    return (-1);
  else if(x.fd > y.fd)
    return (1);
  return (0);
}

static void print(void *data)
{
  t_file x;

  x = *(t_file *)data;
  ft_putnbr(x.fd);
}

int mopa(const int fd, char **line)
{
  static char *mozo = NULL;
  int n;

  n = BUFF_SIZE;
  if (!mozo)
    if (!(mozo = (char *)ft_memalloc(sizeof(char *) * (BUFF_SIZE + 1))))
      return (-1);
  if (!(*mozo))
    if(!(n = read(fd, mozo, BUFF_SIZE)))
      return (0);
  if (!check_newline(mozo))
    {
      if (!no_newline(fd, mozo, line, n))
	return (0);
    }
  else
      with_newline(mozo, line);   
  return (1);
}

int func2(void *data1, void *data2)
{
  if (!data1 && data2)
    return (-1);
  if (data2 && !data1)
    return (1);
  if (!data1 && !data2)
    return (0);
  if (*(int *)data1 < *(int *)data2)
    return (-1);
  else if (*(int *)data1 > *(int *)data2)
    return (1);
  return (0);
}
  
int main()
{
  t_file *file1;
  t_file *file2;
  t_file *file3;
  t_file *file4;
  t_file *file5;
  t_file *file6;
  
  file1 = (t_file *)malloc(sizeof(t_file));
  file2 = (t_file *)malloc(sizeof(t_file));
  file3 = (t_file *)malloc(sizeof(t_file));
  file4 = (t_file *)malloc(sizeof(t_file));
  file5 = (t_file *)malloc(sizeof(t_file));
  file6 = (t_file *)malloc(sizeof(t_file));
  file1->fd = 10;
  file2->fd = 20;
  file3->fd = 30;
  file4->fd = 40;
  file5->fd = 50;
  file6->fd = 25;

  t_btree *tree;

  tree = NULL;
  btree_insert_avl(&tree, file1, sizeof(t_file), &compare_files);
  btree_insert_avl(&tree, file2, sizeof(t_file), &compare_files);
  btree_insert_avl(&tree, file3, sizeof(t_file), &compare_files);
  btree_insert_avl(&tree, file4, sizeof(t_file), &compare_files);
  btree_insert_avl(&tree, file5, sizeof(t_file), &compare_files);
  btree_insert_avl(&tree, file6, sizeof(t_file), &compare_files);
  btree_print(tree, 0, &print);
  /*char **line;
  int fd;
  int i;
  int n;

  n = 0;
  i = 0;
  line = (char **)ft_memalloc(sizeof(char *));
  ft_putnbr(BUFF_SIZE);
  ft_putchar('\n');
  fd = open("tests/in_the_name", O_RDONLY);
  while (mopa(fd, line))
    {
      ft_putnbr(ft_strlen(*line));
      ft_putstr(":\t");
      ft_putstr(*line);
      ft_putchar('\n');
      i++;
      n+= ft_strlen(*line);
    }
  ft_putnbr(ft_strlen(*line));
  ft_putstr(":\t");
  ft_putstr(*line);
  ft_putchar('\n');*/

  /*t_btree *tree;
  int n;
  
  tree = btree_create_node("1", sizeof(char) + 1);
  tree->left = btree_create_node("2", sizeof(char) + 1);
  tree->left->left = btree_create_node("4", sizeof(char) + 1);
  tree->left->right = btree_create_node("5", sizeof(char) + 1);
  tree->right = btree_create_node("3", sizeof(char) + 1);
  //tree->right->right = btree_create_node("7", sizeof(char) + 1);
  tree->right->left = btree_create_node("7", sizeof(char) + 1);

  ft_putstr("height: ");
  ft_putnbr(btree_height(tree));
  ft_putstr("\n");
  if ((n = btree_node_level(tree, btree_create_node("3", sizeof(char) + 1), 1)))
    {
      ft_putstr("\nPORRA\n");
      ft_putnbr(n);
    }
  else
    {
      ft_putstr("\nCATIORRO\n");
      ft_putnbr(n);
    }
  ft_putchar('\n');
  btree_apply_postorder(tree, &func1);
  ft_putchar('\n');
  n = btree_height(tree);
  btree_print_level(tree, 2);
  ft_putchar('\n');
  btree_print_level(tree, 3);
  ft_putchar('\n');
  ft_putnbr(btree_nodes_per_level(tree, 3));
  ft_putchar('\n');

  t_btree **test;

  test = (t_btree **)malloc(sizeof(t_btree *) * (btree_nodes_per_level(tree, 3) + 1));
  btree_nodes_in_level(test, tree, 3);
  test[4] = NULL;
  int i = 0;
  while (test[i])
    {
      if (!(test[i]->data))
	ft_putstr("(null)");
      else
	ft_putstr(test[i]->data);
      i++;
    }
  ft_putstr("\n");
  btree_print(tree, 0);*/

   /* t_btree *tree;
  int n;

  n = 30;
  tree = btree_create_node(&n, sizeof(int));
  n = 5;
  btree_insert_data(tree, &n, sizeof(int), &func2);
  n = 35;
  btree_insert_data(tree, &n, sizeof(int), &func2);
  n = 32;
  btree_insert_data(tree, &n, sizeof(int), &func2);
  n = 40;
  btree_insert_data(tree, &n, sizeof(int), &func2);
  n = 45;
  btree_insert_data(tree, &n, sizeof(int), &func2);

  btree_print(tree, 0);
  ft_putstr("\n");
  tree = btree_left_rotate(tree);
  btree_print(tree, 0);
  tree = NULL;
  n = 10;
  btree_insert_avl(&tree, &n, sizeof(int), &func2);
  n = 20;
  btree_insert_avl(&tree, &n, sizeof(int), &func2);
  n = 30;
  btree_insert_avl(&tree, &n, sizeof(int), &func2);
  n = 40;
  btree_insert_avl(&tree, &n, sizeof(int), &func2);
  n = 50;
  btree_insert_avl(&tree, &n, sizeof(int), &func2);
  n = 25;
  btree_insert_avl(&tree, &n, sizeof(int), &func2);
  btree_print(tree, 0);
  ft_putstr("------------------------------\n");
  n = 50;
  if (btree_search_data(tree, &n, &func2))
    ft_putstr("\nACHOU!\n");
  else
    ft_putstr("\nSQN!\n");
    ft_putstr("\n");*/

  return (0);
}
