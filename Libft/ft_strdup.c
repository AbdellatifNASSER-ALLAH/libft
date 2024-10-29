/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:40:23 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/29 23:27:15 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	size;
	
	size = ft_strlen(s);
	p = (char *)malloc((size + 1) * sizeof(char));
	if (!p)
		return (0);
	*(p +  size) = 0;
	while (size--)
		*(p + size) = *(s + size);
	return (p);
}
