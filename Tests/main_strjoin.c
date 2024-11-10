#include "head.h"


void	seg_handler(int sig)
{
	(void) sig;
	write(2, "Segmentation fault occurred!\n", 29);
	exit(1);
}

void	test(int t, const char *s1, const char *s2, char *exp)
{
	char *res;

	printf("Test %d : ft_strjoin(\"%s\", \"%s\"):\n", t, s1, s2);
	res = ft_strjoin(s1, s2);
	if (res)
	{
		if (strcmp(res, exp) != 0)
		{
			printf("\texp: |%s|\n\tgot: |%s|\n", exp, res);
			printf("\t\033[31mFAILED!\033[0m\n");
		}
		else
		{
			printf("\texp: |%s|\n\tgot: |%s|\n", exp, res);
			printf("\t\033[32mPASSED!\033[0m\n");
		}
		free(res);
	}
	else
	{
		if (!res && !exp)
		{
			printf("\texp: |%s|\n\tgot: |%s|\n", exp, res);
			printf("\t\033[32mPASSED! (NULL result)!\033[0m\n");
		} else {
			printf("\texp: |%s|\n\tgot: |%s|\n", exp, res);
			printf("\t\033[31mFAILED! (NULL result)!\033[0m\n");
		}
	}
}

int main()
{
	signal(SIGSEGV, seg_handler);

	// Test cases
	test(1, "Hello, ", "world!", "Hello, world!");  // Normal test case
	test(2, "", "world!", "world!");  // Empty first string
	test(3, "Hello, ", "", "Hello, ");  // Empty second string
	test(4, "", "", "");  // Both strings are empty
	test(5, NULL, "world!", NULL);  // NULL first string
	test(6, "Hello, ", NULL, NULL);  // NULL second string
	test(7, NULL, NULL, NULL);  // Both are NULL

	return 0;
}
