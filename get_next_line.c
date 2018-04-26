/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:19:50 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 22:51:43 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

  ft_putstr("c1\n");
  x = *(t_file *)data1;
  ft_putstr("c2\n");
  y = *(t_file *)data2;
  ft_putstr("c3\n");
  if (x.fd < y.fd)
  {
	  ft_putstr("c4\n");
	  return (-1);
  }
  else if(x.fd > y.fd)
  {
	  ft_putstr("c4\n");
	  return (1);
  }
  ft_putstr("c4\n");
  return (0);
}

int get_next_line(const int fd, char **line)
{
  static t_btree *files = NULL;
  t_file temp;
  int n;
  t_btree *node;

  temp.fd = fd;
  temp.buffer = NULL;
  ft_putstr("1\n");
  if (!(node = btree_search_data(files, &temp, &compare_files)))
    {
		ft_putstr("2\n");
		btree_insert_avl(&files, &temp, sizeof(t_file), &compare_files);
		ft_putstr("3\n");
		node = btree_search_data(files, &temp, &compare_files);
    }
  n = BUFF_SIZE;
  if (!((t_file *)(node->data))->buffer)
    if (!(((t_file *)(node->data))->buffer = (char *)ft_memalloc(sizeof(char *) * (BUFF_SIZE + 1))))
      return (-1);
  if (!check_newline(((t_file *)(node->data))->buffer))
    {
      if (!no_newline(fd, ((t_file *)(node->data))->buffer, line, n))
	return (0);
    }
  else
    with_newline(((t_file *)(node->data))->buffer, line);   
  return (1);
}
