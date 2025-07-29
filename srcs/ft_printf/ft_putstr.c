/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:07:30 by abdnasse          #+#    #+#             */
/*   Updated: 2024/12/04 22:05:10 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	count;

	if (!str)
		return (ft_putstr("(null)"));
	count = 0;
	while (str[count])
	{
		if (ft_putchar(str[count++]) == -1)
			return (-1);
	}
	return (count);
}
