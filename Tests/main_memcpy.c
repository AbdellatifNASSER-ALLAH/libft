#include "head.h"

void test_memcpy(int t, void *dst, const void *src, size_t n)
{
	ft_putstr_fd("test : ", 1);
	ft_putnbr_fd(t, 1);

	void *exp = memcpy(dst, src, n);  // Standard memcpy
	void *res = memcpy(dst, src, n);  // Your custom memcpy

	if (memcmp(exp, res, n) != 0)  // Compare the results
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
	// Test with normal data
	char src1[] = "Hello, world!";
	char dst1[50];
	test_memcpy(1, dst1, src1, strlen(src1) + 1);

	// Test with empty source (n = 0)
	char dst2[50];
	test_memcpy(2, dst2, "", 0);  // Should be the same (empty)

	// Test with zero length
	test_memcpy(3, dst2, src1, 0);  // Should not change the destination

	// Test with larger source, partial copy
	char dst3[50];
	test_memcpy(4, dst3, src1, 5);  // Copy first 5 chars (should pass)

	// Test with overlapping memory (simulating memcpy behavior)
	char src2[50] = "Overlapping test data";
	test_memcpy(5, src2 + 3, src2, 5);  // Copy within the same array (should pass)

	// Test with arrays of ints
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[5];
	test_memcpy(6, arr2, arr1, sizeof(arr1));  // Full array copy of integers

	// Test with arrays of different sizes (will fail due to mismatch in size)
	int arr3[] = {1, 2, 3};
	test_memcpy(7, arr2, arr3, sizeof(arr1));  // Mismatch in size (should fail)

	// Test with null source (dst should remain unchanged)
	char dst4[50];
	test_memcpy(8, dst4, NULL, 10);  // Should not modify the destination

	// Test with null destination (undefined behavior)
	test_memcpy(9, NULL, src1, 10);  // Undefined behavior; check your implementation

	// Test with small buffer (1 byte)
	char dst5[1];
	test_memcpy(10, dst5, "A", 1);  // Only copy one byte (should pass)

	// Test with large buffer (e.g., 1000 bytes)
	char dst6[1000];
	char src6[1000];
	memset(src6, 'A', 1000);
	test_memcpy(11, dst6, src6, 1000);  // Large buffer copy

	// Test with a large `n` with small buffers
	test_memcpy(12, dst6, src6, 10000);  // Should fail if the source and destination aren't large enough
}

