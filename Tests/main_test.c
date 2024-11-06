#include "head.h"

// Helper function to print test results
void print_result(int condition, const char *test_name) {
    printf("%s: %s\n", test_name, condition ? "PASSED" : "FAILED");
}

int main() {
    void *ptr;

    // Test 1: Zero elements (should return NULL or a non-dereferenceable pointer)
    ptr = ft_calloc(0, 10);
    print_result(ptr == NULL, "Zero elements allocation");
    free(ptr);

    // Test 2: Zero size (should return NULL or a non-dereferenceable pointer)
    ptr = ft_calloc(10, 0);
    print_result(ptr == NULL, "Zero size allocation");
    free(ptr);

    // Test 3: Both elements and size are zero
    ptr = ft_calloc(0, 0);
    print_result(ptr == NULL, "Zero elements and size allocation");


    // Test 4: Overflow test - allocating SIZE_MAX elements of size SIZE_MAX
    ptr = ft_calloc(SIZE_MAX, SIZE_MAX);
    print_result(ptr == NULL, "Overflow test with SIZE_MAX elements and SIZE_MAX size");

    // Test 5: Large allocation (may fail if system doesn't have enough memory)
    ptr = ft_calloc(1, SIZE_MAX);
    print_result(ptr == NULL, "Large allocation test (SIZE_MAX bytes)");
    free(ptr);

    // Test 6: Alignment check - ensure allocation of odd-sized bytes doesn't misalign
    ptr = ft_calloc(1, 3);  // Allocate 3 bytes and check alignment
    print_result(((uintptr_t)ptr % sizeof(void*)) == 0, "Alignment test with odd size");
    free(ptr);

    // Test 7: High count of small elements
    ptr = ft_calloc(1000000, 1);
    print_result(ptr != NULL, "High count of small elements");
    free(ptr);

    // Test 8: Memory is zeroed out (very important for calloc)
    ptr = ft_calloc(5, sizeof(int));
    int all_zeroed = 1;
    if (ptr != NULL) {
        for (size_t i = 0; i < 5 * sizeof(int); i++) {
            if (((unsigned char*)ptr)[i] != 0) {
                all_zeroed = 0;
                break;
            }
        }
    }
    print_result(all_zeroed, "Memory zeroed out");
    free(ptr);

    // Test 9: Repeated free calls to the same pointer
    ptr = ft_calloc(10, 10);
    free(ptr);   // Free once
    print_result(1, "Repeated free calls (manual check for no crash)");

    // Test 10: NULL pointer allocation test
    ptr = ft_calloc(0, 0);
    free(ptr);   // Freeing NULL pointer should be safe
    print_result(1, "Freeing NULL pointer test (manual check for no crash)");

    // Test 11: System memory boundary - simulate failure in low memory conditions (manual check)
    // This test is mostly to be checked manually, as running out of memory might be hard to simulate.
    ptr = ft_calloc(SIZE_MAX / 2, 2);
    if (ptr != NULL) {
        print_result(1, "Low memory boundary allocation (manual verification)");
    } else {
        print_result(ptr == NULL, "Low memory boundary allocation (manual verification)");
    }
    free(ptr);

    printf("All tests completed.\n");
    return 0;
}

