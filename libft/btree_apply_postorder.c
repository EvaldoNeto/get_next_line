/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_postorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:36:03 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 17:36:52 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_postorder(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		btree_apply_postorder(root->left, applyf);
		btree_apply_postorder(root->right, applyf);
		(*applyf)(root->data);
	}
}
