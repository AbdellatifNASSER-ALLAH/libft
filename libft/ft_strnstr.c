/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:42:03 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/12 17:46:06 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	j = 0;
	while (j < len && big[j])
	{
		i = 0;
		while (little[i] && big[j + i] == little[i] && i + j < len)
			i++;
		if (!little[i])
			return ((char *)big + j);
		j++;
	}
	return (0);
}
