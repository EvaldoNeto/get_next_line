/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:04:20 by eneto             #+#    #+#             */
/*   Updated: 2018/04/05 20:04:08 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int aux1;
	int aux2;

	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	aux1 = 1;
	aux2 = n;
	while (aux2 > 9 && aux2 != -2147483648)
	{
		aux1 = aux1 * 10;
		aux2 = aux2 / 10;
	}
	aux2 = n;
	while (aux1 > 0 && n != -2147483648)
	{
		aux2 = aux2 / aux1;
		ft_putchar_fd(aux2 + '0', fd);
		aux2 = n % aux1;
		aux1 = aux1 / 10;
	}
}
