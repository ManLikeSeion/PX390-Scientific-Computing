#include<stdio.h>
#include<stdlib.h>

#define ages 80

long *make_ages(void);

int main(void){
    long *my_ages = make_ages();
    my_ages[19] = 99;
    
    for(int i = 0; i < ages; i++){
        printf("Age %d: %ld\n", i+1, my_ages[i]);
    }

    free(my_ages);
    return 0;
}

long *make_ages(void){
    long i;
    long *array = malloc(sizeof(long)*80);
    for(i = 0; i < ages; i++){
        array[i] = i+1;
    }
    return array;
}