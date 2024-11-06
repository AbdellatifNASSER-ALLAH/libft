#include "head.h"

// test for ft_isascii

int	run_test(void)
{
	int res, exp;
	for (int i = INT_MIN; i <= INT_MAX; i++)
	{
		res = ft_isascii(i);
		exp = isascii(i);
		if (res != exp)
		{
			printf("ft_isascii(%c / %d) -> \033[0;31mFAILED!\033[0m : expected -> %d, got -> %d\n", i, i, exp, res);
			return 1;
		}
		if ( i % 10000000 == 0)
			printf("\033[0;32mft_isascii(%c / %d): expected -> %d, got -> %d\033[0m\n", i, i, exp, res);
		if ( i == INT_MAX)
			break ;
	}
	printf("ft_isascii -> \033[0;32mPASSED!\033[0m\n");
	return 0;
}

int main()
{
		run_test();
		return 0;
}
