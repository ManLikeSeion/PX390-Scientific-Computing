//Given an array of N long integer values a_n with n = 0, 1,..., N-1, 
//calculate the number of elements with values within a closed interval specified by two long integers a and b, 
//[a, b], where b > a. For example, for the input array arr = [1, 2, -3, 3, 1, 0, -1, -2, 0] 
//and the interval [-1,1] the return value should be 5.
 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long int n_elements_in_range(long int *arr, long int N, long int a, long int b);

int main(void){
    long int myarr[] = {1,2,3,4,5,6,7,8,9};
    long int *p = myarr;
    long int low = 2;
    long int high = 7;
    long int length = 9;

    printf("%ld\n", n_elements_in_range(p, length, low, high));
    return 0;
}

long int n_elements_in_range(long int *arr, long int N, long int a, long int b){
    long int i;
    long int count = 0;
    for(i = 0; i < N; i++){
        if(arr[i] >= a && arr[i] <= b){
            count++;
        }
    }
    return count;
}