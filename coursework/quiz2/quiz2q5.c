//Write a function to perform array permutation of a double type array of length N>=1. 
//The input array (named farr) should not be modified, but the array returned should be 
//a reindexed/permuted form of the input array, according to an index array (named iarr), 
//also of length N. You may assume that the indices in iarr are within the valid range. 
// For input array farr = {5, -1, 2, 0, 12} and the index array iarr2 = {1, 3, 4, 0, 2} 
// the expected output should be {-1, 0, 12, 5, 2}

#include<stdio.h>
#include<stdlib.h>
double *move_to_position(double *farr, int *iarr, int N);

int main(void){
    double farr[] = {5, -1, 2, 0, 12};
    int iarr2[] = {1, 3, 4, 0, 2};
    int N = 5;
    double *res = move_to_position(farr, iarr2, N);
    for (int i = 0; i < N; i++) {
        printf("%g%s", res[i], i == N - 1 ? "\n" : " ");
    }
    free(res);
    return 0;
}
 
double *move_to_position(double *farr, int *iarr, int N){
    double *newarr = malloc(sizeof(double) * N);
    int i;

    if (newarr == NULL) {
        return NULL;
    }

    for(i = 0; i<N; i++){
        newarr[i] = farr[iarr[i]];
    }
    return newarr;
}
