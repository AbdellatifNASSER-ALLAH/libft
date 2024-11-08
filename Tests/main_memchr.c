#include "head.h"

void	test(int t, void *p, int c , size_t n)
{
	ft_putstr_fd("test : ", 1);
	ft_putnbr_fd(t, 1);
	void	*exp = memchr(p, c, n);
	void	*res = ft_memchr(p, c, n);

	if (!res && !exp)
	{
		printf("\nexp : |%s|\nres : |%s|\n", (char *)exp, (char *)res);
		printf("\033[0;32mPASSED!\033[0m\n");
	}
	else if (strncmp(exp , res, n))
	{
		printf("\033[0;31mFAILED!\033[0m\n");
		printf("exp : %s |\nres : %s\n", (char *)exp, (char *)res);
	}
	else
	{
		printf("\nexp : |%s|\nres : |%s|\n", (char *)exp, (char *)res);
		printf("\033[0;32mPASSED!\033[0m\n");
	}
}

int main()
{
	test(1, "hassan ali", 'n', 0);
	test(2, "hassan ali", 'n', 10);
	test(3, "hassan ali", 'n', 2);
	test(4, "", 'n', 20);
	test(5, "hassan ali", '\0', 20);
	test(6, NULL, 'n', 0);
	test(7, "hassan ali", 'n', 20);
}
