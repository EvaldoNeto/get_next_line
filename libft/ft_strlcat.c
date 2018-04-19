/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:22:53 by eneto             #+#    #+#             */
/*   Updated: 2018/04/08 20:24:22 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t size_dest;
	size_t size_src;
	size_t i;

	size_src = 0;
	size_dest = (size_t)ft_strlen(dst);
	i = size_dest;
	while (src[size_src])
		size_src++;
	if (size == 0)
		return (size_src);
	while (i < size - 1 && src[i - size_dest])
	{
		dst[i] = src[i - size_dest];
		i++;
	}
	dst[i] = '\0';
	if (i >= size)
		return (size_src + size);
	return (size_t)(size_src + size_dest);
}
