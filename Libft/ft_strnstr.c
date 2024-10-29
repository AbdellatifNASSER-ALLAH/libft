/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:42:03 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/30 00:37:37 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*s;

	if (!*little)
		return ((char *)big);
	while (*big && len--)
	{
		s = big;
		while (*s++ == *little++)
		if(!*little)
			return ((char *)big);
		big++;
	}
	return (0);
}
