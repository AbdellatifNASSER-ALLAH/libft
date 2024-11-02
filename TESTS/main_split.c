#include "../Libft/libft.h"
#include <stdio.h>
int main()
{
	char *ptr ="hello!     ";
	
	char **split = ft_split(ptr, 32);
	printf("\"%s\"\n", *(split));
	printf("\"%s\"\n", *(split + 1));
}
