/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:29:00 by eneto             #+#    #+#             */
/*   Updated: 2018/04/07 19:36:36 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
	}
	if (i == n)
		return (0);
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}
