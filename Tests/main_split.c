#include "head.h"


int main()
{
	char *s ="   one two three     fout five    six  seven     eight   nine ten       ";
	char **strs = ft_split(s, 32);
	int	i = 0;

	while (*(strs + i) != NULL)
		printf("\"%s\"\n", *(strs + i++));
	printf("\"%s\"\n", *(strs + i));
}
