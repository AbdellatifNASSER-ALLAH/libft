#include "head.h"

static sigjmp_buf jump_buffer;

void sigsegv_handler(int sig) {
	// Capture the signal and return from the function.
	(void) sig;
	siglongjmp(jump_buffer, 1);
}

void test_memcpy_behavior(int t, void *dst, const void *src, size_t n)
{
	ft_putstr_fd("test : ", 1);
	ft_putnbr_fd(t, 1);
	ft_putstr_fd("---------------------Start-------------------", 1);
	int segv_exp = 0, segv_res = 0;
	void *exp = NULL, *res = NULL;

	// Test memcpy (standard)
	if (sigsetjmp(jump_buffer, 1) == 0) {
		exp = memcpy(dst, src, n);
	} else {
		ft_putstr_fd("\nstd __ seg\n" ,1);
		segv_exp = 1;
	}

	// Test ft_memcpy (your custom function)
	if (sigsetjmp(jump_buffer, 1) == 0) {
		res = ft_memcpy(dst, src, n);
	} else {
		ft_putstr_fd("\nft_ seg\n" ,1);
		segv_res = 1;
	}

	printf("\nres : %d |------- exp : %d \n", segv_res, segv_exp);
	// Compare the behavior and handle segmentation faults
	if (segv_exp && segv_res) {
		printf("\n\033[0;32mPASSED! (Both caused segfault)\033[0m\n");
	} else if (segv_exp && !segv_res) {
		printf("\n\033[0;31mFAILED! (memcpy caused segfault, but ft_memcpy did not)\033[0m\n");
	} else if (!segv_exp && segv_res) {
		printf("\033[0;31mFAILED! (ft_memcpy caused segfault, but memcpy did not)\033[0m\n");
	} else if (memcmp(exp, res, n) != 0) {
		printf("\033[0;31mFAILED!\033[0m\n");
		printf("exp : %s |\nres : %s\n", (char *)exp, (char *)res);
	} else {
		printf("\nexp : |%s|\nres : |%s|\n", (char *)exp, (char *)res);
		printf("\033[0;32mPASSED!\033[0m\n");
	}
	printf("----------------------------End test %d----------------------------\n\n", t);
}

int main()
{
	// Install the signal handler to catch segfaults
	signal(SIGSEGV, sigsegv_handler);

	// Test with normal data
	char src1[] = "Hello, world!";
	char dst1[50];
	test_memcpy_behavior(1, dst1, src1, strlen(src1) + 1);

	// Test with empty source (n = 0)
	char dst2[50];
	test_memcpy_behavior(2, dst2, "", 0);

	// Test with zero length
	test_memcpy_behavior(3, dst2, src1, 0);

	// Test with larger source, partial copy
	char dst3[50];
	test_memcpy_behavior(4, dst3, src1, 5);

	// Test with overlapping memory (simulating memcpy behavior)
	char src2[50] = "Overlapping test data";
	test_memcpy_behavior(5, src2 + 3, src2, 5);

	// Test with arrays of ints
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[5];
	test_memcpy_behavior(6, arr2, arr1, sizeof(arr1));

	// Test with arrays of different sizes
	int arr3[] = {1, 2, 3};
	test_memcpy_behavior(7, arr2, arr3, sizeof(arr1));

	// Test with null source (dst should remain unchanged)
	char dst4[50];
	test_memcpy_behavior(8, dst4, NULL, 10);

	// Test with null destination (undefined behavior)
	test_memcpy_behavior(9, NULL, src1, 10);

	// Test with small buffer (1 byte)
	char dst5[1];
	test_memcpy_behavior(10, dst5, "A", 1);

	// Test with large buffer (e.g., 1000 bytes)
	char dst6[1000];
	char src6[1000];
	memset(src6, 'A', 1000);
	test_memcpy_behavior(11, dst6, src6, 1000);

	// Test dest is null , src empty and size is non-zero value
	test_memcpy_behavior(12, NULL, "", 10);

	// Test dest empty string and src is null and size is non-zero value
	test_memcpy_behavior(13, "", NULL, 10);

	// Test dest and src both null and size is non-zero
	test_memcpy_behavior(14, NULL, 0, 10);

	// Test dest null string and size is 0
	test_memcpy_behavior(15, NULL, "", 0);

	// Test dest string src null and size is 0
	test_memcpy_behavior(16, "", NULL, 0);

	// Test dest null src null and size is 0
	test_memcpy_behavior(17, NULL, NULL, 0);
}

