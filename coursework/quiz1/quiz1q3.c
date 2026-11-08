#include <stdio.h>
#include <limits.h>

int reverse_intnum(int num);

int main(void) {
    long x;
    scanf("%ld", &x);

    if (x < 0 || x > INT_MAX) {
        printf("0\n");
    } else {
        printf("%d\n", reverse_intnum(x));
    }

    return 0;
}

int reverse_intnum(int num) {
    long p = 0;
    long result = 0;
    if (num >= 0) {
        while (num > 0){
            long a = num % 10;
            num = num / 10;

            long new = 10 * p + a;
            p = new;

        }
        if(p>INT_MAX){
            return 0;
        }
        result = p;
    }

    return result;
}