#include "head.h"

int main()
{
	int a = 0;

	char *s = (char *)&a;
	ft_memset(s++, '9', 1);
	ft_memset(s, 5, 1);

	printf("hello hadchi : %d\n",a);
}
