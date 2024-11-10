/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:28:37 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/10 19:40:14 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	if (size == 0 && !dst)
		return (slen);
	dlen = ft_strlen(dst);
	if (size <= dlen)
		return (size + slen);
	i = dlen;
	while (*src && i < size - 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	ft_putnbr_fd(slen, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(dlen, 1);
	write(1, "\n", 1);
	return (slen + dlen);
}
