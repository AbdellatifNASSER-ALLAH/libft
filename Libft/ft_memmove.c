/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:44:01 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/27 15:42:30 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!dest && !src)
		return (dest);
	if (sizeof(d) - sizeof(s) < n)
	{
		s += n - 1;
		d += n - 1;
		while (n--)
			*d-- = *s--;
	}
	else
	{
		while (n)
		{
			*d++ = *s++;
			n--;
		}
	}
	return (dest);
}
