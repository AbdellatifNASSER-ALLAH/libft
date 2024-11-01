/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:50:04 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/01 12:50:12 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <unistd.h>

size_t	ft_words(const char *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			count++;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	p = (char **)malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!p)
		return (0);
	i = 0;
	while (*s)
	{
		count = 0;
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		while (s[count] && s[count] != c)
			count++;
		p[i++] = ft_substr(s, 0, count);
		s += count;
	}
	p[i] = 0;
	return (p);
}
