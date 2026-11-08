#include<stdio.h>
#include<stdlib.h>

//Write a function which concatenates two long integer arrays of known size 
//and returns a pointer to a heap memory block where the new array is located. 
//The new array is the concatenation of the two input arrays 'arr1' and 'arr2' 
//(i.e., all the elements in the first array followed by all the elements in the second array). 
//Use malloc function to allocate the memory for the concatenated array. 
//For example, if arr1 contains [2,5,1] and arr2 contains [8], the array newarr should contain elements [2,5,1,8]. 
//You may assume that each array has at least 1 element.
//The prototype is:
 
//Nar1 and Nar2 are the numbers of elements in arr1 and arr2, respectively.

#include <stdio.h>
#include <stdlib.h>

long*  concat_arrays(long *arr1, int Nar1, long *arr2, int Nar2);

int main(void){
    long ages1[] = {1, 2, 3, 4};
    long ages2[] = {5, 6, 7, 8};
    int Nar1 = 4, Nar2 = 4;
    long* ages3 = concat_arrays(ages1, Nar1, ages2, Nar2);

    if(ages3 == NULL){
        return 1;
    }

    printf("%ld\n", ages3[5]);
    free(ages3);
    return 0;
}

long*  concat_arrays(long *arr1, int Nar1, long *arr2, int Nar2){
    //Objective here is to make a new uninitialised array of size Nar1 + Nar2 and put all the array elements of array 1 in, and then all of 2.
    long int i, j;
    long length = Nar1 + Nar2;
    long* newarr = malloc(sizeof(long)*length);

    if(newarr == NULL){
        return NULL;
    }

    for(i = 0; i < Nar1; i++){
        newarr[i] = arr1[i];
    }
    for (j = 0; j < Nar2; j++){
        newarr[Nar1 + j] = arr2[j];
    }
    return newarr;
}