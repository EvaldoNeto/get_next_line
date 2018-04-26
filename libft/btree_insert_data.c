/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:45:44 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 17:46:32 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_insert_data(t_btree *root, void *data, size_t data_size,
		int (*cmpf)(void *, void *))
{
	if (!root)
		return (btree_create_node(data, data_size));
	if ((*cmpf)(data, root->data) < 0)
	{
		if (root->left == 0)
		{
			root->left = btree_create_node(data, data_size);
			return (root->left);
		}
		btree_insert_data(root->left, data, data_size, cmpf);
	}
	else if ((*cmpf)(data, root->data) > 0)
	{
		if (root->right == 0)
		{
			root->right = btree_create_node(data, data_size);
			return (root->right);
		}
		btree_insert_data(root->right, data, data_size, cmpf);
	}
	return (root);
}
