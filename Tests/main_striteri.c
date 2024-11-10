#include "head.h"

void	seg_handler(int sig)
{
	(void) sig;
	// Print the line where the segfault happned
	write(2, "Segmentation fault occurred!\n", 29);

	// Obtain the backtrace
	void *array[10];
	int size = backtrace(array, 10);

	// Print the backtrace to stderr
	backtrace_symbols_fd(array, size, 2);

	exit(1);
}

void	f(unsigned int i, char *s)
{
	*s += i;
}

void	test(unsigned int i, char *s, void (*f)(unsigned int, char *),char *exp)
{
	printf("Test %d : ft_striteri(\"%s\", f):\n\texp : |%s|\n", i, s, exp);
	ft_striteri(s, f);
	printf("\tgot : |%s|\n", s);
	if (strcmp(exp, s))
		printf("\t\033[0;31mFAILED!\033[0m\n");
	else 
		printf("\t\033[0;32mPASSED!\033[0m\n");

}
int main() {
	signal(SIGSEGV, seg_handler);

	char t[][200] = { "aaaaaa", "bbbbb", "" };
	char te[][200] = {""};
	int j;
	// Prepare expected results by manually applying 'f' to 'te'
	for (size_t i = 0; i < sizeof(t)/ sizeof(t[0]); i++) {
		strcpy(te[i], t[i]);
		j = 0;
		while (te[i][j])
		{
			f(j, &te[i][j]);
			j++;
		}
	}

	// Test cases
	for (size_t i = 0; i < sizeof(t)/ sizeof(t[0]); i++) {
		test(i, t[i], f, te[i]);
	}

	// Test for segfaults
	ft_striteri(NULL, f);
	ft_striteri(NULL, NULL);
	ft_striteri(t[0], NULL);

	return 0;
}

