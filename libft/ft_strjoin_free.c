/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:31:35 by eneto             #+#    #+#             */
/*   Updated: 2018/05/01 13:31:53 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *str;

	if (!(str = ft_strjoin(s1, s2)))
		return (NULL);
	if (s1 && *s1)
	    free(s1);
	if (s2 && *s2)
	    free(s2);
	return (str);
}
