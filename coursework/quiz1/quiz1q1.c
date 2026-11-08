#include <stdio.h>

int main(void) {
    long a;
    long b;
    long c = 1;
    long i;
    scanf("%ld %ld", &a, &b);
    for (i = 0; i < b; i++) {
        c = c * a;
    }
    printf("%ld", c);
    return 0;
}