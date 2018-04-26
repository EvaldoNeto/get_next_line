/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_left_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:46:52 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 17:47:05 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_left_rotate(t_btree *node)
{
	t_btree *x;
	t_btree *y;

	x = node->right;
	y = x->left;
	x->left = node;
	node->right = y;
	return (x);
}
