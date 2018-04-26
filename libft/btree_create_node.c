/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:37:11 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 17:37:57 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_create_node(void const *data, size_t data_size)
{
	t_btree	*new_tree;

	new_tree = (t_btree *)malloc(sizeof(t_btree));
	if (new_tree)
	{
		if (!data)
		{
			new_tree->data = NULL;
			new_tree->data_size = 0;
		}
		else
		{
			new_tree->data_size = data_size;
			new_tree->data = malloc(data_size);
			ft_memmove(new_tree->data, data, data_size);
		}
		new_tree->left = NULL;
		new_tree->right = NULL;
	}
	return (new_tree);
}
