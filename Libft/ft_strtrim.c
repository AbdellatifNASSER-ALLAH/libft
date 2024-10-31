/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:21:58 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/31 21:00:48 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_inset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	end;
	size_t	start;
	size_t	i;

	end = ft_strlen(s1);
	if (!*s1 && !*set)
		return (ft_strdup("\0"));
	start = 0;
	while (start < end && ft_inset(s1[start], set))
		start++;
	while (end && ft_inset(s1[end], set))
		end--;
	p = (char *)malloc((end - start + 1) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (start < end + 1)
		p[i++] = s1[start++];
	p[i] = 0;
	return (p);
}
