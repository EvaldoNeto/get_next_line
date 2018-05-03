/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:16:00 by eneto             #+#    #+#             */
/*   Updated: 2018/05/03 13:20:54 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str)
	{
		ft_memcpy(str, s, sizeof(char) * i);
		str[i] = '\0';
	}
	return (str);
}
