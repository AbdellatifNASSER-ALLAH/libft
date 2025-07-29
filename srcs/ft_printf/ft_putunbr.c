/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:11:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/12/02 15:34:47 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	unsigned int	mask;
	int				count;
	char			c;

	mask = ft_10power(ft_ilen(nbr) - 1);
	count = 0;
	while (mask)
	{
		c = (nbr / mask) + 48;
		if (ft_putchar(c) < 0)
			return (-1);
		count++;
		nbr %= mask;
		mask /= 10;
	}
	return (count);
}
