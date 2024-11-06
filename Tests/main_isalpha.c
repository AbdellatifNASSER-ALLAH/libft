#include "head.h"

int run_test(void)
{
	int res, exp;

	for (int i = INT_MIN; i <= INT_MAX; i++)
	{
		res = ft_isaplha
		if (isalpha(cases[i]) != ft_isalpha(cases[i]))
		{
			printf("ft_isalpha(%c / %d) -> \033[0;31mFAILED! : expected -> %d, got -> %d\n",
					cases[i], cases[i], isalpha(cases[i]), ft_isalpha(cases[i]));
			return 0;
		}
		if (i % 10000000 == 0)
			printf("\033[0;32mft_isalpha(%c / %d): expected -> %d, got -> %d\n",
					cases[i], cases[i], isalpha(cases[i]), ft_isalpha(cases[i]));
		if (i == INT_MAX)
			break ;
	}
	printf("ft_isalpha -> \033[0;32mPASSED!\n");
	return 1;
}

int main()
{
		run_test();
			return 0;
}

