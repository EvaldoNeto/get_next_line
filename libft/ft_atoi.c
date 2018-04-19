/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:30:20 by eneto             #+#    #+#             */
/*   Updated: 2018/04/07 18:09:01 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numspaces(const char *nptr)
{
	int i;

	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	return (i);
}

int			ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	int			j;
	long int	result;

	result = 0;
	j = 0;
	i = numspaces(nptr);
	sign = 1;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (ft_isdigit(nptr[i + j]))
	{
		result = result * 10 + (nptr[i + j] - '0');
		j++;
	}
	if (sign * result == (int)(sign * result))
		return ((int)(sign * result));
	else
		return ((sign > 0) ? -1 : 0);
}
