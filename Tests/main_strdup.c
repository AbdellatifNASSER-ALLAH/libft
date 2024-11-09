#include "head.h"

static sigjmp_buf env;

void	seg_handler(int sig)
{
	(void) sig;
	siglongjmp(env, 1);
}

void	test(int t, const char *s)
{
	char	*res = NULL, *exp = NULL;
	int	seg_res = 0, seg_exp = 0;

	printf("\033[0;33mTest %d : ft_strdup(\"%s\")\033[0m",t, s);
	if (!sigsetjmp(env, 1))
		exp = strdup(s);
	else 
		seg_exp = 1;
	if (!sigsetjmp(env, 1))
		res = ft_strdup(s);
	else 
		seg_res = 1;
	if (seg_res && seg_exp)
		printf("\n\tSegfault both functions\n\t\033[0;32mPASSED!\033[0m\n");
	else if ((seg_res != seg_exp) || strcmp(res, exp))
	{
		printf("\033[0;31m-->FAILED!\n");
		if (seg_res != seg_exp){
			printf("\texp : |%s|\n",seg_exp ? "segfault!" : exp); 
			printf("\tres : |%s|\n\033[0m",seg_res ? "segfault!" : res); 
		}else if (strcmp(res, exp))
			printf("\texp : |%s|\n\tres : |%s|\n\033[0m", exp, res);
	} else {
		printf("\n\texp : |%s|\n\tres : |%s|\n", exp, res);
		printf("\t\033[0;32mPASSED!\033[0m\n");
	}

}

int main()
{
	signal(SIGSEGV, seg_handler);

	test(1, "something");
	test(2, "");
	test(3, NULL);
	test(4, "Hello, World!");
}
