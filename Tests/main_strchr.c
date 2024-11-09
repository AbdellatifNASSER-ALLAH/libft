#include "head.h"

static sigjmp_buf env;

void	seg_handler(int sig)
{
	(void) sig;
	siglongjmp(env , 1);
}

void	test(int t, const char *s, int c)
{
	char *res = NULL, *exp = NULL;
	int	seg_res = 0, seg_exp = 0;

	printf("\033[0;33mTest %d : ft_strchr(\"%s\", '%c'/%d)\033[0m", t, s, c, c);
	if (sigsetjmp(env , 1) == 0)
		exp = strchr(s, c);
	else
		seg_exp = 1;
	if (sigsetjmp(env , 1) == 0)
		res = ft_strchr(s, c);
	else
		seg_res = 1;
	if (seg_res && seg_exp)
		printf("\n\tSegfault both functions\n\t\033[0;32mPASSED!\033[0m\n");
	else if ((res != exp) || (seg_res != seg_exp))
	{
		printf("\033[0;31m-->FAILED!\n");
		if (seg_res != seg_exp){
			printf("\texp : |%s|\n",seg_exp ? "segfault!" : exp); 
			printf("\tres : |%s|\n\033[0m",seg_res ? "segfault!" : res); 
		}else if (!res || !exp || strcmp(res, exp)){
			printf("\texp : |%s|\n\tres : |%s|\n\033[0m", exp, res);
		}
	} else {
		printf("\n\texp : |%s|\n\tres : |%s|\n", exp, res);
		printf("\t\033[0;32mPASSED!\033[0m\n");
	}
}

int main()
{
	signal(SIGSEGV, seg_handler);


	test(1, "Hello, world!", 'o');  // Normal test case (should pass)
	test(2, "Hello, world!", 'z');  // Character not found (should return NULL)
	test(3, "", 'a');  // Empty string (should return NULL)
	test(4, NULL, 'a');  // NULL string (should segfault)
	test(5, NULL, 0);  // NULL string (should segfault)
	test(6, "hello hi", 0);  // NULL string (should segfault)
	test(7, "Hello, world!", 'o');  // Testing first case again
}
