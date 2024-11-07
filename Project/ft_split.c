/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:50:04 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/07 16:03:26 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_words(const char *s, char c);
char	*ft_fill_word(char **p, int size, char const *s, size_t len);

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
		p[i] = ft_fill_word(p, i, s, count);
		if (!p[i])
			return (0);
		s += count;
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_fill_word(char **p, int i, char const *s, size_t len)
{
	size_t	j;

	p[i] = (char *)malloc((len + 1) * sizeof(char));
	if (!p[i])
	{
		while (i--)
			free(p[i]);
		free(p);
		return (0);
	}
	j = 0;
	while (j < len)
	{
		p[i][j] = s[j];
		j++;
	}
	p[i][j] = 0;
	return (p[i]);
}

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
