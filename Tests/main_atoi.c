#include "head.h"

int run()
{
	char *tests[] = {
		"0",
		"",
		"-2147483649",	// INT_MIN + 1
		"-2147483648",	// INT_MIN
		"-2147483647",	// INT_MIN - 1
		"2147483646",	// INT_MAX - 1
		"2147483647",	// INT_MAX
		"2147483648",	// INT_MAX + 1
		"2147422222283648",	// INT_MAX + 1

		"-9223372036854775806",	//LONG_MINI + 2
		"-9223372036854775807",	//LONG_MINI + 1
		"-9223372036854775808",	//LONG_MIN
		"-9223372036854775809",	//LONG_MIN - 1 the std atoi return 0
		"-9223372036854775810",	//LONG_MIN - 2
		"-922337203685475555555575811",	//LONG_MIN - 2
		"9223372036854775805",	// LONG_MAX - 2
		"9223372036800000022222222222111111115806",	// LONG_MAX - 1
		"9223372036854775807",	// LONG_MAX
		"9223372036854775808",	// LONG_MAX + 1 the std atoi return -1
		"-+14748ddd3648",
		"+sss2147483648",
		"2514jhjfh"
	};
	int res, exp;
	int size = sizeof(tests) / sizeof(tests[0]);
	for (int i = 0; i < size; i++)
	{
		res = ft_atoi(tests[i]);
		exp = atoi(tests[i]);
		if (res != exp)
		{
			printf("ft_atoi(\"%s\") -> \033[0;31mFAILED!\033[0m :\nexpected -> %d\ngot      -> %d\n", tests[i], exp, res);
			return 1;
		}
		printf("\033[0;32mft_atoi(\"%s\"):\033[0m\nexpected -> %d\ngot      -> %d\033[0m\n", tests[i], exp, res);
	}
	printf("ft_atoi -> \033[0;32mPASSED!\033[0m\n");
	return 0;
}

int main()
{
	run();
}
