/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:50:24 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 17:50:45 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_print_level(t_btree *root, int level)
{
	if (root)
	{
		if (level == 1)
			ft_putstr(root->data);
		else if (level > 1)
		{
			btree_print_level(root->left, level - 1);
			btree_print_level(root->right, level - 1);
		}
	}
	else
		ft_putstr("(null)");
}
