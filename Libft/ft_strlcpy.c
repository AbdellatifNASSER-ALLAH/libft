/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:07:55 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/27 17:57:50 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	i = 0;
	while (*src && i < size - 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (slen);
}
