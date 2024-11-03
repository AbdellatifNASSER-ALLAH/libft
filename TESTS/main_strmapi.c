#include "../Libft/libft.h"
#include <stdio.h>

char	test(unsigned int i, char c)
{
	return (i + c);
}
int main()
{
	char *p = "aaaaaaaaaaaa";

	printf("--|%s|\n", ft_strmapi(p, test));
}
