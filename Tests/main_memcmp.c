#include "head.h"

void	test(int t, const void *p, const void * c , size_t n)
{
	ft_putstr_fd("test : ", 1);
	ft_putnbr_fd(t, 1);
	int	exp = memcmp(p, c, n);
	int	res = ft_memcmp(p, c, n);

	if (exp != res)
	{
		printf("\033[0;31mFAILED!\033[0m\n");
		printf("exp : %d |\nres : %d\n", exp, res);
	}
	else
	{
		printf("\nexp : |%d|\nres : |%d|\n", exp, res);
		printf("\033[0;32mPASSED!\033[0m\n");
	}
}

int main()
{
	// Regular comparisons with different lengths
	test(1, "abcdef", "abcxyz", 0);      // Comparison with n = 0 (should pass, expect res = 0)
	test(2, "abcdef", "abcxyz", 3);      // Partial comparison (should pass, expect res = 0)
	test(3, "abcdef", "abcxyz", 6);      // Full comparison (should fail, expect res < 0)

	// Comparing with empty strings
	test(4, "", "", 0);                  // Both empty, n = 0 (should pass, res = 0)
	test(5, "", "", 5);                  // Both empty, n > 0 (should pass, res = 0)
	test(6, "abcdef", "", 0);            // One empty, n = 0 (should pass, res = 0)
	test(7, "abcdef", "", 3);            // One empty, n > 0 (should fail, res > 0)

	// NULL pointers
	test(8, NULL, "abc", 0);             // NULL pointer, n = 0 (should pass, res = 0)
										 // The following case should be avoided, as memcmp(NULL, "abc", 3) is undefined behavior in C
										 // test(9, NULL, "abc", 3);

										 // Test with embedded null characters
	test(10, "abc\0def", "abc\0xyz", 7); // Comparison up to and beyond null char (should pass, expect res < 0)
	test(11, "abc\0def", "abc\0def", 7); // Identical strings with null (should pass, res = 0)

	// Edge cases with characters near signed/unsigned boundary
	char s1[] = {127, 0};
	char s2[] = {-128, 0};
	test(12, s1, s2, 1);                 // Comparison near boundary (127 vs -128)

	// Different lengths, partial match
	test(13, "abcdef", "abcdefg", 6);    // Only comparing up to first 6 chars (should pass, res = 0)
	test(14, "abcdef", "abcdefg", 7);    // Comparing with different lengths (should fail, res < 0)
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {1, 2, 3, 4, 6};
	int arr3[] = {1, 2, 3};
	test(15, arr1, arr2, sizeof(arr1));  // Compare two arrays of ints (should fail)
	test(16, arr1, arr1, sizeof(arr1));  // Compare same arrays (should pass)
										 // Compare arrays with different lengths (will fail)
	test(17, arr1, arr2, sizeof(arr1) - 1);  // Compare first 4 elements (should fail)

	// Compare arrays of different lengths (will fail)
	test(18, arr1, arr3, sizeof(arr1));  // Compare full arr1 with smaller arr3 (should fail)

	// Compare part of one array with another (will pass)
	test(19, arr1, arr2, sizeof(arr2));  // Compare first 5 elements (should pass)

	// Compare first 3 elements (will pass)
	test(20, arr1, arr2, sizeof(arr3));  // Compare first 3 elements (should fail if values differ)


	printf("ft_ %d \nstd %d\n", ft_memcmp("a", "z", 1), memcmp("a", "z", 1));

}
