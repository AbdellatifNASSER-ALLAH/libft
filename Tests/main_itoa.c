#include "head.h"

int main()
{
	int i;
	char exp[30];
	char *res;

	i = 1935300000;
	while (1)
	{
		sprintf(exp,"%d",i);	
		res = ft_itoa(i);
		if(strcmp(exp,res))
		{
			printf("ERROR\nExpected : %s\nGot    : %s\n",exp,res);
			break;
		}
		if(i % 100000 == 0)
			printf("PASS %d\n",i);
		if(i == INT_MAX)
			break;
		i++;


	}
}
