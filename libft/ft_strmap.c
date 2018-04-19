/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:25:30 by eneto             #+#    #+#             */
/*   Updated: 2018/04/09 18:23:05 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		i;
	char		*str;

	if (s)
	{
		i = ft_strlen((char *)s);
		if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		str[i] = '\0';
		i = 0;
		while (s && s[i])
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		return (char *)(str);
	}
	return (NULL);
}
