#include <stdio.h>
#include <stdlib.h>

// Function prototype
long int n_pairs_ratio(long int *arr, long int N);

int main(void){

    // Define a test array
    long int arr[] = {4, -2, 8, 1};

    // Calculate the number of elements
    long int N = sizeof(arr) / sizeof(arr[0]);

    // Call the function
    long int result = n_pairs_ratio(arr, N);

    // Print the result
    printf("Number of valid pairs: %ld\n", result);

    return 0;
}

long int n_pairs_ratio(long int *arr, long int N){
    long int i, j;
    long int count = 0;
    for(i = 0; i < N - 1; i++){
        for(j = i + 1; j < N; j++){
            if(arr[i] != 0 && labs(arr[j]) < labs(arr[i])){
                count++;
            }
        }
    }
    return count;
}