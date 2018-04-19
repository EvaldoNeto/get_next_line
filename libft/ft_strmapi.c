/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:26:46 by eneto             #+#    #+#             */
/*   Updated: 2018/04/08 20:35:49 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	char		*str;

	if (s)
	{
		i = ft_strlen((char *)s);
		str = (char *)malloc(sizeof(char) * (i + 1));
		if (!str)
			return (NULL);
		str[i] = '\0';
		i = 0;
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
		return (char *)(str);
	}
	return (NULL);
}
