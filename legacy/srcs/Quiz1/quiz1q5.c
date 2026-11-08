// Write a function with prototype
//int isprime(long k);
//Use a loop to determine whether a number is prime by checking if it is divisible by another natural number above 1. The code should be a function, returning true (i.e, non-zero) if prime, false (zero) if non-prime (you may assume the input is a natural number).
//All testing will be performed with smallish primes so there is no need to worry too much about efficiency.

#include<stdio.h>

int isprime(long k);

int main(void){
    long input = 0;
    scanf("%ld", &input);
    printf("%d", isprime(input)); //Should return 1 if prime, 0 if non-prime
    return 0;
}

int isprime(long k){

    if(k < 2){
        return 0;
    }

    for(long i = 2; i<k-1 ; i++){
        if(k%i == 0){
            return 0;
        }
    }
    return 1;
}