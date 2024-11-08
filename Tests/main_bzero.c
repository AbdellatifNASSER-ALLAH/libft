#include "head.h"

// Test ft_bzero and compare it with standard bzero
void test_bzero(size_t size) {
	// Allocate two arrays with the same size
	char *buffer1 = malloc(size);
	char *buffer2 = malloc(size);

	if (!buffer1 || !buffer2) {
		perror("Failed to allocate memory");
		return;
	}

	// Fill both arrays with non-zero values
	memset(buffer1, 'A', size);
	memset(buffer2, 'A', size);

	// Use standard bzero and your ft_bzero function
	bzero(buffer1, size);
	ft_bzero(buffer2, size);

	// Compare the two arrays
	if (memcmp(buffer1, buffer2, size) == 0) {
		printf("Test passed for size %zu.\n", size);
	} else {
		printf("Test failed for size %zu.\n", size);
	}

	// Free allocated memory
	free(buffer1);
	free(buffer2);
}

int main() {
	// Test with different sizes
	test_bzero(0);
	test_bzero(10);
	test_bzero(20);
	test_bzero(50);
	test_bzero(100);

	return 0;
}

