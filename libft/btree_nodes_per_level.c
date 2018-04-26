/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_nodes_per_level.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:11:03 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 20:11:52 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	btree_nodes_per_level(t_btree *root, int level)
{
	if (root)
	{
		if (level == 1)
			return (1 + btree_nodes_per_level(root, level - 1));
		if (level == 0)
			return (0);
		return (btree_nodes_per_level(root->left, level - 1)
				+ btree_nodes_per_level(root->right, level - 1));
	}
	return (0);
}
