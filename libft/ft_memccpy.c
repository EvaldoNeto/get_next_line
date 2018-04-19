/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:47:18 by eneto             #+#    #+#             */
/*   Updated: 2018/04/06 15:33:34 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(src + i) != (unsigned char)c)
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		else
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			return (unsigned char *)(dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
