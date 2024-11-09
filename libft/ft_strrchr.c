/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:10:15 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/29 22:00:28 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	cc;

	p = (char *)s;
	cc = c;
	while (*s)
	{
		if (*s == cc)
			p = (char *)s;
		s++;
	}
	if (*s == cc)
		p = (char *)s;
	if (*p == cc)
		return (p);
	return (NULL);
}
