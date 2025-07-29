/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:11:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/12/04 19:09:01 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(long nbr)
{
	long	n;
	int		mask;
	int		count;

	n = nbr;
	count = 0;
	if (n < 0)
	{
		n = -n;
		if (ft_putchar('-') < 0)
			return (-1);
		count++;
	}
	mask = ft_10power(ft_ilen(n) - 1);
	while (mask)
	{
		if (ft_putchar((n / mask) + 48) < 0)
			return (-1);
		count++;
		n %= mask;
		mask /= 10;
	}
	return (count);
}
