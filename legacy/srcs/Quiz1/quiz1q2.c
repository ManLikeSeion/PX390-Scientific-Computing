//Write a function that takes two long integer values n and k as its inputs and returns a 
//long integer binomial coefficient C(n k), where n >= k and n, k <= 10. Function prototype should be:
//long binomial_coeff(long n, long k);

#include<stdio.h>

long binomial_coeff(long n, long k);

int main(void){
    long a;
    long b;
    scanf("%ld %ld", &a, &b);

    printf("%ld", binomial_coeff(a, b));

    return 0;
}

long binomial_coeff(long n, long k){
    // formula is n!/[k!(n-k)!]

    long result = 1;
    for (long i = 1; i <= k; i++) { // counts from i = 1 up to k
        result = result * (n - k + i) / i; //denominator counts up, while numerator counts up starting from n-k
    }

    return result;
}