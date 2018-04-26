/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_right_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:12:47 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 20:14:24 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_right_rotate(t_btree *node)
{
	t_btree *x;
	t_btree *y;

	x = node->left;
	y = x->right;
	x->right = node;
	node->left = y;
	return (x);
}
