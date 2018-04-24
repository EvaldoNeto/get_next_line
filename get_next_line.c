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

int main()
{
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
  while (get_next_line(fd, line))
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

  t_btree *tree;
  int n;
  
  tree = btree_create_node("1", sizeof(char) + 1);
  tree->left = btree_create_node("2", sizeof(char) + 1);
  tree->left->left = btree_create_node("4", sizeof(char) + 1);
  tree->left->right = btree_create_node("5", sizeof(char) + 1);
  tree->right = btree_create_node("3", sizeof(char) + 1);

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
  btree_apply_postorder(tree, &ft_putstr);
  ft_putchar('\n');
  
  return (0);
}
