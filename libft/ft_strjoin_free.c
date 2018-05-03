/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:31:35 by eneto             #+#    #+#             */
/*   Updated: 2018/05/03 15:41:24 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *str;

	if (!(str = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	free(s2);
	return (str);
}
