/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:42:03 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/30 01:12:07 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		i = 0;
		while (i < len && big[i] == little[i])
			i++;
		if(!little[i])
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
