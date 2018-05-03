/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:08:56 by eneto             #+#    #+#             */
/*   Updated: 2018/04/05 20:03:38 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
	  return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (char *)(s + i);
		i++;
	}
	if (c == '\0')
		return (char *)(s + i);
	return (NULL);
}
