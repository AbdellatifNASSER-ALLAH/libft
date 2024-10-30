/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:38:53 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/30 02:02:07 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t	i;

	if (size == 0 ||  nmemb == 0)
	{
		p = (unsigned char *)malloc(sizeof(char));
		if (!p)
			return (0);
		*p = 0;
		return ((void *)p);
	}
	if (nmemb > SIZE_MAX / size)
		return (0);
	p = (unsigned char *)malloc(nmemb * size);
	if (!p)
		return (0);
	i = 0;
	while (i < nmemb * size)
		p[i++] = 0;
	return ((void *)p);
}
