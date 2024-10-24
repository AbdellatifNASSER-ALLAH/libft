/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:04:58 by abdnasse          #+#    #+#             */
/*   Updated: 2024/10/24 16:18:16 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 128);
}

int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}

size_t	ft_strlen(const	char *s)
{
	size_t	n;

	n = 0;
	while(s[n])
		n++;
	return (n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while(i < len)
		b[i++] = c;
	return (b);
}

int main()
{
	char *s = "test test test test";
	printf("-> std: %s\n", memset(s, 97, 5));
  	printf("-> ft_: %s\n", ft_memset(s, 97, 5));
}
