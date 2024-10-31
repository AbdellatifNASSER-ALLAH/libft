/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:21:58 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/31 16:36:17 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	if (!*s1 && !*set)
		return (ft_strdup("\0");
	i = 0;
	while (i < len)
	{
		j = 0;
		while (s1[i] == set[j++])
		if (!set[j])
		{
			p = (char *)s1[i];
			i = len - 1;
		}
		i++;
	}
	while (len 

}
