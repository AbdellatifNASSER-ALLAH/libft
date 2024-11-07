#include "head.h"

int	run_test(void)
{
	int cases[] = {'A', 'z', '5', 'b', ' ', '0', '\n', EOF};
	int num_cases = sizeof(cases) / sizeof(cases[0]);

	for (int i = 0; i < num_cases; i++)
	{
		if (isalnum(cases[i]) != ft_isalnum(cases[i]))
		{
			printf("ft_isalnum(%c / %d) -> FAILED! : expected -> %d, got -> %d\n",
					cases[i], cases[i], isalnum(cases[i]), ft_isalnum(cases[i]));
			return 0;
		}
	}
	printf("ft_isalnum -> PASSED!\n");
	return 1;
}

int main()
{
	run_test();
	return 0;
}
