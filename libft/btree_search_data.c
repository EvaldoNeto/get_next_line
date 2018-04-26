/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:14:35 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 20:15:10 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_search_data(t_btree *root, void *data,
		int (*cmpf)(void *, void *))
{
	if (!root)
		return (NULL);
	if (cmpf(data, root->data) < 0)
		return (btree_search_data(root->left, data, cmpf));
	else if (cmpf(data, root->data) > 0)
		return (btree_search_data(root->right, data, cmpf));
	else
		return (root);
	return (NULL);
}
