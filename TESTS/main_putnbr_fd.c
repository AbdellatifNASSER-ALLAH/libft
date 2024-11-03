#include "../Libft/libft.h"
#include <limits.h>
#include <stdio.h>

int main()
{
	int	nbrs[] = {0, 1, 111, INT_MIN, INT_MAX};
	size_t	i = 0;
	int	fd = 1;

	while (i < sizeof(nbrs) / sizeof(int))
	{
		ft_putnbr_fd(nbrs[i], fd);
		write(fd, "\n", 1);
	}
}
