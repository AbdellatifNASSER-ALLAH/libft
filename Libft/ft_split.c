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

size_t	ft_words(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && *(s + 1) == c)
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

	p = (char **)malloc((ft_words((char *)s, c) + 1) * sizeof(char *));
	if (!p)
		return (0);
	i = 0;
	while (*s)
	{
		count = 0;
		while (*s == c)
			s++;
		while (*s != c && *s++)
			count++;
		p[i++] = ft_substr((s - count), 0, count);
		while (*s == c)
			s++;
	}
	p[i] = 0;
	return (p);
}

int	main()
{
	char	*s = " hello world   this is   just  a  test  ";
	char	c = 32;
	char **p  = ft_split(s, c);
	size_t	count = ft_words(s, c);

	for (size_t i = 0; i < count ; i++)
		printf("--> %s \n", p[i]);
}
