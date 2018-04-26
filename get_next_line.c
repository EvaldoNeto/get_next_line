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
  if((n = read(fd, buff, BUFF_SIZE)) == -1)
    {
      ft_putstr("PRIMEIRO IF\n");
      *line = NULL;
      return (-1);
    }
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
      if((n = read(fd, buff, BUFF_SIZE)) == - 1)
	{
	  ft_putstr("SEGUNDO IF\n");
	  *line = NULL;
	  return (-1);
	}
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


/*static void print_fd(void *data)
{
  t_file x;

  x = *(t_file *)data;
  ft_putnbr(x.fd);
}

static void print_buffer(void *data)
{
  t_file x;

  x = *(t_file *)data;
  ft_putstr(x.buffer);
  }*/

int get_next_line(const int fd, char **line)
{
  static t_btree *files = NULL;
  t_file temp;
  int n;
  t_btree *node;

  temp.fd = fd;
  temp.buffer = NULL;
  if (!(node = btree_search_data(files, &temp, &compare_files)))
    {
      btree_insert_avl(&files, &temp, sizeof(t_file), &compare_files);
      node = btree_search_data(files, &temp, &compare_files);
    }
  n = BUFF_SIZE;
  if (!((t_file *)(node->data))->buffer)
    if (!(((t_file *)(node->data))->buffer = (char *)ft_memalloc(sizeof(char *) * (BUFF_SIZE + 1))))
      return (-1);
  /*if (!(*((t_file *)(node->data))->buffer))
    if((n = read(fd, ((t_file *)(node->data))->buffer, BUFF_SIZE)) == -1)
    return (-1);*/
  if (!check_newline(((t_file *)(node->data))->buffer))
    {
      if (!no_newline(fd, ((t_file *)(node->data))->buffer, line, n))
	return (0);
    }
  else
    with_newline(((t_file *)(node->data))->buffer, line);   
  return (1);
}
  
int main()
{
  char **line;
  int fd1;
  int fd2;
  int fd3;
  int fd4;
  int i;
  int n;

  n = 0;
  i = 0;
  line = (char **)ft_memalloc(sizeof(char *));
  ft_putnbr(BUFF_SIZE);
  ft_putchar('\n');
  fd1 = open("tests/in_the_name", O_RDONLY);
  fd2 = open("tests/draft_browns", O_RDONLY);
  fd3 = open("tests/game_of_thrones", O_RDONLY);
  fd4 = open("tests/inorder_traversal", O_RDONLY);

  get_next_line(fd1, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd2, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd1, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd3, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd4, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd1, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd1, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd3, line);
  ft_putstr(*line);
  ft_putstr("\n\n");

  get_next_line(-42, line);
  while (get_next_line(fd1, line))
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
  ft_putchar('\n');

  while (get_next_line(fd2, line))
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
  ft_putchar('\n');

  char temp[10];
  int k;

  k = read(-42, temp, 10);
  ft_putnbr(k);
  ft_putchar('\n');
  return (0);
}
