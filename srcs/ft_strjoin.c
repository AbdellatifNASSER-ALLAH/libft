/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:57:29 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/10 12:55:01 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(size * sizeof(char));
	if (!p)
		return (0);
	size = 0;
	while (*s1)
		p[size++] = *s1++;
	while (*s2)
		p[size++] = *s2++;
	p[size] = 0;
	return (p);
}
