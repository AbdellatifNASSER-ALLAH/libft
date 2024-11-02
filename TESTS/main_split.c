#include "../Libft/ft_split.c"
#include "../Libft/libft.h"
#include <stdio.h>
int main()
{
	char *ptr = "hd          hi       hi              hi              hi  ho";
	int i = 0;
	
	char **split = ft_split(ptr, ' ');
	while (*(split + i))
	{
		printf("\"%s\"\n", *(split + i));
		i++;
	}
}
