#include "../Libft/libft.h"
#include <limits.h>
#include <stdio.h>

int main()
{
	int	nbrs[] = {0, 1, 123, INT_MIN, INT_MAX};
	size_t	i = 0;
	int	fd = 1;
	
	while (i < sizeof(nbrs) / sizeof(int))
		printf("std|%d\n", nbrs[i++]);
	i = 0;
	while (i < sizeof(nbrs) / sizeof(int))
	{
		ft_putstr_fd("ft_|", fd);
		ft_putnbr_fd(nbrs[i++], fd);
		ft_putstr_fd("\n", fd);
	}
}
