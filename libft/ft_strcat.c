/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:07:38 by eneto             #+#    #+#             */
/*   Updated: 2018/04/08 20:33:12 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t size_dest;
	size_t size_src;
	size_t i;

	size_src = 0;
	size_dest = ft_strlen(dest);
	i = size_dest;
	while (src[size_src])
		size_src++;
	while (i < size_src + size_dest)
	{
		dest[i] = src[i - size_dest];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
