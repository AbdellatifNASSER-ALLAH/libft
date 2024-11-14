/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:50:04 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/11 12:55:07 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is2free(char **p, int i)
{
	if (!p[i])
	{
		while (i--)
			free(p[i]);
		free(p);
		return (1);
	}
	return (0);
}

static char	*ft_fill_word(char **p, int i, char const *s, size_t len)
{
	size_t	j;

	p[i] = (char *)malloc((len + 1) * sizeof(char));
	if (!p[i])
		return (0);
	j = 0;
	while (j < len)
	{
		p[i][j] = s[j];
		j++;
	}
	p[i][j] = 0;
	return (p[i]);
}

static size_t	ft_words(const char *s, char c)
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

static size_t	ft_wordlen(const char *s, char end)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != end)
		i++;
	return (i);
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
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		count = ft_wordlen(s, c);
		p[i] = ft_fill_word(p, i, s, count);
		if (ft_is2free(p, i))
			return (0);
		s += count;
		i++;
	}
	p[i] = 0;
	return (p);
}
