/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:44:33 by abdnasse          #+#    #+#             */
/*   Updated: 2024/12/05 20:08:26 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = f_putformat(ap, format);
	va_end(ap);
	return (count);
}

int	f_putformat(va_list ap, const char *p)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 0;
	while (p[i])
	{
		if (p[i] == '%')
		{
			check = f_specifier(ap, p[++i]);
			if (check < 0)
				return (-1);
			count += check;
		}
		else
		{
			if (ft_putchar(p[i]) < 0)
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

int	f_specifier(va_list ap, char c)
{
	unsigned long	ptr;

	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, const char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_puthex("0123456789abcdef", va_arg(ap, unsigned int)));
	if (c == 'X')
		return (ft_puthex("0123456789ABCDEF", va_arg(ap, unsigned int)));
	if (c == 'p')
	{
		ptr = (unsigned long)va_arg(ap, void *);
		return (ft_putptr("0123456789abcdef", ptr));
	}
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
