#include <stdio.h>

int rational_approx(double x) {
    double x_1 = x;
    long a_1 = (long)x_1;
    if (x_1 < a_1) {
        a_1--;
    }
    // Initial setup 
    long n_0 = 0;
    long d_0 = 1;
    long n_1 = 1;
    long d_1 = 0;
    long n_2 = 0;
    long d_2 = 0;

    double small = 0.000001;
    int count = 0;

    for (long k = 2; k <= 4; k++) {

        // Find the next values
        n_2 = a_1 * n_1 + n_0;
        d_2 = a_1 * d_1 + d_0;
        double diff = x - (double)n_2 / d_2;
        if (diff < 0) {
            diff = -diff;
        }

        count++;

        if (diff < small || k == 4) {
            break;
        }
        if (x_1 == a_1) {
            break;
        }

        // Reassign
        n_0 = n_1;
        d_0 = d_1;
        n_1 = n_2;
        d_1 = d_2;

        double x_2 = 1.0 / (x_1 - a_1);
        long a_2 = (long)x_2;

        if (x_2 < a_2) {
            a_2--;
        }

        x_1 = x_2;
        a_1 = a_2;
    }

    printf("%ld/%ld", n_2, d_2);

    return count;
}