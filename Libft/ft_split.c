/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:50:04 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/02 17:16:30 by abdnasse         ###   ########.fr       */
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

char	**ft_free_all(char **p, int len)
{
	if (len == 0)
		return (0);
	while (len)
		free(p[len--]);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	count;
	size_t	i;

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
		if (!p[i - 1])
			return (ft_free_all(&p[i - 2], i - 1));
		s += count;
	}
	p[i] = 0;
	return (p);
}
