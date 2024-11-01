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

char	**ft_split(char const *s, char c)
{
	char	**p;
	char	*ss;
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	while (*ss && *ss == c && *(ss - 1) != c)
	{
		count++;
		ss++;
	}
	p = (char **)malloc((count + 1) * sizeof(char *));
	if (!p)
		return (0);
	i = 0;
	while (*s)
	{
		j = 0;
		count = 0;
		while (*s++ == c)
			while (*s++ != c)
				count++;
		p[i] = (char *)malloc((count + 1) * sizeof(char));
		while (j < count)
		{
			p[i][j++] = *(s - count + j);
			j++;
		}
		p[i][j] = 0;
		s++;
	}
}
