#include "head.h"

// test for ft_isascii

int	run_test(void)
{
	int res, exp;
	for (int i = CHAR_MIN; i < CHAR_MAX * 2; i++)
	{
		res = ft_isascii(i);
		exp = isascii(i);
		if (res != exp)
		{
			printf("ft_isascii(%c / %d) -> \033[0;31mFAILED!\033[0m : expected -> %d, got -> %d\n", i, i, exp, res);
			return 1;
		}
	}
	printf("ft_isascii -> \033[0;32mPASSED!\033[0m\n");
	return 0;
}

int main()
{
		run_test();
		return 0;
}
