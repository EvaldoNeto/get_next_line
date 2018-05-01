/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_avl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:38:53 by eneto             #+#    #+#             */
/*   Updated: 2018/05/01 13:42:13 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_btree	*rotate_left_right(t_btree **ptr)
{
	(*ptr)->left = btree_left_rotate((*ptr)->left);
	return (*ptr = btree_right_rotate((*ptr)));
}

static	t_btree	*rotate_right_left(t_btree **ptr)
{
	(*ptr)->right = btree_right_rotate((*ptr)->right);
	return (*ptr = btree_left_rotate((*ptr)));
}

t_btree			*btree_insert_avl(t_btree **ptr, void *data, size_t data_size,
				int (*cmpf)(void *, void *))
{
	int balance;

	if (!(*ptr))
		return (*ptr = btree_create_node(data, data_size));
	if ((*cmpf)(data, (*ptr)->data) < 0)
		(*ptr)->left = btree_insert_avl(&((*ptr)->left), data, data_size, cmpf);
	else if ((*cmpf)(data, (*ptr)->data) > 0)
		(*ptr)->right = btree_insert_avl(&((*ptr)->right), data,
									data_size, cmpf);
	else
		return (*ptr);
	balance = btree_height((*ptr)->left) - btree_height((*ptr)->right);
	if (balance > 1 && (*cmpf)(data, (*ptr)->left->data) < 0)
		return (*ptr = btree_right_rotate((*ptr)));
	if (balance < -1 && (*cmpf)(data, (*ptr)->right->data) > 0)
		return (*ptr = btree_left_rotate((*ptr)));
	if (balance > 1 && (*cmpf)(data, (*ptr)->left->data) > 0)
		return (rotate_left_right(ptr));
	if (balance < -1 && (*cmpf)(data, (*ptr)->right->data) < 0)
		return (rotate_right_left(ptr));
	return (*ptr);
}
