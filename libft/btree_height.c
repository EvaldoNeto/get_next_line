/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:38:19 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 17:38:29 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	btree_height(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + ft_max(btree_height(root->left), btree_height(root->right)));
}
