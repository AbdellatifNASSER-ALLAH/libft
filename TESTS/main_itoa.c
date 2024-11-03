#include "../Libft/libft.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	int	nbrs[] = {0, 12, 1000, -12, -85858, INT_MIN, INT_MAX};
	size_t	i;

	i = 0;
	while (i < sizeof(nbrs) / sizeof(nbrs[0]))
		printf("--|%s|\n", ft_itoa(nbrs[i++]));
}
