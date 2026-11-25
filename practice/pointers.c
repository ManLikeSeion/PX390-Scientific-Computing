#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long *jumble(long *array, long len); 
// Declare the jumble function, which takes a pointer to an array of longs, 
// and its long length (pause), and returns a pointer to a long

int main(void){
    srand((unsigned int)time(NULL)); // Seeds the random number generator
    long *ages; //declare a pointer to somewhere in memory for our array
    long numberofpeople = 20, i;
    ages = (long *)malloc(sizeof(long) * numberofpeople); //allocate memory for our array
    
    if(ages == NULL){
        printf("MEMORY ALLOCATION FAILED!!! EXITING...");
        return EXIT_FAILURE;
    }

    for(i = 0; i<numberofpeople; i++){
        ages[i] = rand() %121; //Sets every array entry to a random number
        //up to 120.
    }

    long *jumbledages = jumble(ages, numberofpeople);
    if (jumbledages == NULL) {
        free(ages);
        return EXIT_FAILURE;
    }
    
   FILE *fp = fopen("practice/ages.txt", "w"); //open the file in write mode
    if (fp == NULL) {
        free(jumbledages);
        free(ages);
        return EXIT_FAILURE;
    }

    fprintf(fp, "UNJUMBLED: \n");
    for(i = 0; i<numberofpeople; i++){
        fprintf(fp, "%ld ", ages[i]);
    }
    fprintf(fp, "\nJUMBLED:\n");
    for(i = 0; i<numberofpeople; i++){
        fprintf(fp, "%ld ", jumbledages[i]);
    }
    fclose(fp); //all that writes the arrays to the file

    free(ages);
    free(jumbledages); /*free the allocated memory with some careful
    pointer tracking */
    return 0;
}

long *jumble(long *array, long len){
    long *newarr, j;
    if (array == NULL || len <= 0) {
        return NULL;
    }

    newarr = (long *)malloc(sizeof(long) * len);
    if(newarr == NULL){
        printf("MEMORY ALLOCATION 2 FAILED!!! EXITING...");
        return NULL;
    }

    for(j = 0; j < len; j++){
        newarr[j] = array[j];
    } //replicate the array to newarr

    /* Fisher-Yates shuffle: select from the remaining indices and swap
       (Wolfram MathWorld: https://mathworld.wolfram.com/Fisher-YatesShuffle.html). */
    for(j = len - 1; j > 0; j--){
        long randindex = rand() % (j + 1);
        long temp = newarr[j];
        newarr[j] = newarr[randindex];
        newarr[randindex] = temp;
    }

    return newarr;
}