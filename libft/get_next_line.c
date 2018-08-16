/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:19:50 by eneto             #+#    #+#             */
/*   Updated: 2018/05/03 15:43:48 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

static int	aux_function(const int fd, t_btree **files, t_btree **node,
						t_file *temp)
{
	int n;

	if (((t_file *)((*node)->data))->buffer == NULL)
	{
		if (!(((t_file *)((*node)->data))->buffer = ft_strnew((BUFF_SIZE + 1))))
			return (-1);
		if ((n = read(fd, ((t_file *)((*node)->data))->buffer,
			BUFF_SIZE)) == -1)
		{
			free(((t_file *)((*node)->data))->buffer);
			((t_file *)((*node)->data))->buffer = NULL;
			btree_deletenode_avl(files, &temp, &compare_files, &free);
			return (-1);
		}
		if (n == 0)
		{
			free(((t_file *)((*node)->data))->buffer);
			((t_file *)((*node)->data))->buffer = NULL;
			return (0);
		}
	}
	return (1);
}

static int	aux_function2(t_btree **node, char **line)
{
	int n;

	n = ft_strlen((((t_file *)((*node)->data))->buffer)) -
		ft_strlen(ft_strchr((((t_file *)((*node)->data))->buffer), '\n'));
	*line = ft_strjoin_free(*line,
						ft_strsub((((t_file *)((*node)->data))->buffer), 0, n));
	ft_memmove((((t_file *)((*node)->data))->buffer),
		(((t_file *)((*node)->data))->buffer) + n + 1,
		ft_strlen((((t_file *)((*node)->data))->buffer) + n + 1) + 1);
	if ((((t_file *)((*node)->data))->buffer)[0] == '\0')
	{
		free(((t_file *)((*node)->data))->buffer);
		((t_file *)((*node)->data))->buffer = NULL;
	}
	return (1);
}

static int	gnl(const int fd, char **line, t_btree **files, t_file temp)
{
	t_btree	*node;
	int		n;

	if (!(node = btree_search_data(*files, &temp, &compare_files)))
	{
		btree_insert_avl(files, &temp, sizeof(t_file), &compare_files);
		node = btree_search_data(*files, &temp, &compare_files);
	}
	if ((n = aux_function(fd, files, &node, &temp)) == 0 || n == -1)
		return (n);
	if (ft_strchr(((t_file *)(node->data))->buffer, '\n'))
		return (aux_function2(&node, line));
	else
	{
		*line = ft_strjoin_free(*line, ((t_file *)(node->data))->buffer);
		((t_file *)(node->data))->buffer = NULL;
		gnl(fd, line, files, temp);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_btree	*files = NULL;
	int				n;
	t_file			temp;

	temp.fd = fd;
	temp.buffer = NULL;
	if (!line)
		return (-1);
	*line = ft_strdup("");
	n = (gnl(fd, line, &files, temp));
	if (n == 0)
		btree_deletenode_avl(&files, &temp, &compare_files, &free);
	if (btree_height(files) == 0)
	{
		free(files);
		files = NULL;
	}
	return (n);
}
