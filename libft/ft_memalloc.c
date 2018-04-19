/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:44:26 by eneto             #+#    #+#             */
/*   Updated: 2018/04/05 20:05:57 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;

	mem = (void *)malloc(size);
	i = 0;
	if (mem)
		while (i < size)
		{
			*(char *)(mem + i) = 0;
			i++;
		}
	return (mem);
}
