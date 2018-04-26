/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:48:34 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 17:50:09 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	print_spaces(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putstr(" ");
		i++;
	}
}

void			btree_print(t_btree *root, int n, void (*print)(void *))
{
	static int spaces = 10;

	if (root)
	{
		n += spaces;
		btree_print(root->right, n, print);
		ft_putstr("\n");
		print_spaces(n - spaces);
		(*print)(root->data);
		ft_putstr("\n");
		btree_print(root->left, n, print);
	}
}
