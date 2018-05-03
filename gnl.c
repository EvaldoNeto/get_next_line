#include "./libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void print_aux(char *s, int n)
{
  if (s)
    {
      int i;

      i = 0;
      while (i < n)
	{
	  if (s[i] == '\n')
	    ft_putstr("n");
	  else if (s[i] == '\0')
	    ft_putstr("0");
	  else
	    ft_putchar(s[i]);
	  i++;
	}
    }
  ft_putstr("\n");
}

static int	compare_files(void *data1, void *data2)
{
	t_file x;
	t_file y;

	x = *(t_file *)data1;
	y = *(t_file *)data2;
	if (x.fd < y.fd)
		return (-1);
	else if (x.fd > y.fd)
		return (1);
	return (0);
}

int gnl(const int fd, char **line)
{
  static t_btree *files = NULL;
  t_file temp;
  t_btree *node;
  int n;

  if (!line)
    return (-1);
  *line = ft_strdup("");
  temp.fd = fd;
  temp.buffer = NULL;
  if (!(node = btree_search_data(files, &temp, &compare_files)))
    node = btree_insert_avl(&files, &temp, sizeof(t_file), &compare_files);
  if (((t_file *)(node->data))->buffer == NULL)
    {
      if (!(((t_file *)(node->data))->buffer = ft_strnew((BUFF_SIZE + 1))))
	return (-1);
      if((n = read(fd, ((t_file *)(node->data))->buffer, BUFF_SIZE)) == - 1)
	return (-1);
      if (n < BUFF_SIZE)
	(((t_file *)(node->data))->buffer)[n] = '\0';
      if (n == 0)
	{
	  free(((t_file *)(node->data))->buffer);
	  ((t_file *)(node->data))->buffer = NULL;
	  return (0);
	}
    }  
  if (ft_strchr(((t_file *)(node->data))->buffer, '\n'))
    {
      int i;
      char *buff = (((t_file *)(node->data))->buffer);
      
      i = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '\n'));
      char *tmp = ft_strsub(buff, 0, i);
      *line = ft_strjoin_free(*line, tmp);
      ft_memmove((((t_file *)(node->data))->buffer), (((t_file *)(node->data))->buffer) + i + 1, ft_strlen((((t_file *)(node->data))->buffer) + i + 1) + 1);
      if (buff[0] == '\0')
	{
	  free(((t_file *)(node->data))->buffer);
	  ((t_file *)(node->data))->buffer = NULL;
	}
      return (1);
    }
  else
    {
      char *buff = ((t_file *)(node->data))->buffer;

      while (!ft_strchr(((t_file *)(node->data))->buffer, '\n') && n != 0)
	{
	  *line = ft_strjoin_free(*line, buff);
	  if ((n = read(fd, buff, BUFF_SIZE)) == - 1)
	    return (-1);	  
	}
      int i = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '\n'));
      char *tmp = ft_strsub(buff, 0, i);
      *line = ft_strjoin_free(*line, tmp);
      ft_memmove((((t_file *)(node->data))->buffer), (((t_file *)(node->data))->buffer) + i + 1, ft_strlen((((t_file *)(node->data))->buffer) + i + 1) + 1);

      if (buff[0] == '\0')
	{
	  if (*((t_file *)(node->data))->buffer)
	    free(((t_file *)(node->data))->buffer);
	  ((t_file *)(node->data))->buffer = NULL;
	}
      return (1);
    }
  return (1);
}
