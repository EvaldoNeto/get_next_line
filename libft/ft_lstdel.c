/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:21:38 by eneto             #+#    #+#             */
/*   Updated: 2018/04/09 18:58:20 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *after;

	if (alst && del)
	{
		after = *alst;
		while ((*alst)->next)
		{
			after = (*alst)->next;
			ft_lstdelone(alst, del);
			if (!after)
				break ;
			alst = &after;
		}
		if (*alst)
			ft_lstdelone(alst, del);
	}
}
