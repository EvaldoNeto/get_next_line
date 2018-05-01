/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:38:49 by eneto             #+#    #+#             */
/*   Updated: 2018/05/01 13:40:13 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	if (!s)
		return (NULL);
	i = (int)ft_strlen((char *)s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	if (j > 0 && !s[j])
	{
		if (!(str = (char *)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (char *)(str);
	}
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	if (!(str = (char *)malloc(sizeof(char) * (i - j + 2))))
		return (NULL);
	str[i - j + 1] = '\0';
	while (i-- >= j)
		str[i - j + 1] = s[i + 1];
	return ((char *)str);
}
