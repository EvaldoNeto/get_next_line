/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:32:33 by eneto             #+#    #+#             */
/*   Updated: 2018/04/09 19:50:29 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (little[k])
		k++;
	while (i + j <= len && j != k && big[i])
	{
		if (little[j] == big[i + j] && big[i + j])
			j++;
		else
		{
			i++;
			j = 0;
		}
	}
	if ((j == len && little[j]) || i + j > len)
		return (NULL);
	if (!big[i] && j < len)
		return (NULL);
	return (char *)(big + i);
}
