/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:20:56 by eneto             #+#    #+#             */
/*   Updated: 2018/04/08 20:43:40 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*str;

	if (s1 && s2)
	{
		i = (int)ft_strlen((char *)s1);
		j = (int)ft_strlen((char *)s2);
		if (!(str = (char *)malloc(sizeof(char) * (i + j + 1))))
			return (NULL);
		str[i + j] = '\0';
		while (--j > -1)
			str[i + j] = s2[j];
		while (--i > -1)
			str[i] = s1[i];
		return (str);
	}
	if (s1 && !s2)
	    return (ft_strdup(s1));
	if (!s1 && s2)
	    return (ft_strdup(s2));
	return (NULL);
}
