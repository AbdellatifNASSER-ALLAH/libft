/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:10:15 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/28 12:44:23 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	while (*s)
	{
		if (*s == c)
			p = (char *)s;
		s++;
	}
	if (*s == c)
		p = (char *)s;
	if (*p == c)
		return (p);
	return (NULL);
}
