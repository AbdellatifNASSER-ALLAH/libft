#include "head.h"

int run_test(void)
{
	for (int i = CHAR_MIN * 4; i < CHAR_MAX * 4; i++)
	{
		if (isalpha(i) != ft_isalpha(i))
		{
			printf("ft_isalpha(%c / %d) -> \033[0;31mFAILED! : expected -> %d, got -> %d\n",
					i, i, isalpha(i), ft_isalpha(i));
			return 0;
		}
	}
	printf("ft_isalpha -> \033[0;32mPASSED!\n");
	return 1;
}

int main()
{
		run_test();
			return 0;
}

