/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:19:50 by eneto             #+#    #+#             */
/*   Updated: 2018/05/01 13:30:16 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


int gnl_2(const int fd, char **line, t_btree **files)
{
  t_file temp;
  t_btree *node;
  int n;

  if (!line)
    return (-1);
  temp.fd = fd;
  temp.buffer = NULL;
  if (!(node = btree_search_data(*files, &temp, &compare_files)))
    {
      btree_insert_avl(files, &temp, sizeof(t_file), &compare_files);
      node = btree_search_data(*files, &temp, &compare_files);
    }
  if (((t_file *)(node->data))->buffer == NULL)
    {
      if (!(((t_file *)(node->data))->buffer = ft_strnew((BUFF_SIZE + 1))))
	  return (-1);
      if((n = read(fd, ((t_file *)(node->data))->buffer, BUFF_SIZE)) == -1)
	{
	  free(((t_file *)(node->data))->buffer);
	  ((t_file *)(node->data))->buffer = NULL;
	  btree_deletenode_avl(files, &temp, &compare_files, &free);
	  return (-1);
	}
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

      *line = ft_strjoin_free(*line, buff);
      ((t_file *)(node->data))->buffer = NULL;
      gnl_2(fd, line, files);
    }
  return (1);
}

int			get_next_line(const int fd, char **line)
{
  static t_btree *files = NULL;
  int n;
  t_file temp;

  temp.fd = fd;
  temp.buffer = NULL;
  if (!line)
    return (-1);
  *line = ft_strdup("");
  n = (gnl_2(fd, line, &files));
  if (n == 0)
    btree_deletenode_avl(&files, &temp, &compare_files, &free);
  return (n);
}
