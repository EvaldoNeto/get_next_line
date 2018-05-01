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

static int	with_newline(char *buff, char **line)
{
	int i;

	i = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '\n'));
	*line = ft_strsub(buff, 0, i);
	ft_memmove(buff, buff + i + 1, ft_strlen(buff + i + 1) + 1);
	return (1);
}

static int	no_newline(const int fd, char *buff, char **line)
{
	int i;
	int n;

	n = 1;
	i = 0;
	*line = ft_strdup(buff);
	while (((n = read(fd, buff, BUFF_SIZE)) != 0))
	{
		if (n == -1)
			return (-1);
		if (n < BUFF_SIZE)
			buff[n] = '\0';
		if (ft_strchr(buff, '\n'))
		{
			i = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '\n'));
			*line = ft_strjoin_free(*line, ft_strsub(buff, 0, i));
			ft_memmove(buff, buff + i + 1, ft_strlen(buff + i + 1) + 1);
			return (1);
		}
		*line = ft_strjoin_free(*line, ft_strsub(buff, 0, n));
		if (n < BUFF_SIZE)
			return (1);
	}
	return ((n == 0) ? (0) : (1));
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

static int	aux_function(const int fd, t_btree **root,
					t_btree *node, char **line)
{
	int n;

	if (!(n = no_newline(fd, ((t_file *)(node->data))->buffer,
					line)) || n == -1)
	{
		btree_deletenode_avl(root, node->data, &compare_files, &free);
		if (n == -1)
			free(*line);
		return (n);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_btree	*files = NULL;
	t_file			temp;
	t_btree			*node;

	temp.fd = fd;
	temp.buffer = NULL;
	if (!line)
		return (-1);
	if (!(node = btree_search_data(files, &temp, &compare_files)))
	{
		btree_insert_avl(&files, &temp, sizeof(t_file), &compare_files);
		node = btree_search_data(files, &temp, &compare_files);
	}
	if (!((t_file *)(node->data))->buffer)
		if (!(((t_file *)(node->data))->buffer = ft_strnew((BUFF_SIZE + 1))))
			return (-1);
	if (!ft_strchr(((t_file *)(node->data))->buffer, '\n'))
		return (aux_function(fd, &files, node, line));
	else
		(with_newline(((t_file *)(node->data))->buffer, line));
	return (1);
}
