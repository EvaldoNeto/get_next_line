/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:19:50 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 23:22:08 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int no_newline(const int fd, char *buff, char **line, int n)
{
  int i;

  i = 0;
  *line = ft_strdup(buff);
  if((n = read(fd, buff, BUFF_SIZE)) == -1)
      return (-1);
  while (!ft_strchr(buff, '\n'))
  {
      if (n != 0)
	*line = ft_strjoin_free(*line, ft_strsub(buff, 0, n));
      if((n = read(fd, buff, BUFF_SIZE)) == - 1)
	return (-1);
      if (n < BUFF_SIZE)
	return (0);
  }
  i = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '\n'));
  *line = ft_strjoin_free(*line, ft_strsub(buff, 0, i));
  if (!ft_strchr(buff, '\n'))
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

  i = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '\n'));
  *line = ft_strsub(buff, 0, i);
  if (!ft_strchr(buff, '\n'))
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
  y = *(t_file *)data2;;
  if (x.fd < y.fd)
	  return (-1);
  else if(x.fd > y.fd)
	  return (1);
  return (0);
}

void print_fd(void *data1)
{
	t_file *temp;

	temp = (t_file *)data1;
	ft_putnbr(temp->fd);
}

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
  if (!ft_strchr(((t_file *)(node->data))->buffer, '\n'))
    {
      if (!(n = no_newline(fd, ((t_file *)(node->data))->buffer, line, n)) || n == -1)
	{
	  free(((t_file *)(node->data))->buffer);
	  ((t_file *)(node->data))->buffer = NULL;
	  if (n == -1)
	    free(*line);
	  return (n);
	}
    }
  else
    with_newline(((t_file *)(node->data))->buffer, line);   
  return (1);
}
