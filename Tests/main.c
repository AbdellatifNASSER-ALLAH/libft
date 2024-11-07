#include <stdio.h>

void modify_arrays(int * a, int * b) {
    a[0] = 10;
    b[0] = a[0] + 5;
}

int main() {
    int data[2] = {1, 2};

    // a and b are overlapping: they both point to parts of the `data` array.
    int *a = &data[0];
    int *b = &data[0];

    modify_arrays(a, b);

    printf("data[0]: %d\n", data[0]);  // Output may vary
    printf("data[1]: %d\n", data[1]);  // Output may vary

    return 0;
}

