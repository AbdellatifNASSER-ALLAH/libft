/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:23:53 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/28 15:32:13 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(void *b, int c, size_t len)
{
	unsigned char	*t;
	size_t			i;

	t = b;
	i = 0;
	while (i < len)
		t[i++] = (unsigned char)c;
	return (b);
}
