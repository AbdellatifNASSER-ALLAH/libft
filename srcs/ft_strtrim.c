/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:21:58 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/11 13:03:04 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_inset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static void	ft_filltrim(char *p, char const *s, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start <= end)
		p[i++] = s[start++];
	p[i] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	end;
	size_t	start;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1);
	if ((!*s1 && !*set) || !end)
		return (ft_strdup(""));
	start = 0;
	end--;
	while (start <= end && ft_inset(s1[start], set))
		start++;
	while (end > start && ft_inset(s1[end], set))
		end--;
	p = (char *)malloc((end - start + 2) * sizeof(char));
	if (!p)
		return (0);
	ft_filltrim(p, s1, start, end);
	return (p);
}
