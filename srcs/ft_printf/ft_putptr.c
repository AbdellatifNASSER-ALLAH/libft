/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:13:34 by abdnasse          #+#    #+#             */
/*   Updated: 2024/12/05 14:58:01 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr(char *base, unsigned long ptr)
{
	int				count;
	int				hex;
	int				shift;
	unsigned long	mask;

	if ((void *)ptr == NULL)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	if (count < 0)
		return (-1);
	mask = 0xf000000000000000;
	shift = 60;
	while (mask)
	{
		hex = (ptr & mask) >> shift;
		if (hex > 0 || count > 2)
		{
			if (ft_putchar(base[hex]) < 0)
				return (-1);
			count++;
		}
		shift -= 4;
		mask >>= 4;
	}
	return (count);
}
