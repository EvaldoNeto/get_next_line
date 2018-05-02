#include "./libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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
  temp.fd = fd;
  temp.buffer = NULL;
  if (!(node = btree_search_data(files, &temp, &compare_files)))
    node = btree_insert_avl(&files, &temp, sizeof(t_file), &compare_files);
  if (((t_file *)(node->data))->buffer == NULL)
    {
      if (!(((t_file *)(node->data))->buffer = ft_strnew((BUFF_SIZE + 1))))
	return (-1);
      n = read(fd, ((t_file *)(node->data))->buffer, BUFF_SIZE);
      if (n == 0)
	return (0);	
    }
  if (ft_strchr(((t_file *)(node->data))->buffer, '\n'))
    {
      int i;
      char *buff = ((t_file *)(node->data))->buffer;

      i = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '\n'));
      *line = ft_strjoin_free(*line, ft_strsub(buff, 0, i));
      ft_memmove(buff, buff + i + 1, ft_strlen(buff + i + 1) + 1);
      return (1);
    }
  else
    {
      char *buff = ((t_file *)(node->data))->buffer;
	
      *line = ft_strjoin_free(*line, buff);
      free(((t_file *)(node->data))->buffer);
      ((t_file *)(node->data))->buffer = NULL;
      gnl(fd, line);
    }
  return (1);
}
