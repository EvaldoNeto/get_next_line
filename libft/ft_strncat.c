/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:27:48 by eneto             #+#    #+#             */
/*   Updated: 2018/04/05 20:01:54 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t size_dest;
	size_t size_src;
	size_t i;

	size_src = 0;
	size_dest = (size_t)ft_strlen(dest);
	i = size_dest;
	while (src[size_src])
		size_src++;
	while (i < size_src + size_dest && i - size_dest < n)
	{
		dest[i] = src[i - size_dest];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
