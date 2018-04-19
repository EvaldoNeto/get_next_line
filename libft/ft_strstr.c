/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:35:59 by eneto             #+#    #+#             */
/*   Updated: 2018/04/09 19:49:29 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int len;
	int i;
	int j;

	i = 0;
	j = 0;
	len = 0;
	while (needle[len])
		len++;
	while (j != len && haystack[i])
	{
		if (needle[j] == haystack[i + j] && haystack[i + j])
			j++;
		else
		{
			i++;
			j = 0;
		}
	}
	if (!haystack[i] && len != 0)
		return (NULL);
	return (char *)(haystack + i);
}
