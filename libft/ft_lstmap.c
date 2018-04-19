/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:50:54 by eneto             #+#    #+#             */
/*   Updated: 2018/04/09 18:10:30 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *aux;
	t_list *new;

	if (lst)
	{
		aux = (*f)(lst);
		new = aux;
		while (lst->next)
		{
			aux->next = (f)(lst->next);
			aux = aux->next;
			lst = lst->next;
		}
		return (new);
	}
	return (lst);
}
