#include <stdio.h>
#include <limits.h>

int main(void) {
    double x = 1.234567890123456789;
    float y = (float)x;
    double z = (double)y;

    printf("Original double: %.15f\n", x);
    printf("Converted float: %.15f\n", y);
    printf("Back to double: %.15f\n", z);

    int d = INT_MAX;
    d = d + 1;
    unsigned int e = UINT_MAX;
    e = e + 1;

    printf("Long: %d, Unsigned: %u\n", d, e);
    return 0;
}