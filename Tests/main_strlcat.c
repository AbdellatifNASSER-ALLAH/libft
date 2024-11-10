#include "head.h"
#include <string.h>

static sigjmp_buf env;

void	seg_handler(int sig)
{
	(void) sig;
	siglongjmp(env , 1);
}

void	test(int t, char *dst, const char *src, size_t size)
{
	size_t res = 0, exp = 0;
	int	seg_res = 0, seg_exp = 0;

	printf("\033[0;33mTest %d : ft_strlcat(\"%s\", \"%s\", %lu)\033[0m", t, dst, src, size);
	if (sigsetjmp(env , 1) == 0)
		exp = strlcat(dst, src, size);
	else
		seg_exp = 1;
	if (sigsetjmp(env , 1) == 0)
		res = ft_strlcat(dst, src, size);
	else
		seg_res = 1;
	if (seg_res && seg_exp)
		printf("\n\tSegfault both functions\n\t\033[0;32mPASSED!\033[0m\n");
	else if ((res != exp) || (seg_res != seg_exp))
	{
		printf("\033[0;31m-->FAILED!\n");
		if (seg_res != seg_exp){
			printf("\texp : |%s|\n",seg_exp ? "segfault!" : "noSeg"); 
			printf("\tres : |%s|\n\033[0m",seg_res ? "segfault!" : "noSeg"); 
		}else if (res != exp){
			printf("\texp : |%lu|\n\tres : |%lu|\n\033[0m", exp, res);
		}
	} else {
		printf("\n\texp : |%lu|\n\tres : |%lu|\n", exp, res);
		printf("\t\033[0;32mPASSED!\033[0m\n");
	}
}

int main()
{
	signal(SIGSEGV, seg_handler);

	// Test cases for ft_strlcat
	char dst1[50] = "Hello, ";
	char src1[] = "world!";
	test(1, dst1, src1, 50);  // Normal case

	char dst2[50] = "Hello, ";
	char src2[] = "world!";
	test(2, dst2, src2, 10);  // Buffer size smaller than needed

	char dst3[50] = "";
	char src3[] = "abc";
	test(3, dst3, src3, 5);  // Empty destination buffer

	char dst4[50] = "A";
	char src4[] = "longer string";
	test(4, dst4, src4, 10);  // Buffer size enough for part of source

	char dst5[50] = "Hello, ";
	char *src5 = NULL;  // NULL source
	test(5, dst5, src5, 50);  // NULL source

	// NULL destination
	test(6, NULL, "world", 50);  // NULL destination string

	// Test with very small buffer size
	char dst6[50] = "Hello";
	char src6[] = "world!";
	test(7, dst6, src6, 2);  // Only space for the first character


}

