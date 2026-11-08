/*************************************************
* This program demonstrates various pointer
* operations. The compiler should warn you
* about the incorrect pointer use. Try to
* fix this and compare the the bahviour on
* vonneumann and your own computer.
*
* Compile:
* gcc -Wall -g -std=c99 -ow5wrkshop w5wrkshop.c
***************************************************/
#include<stdio.h>
#include<stdlib.h>

int main(void) {

    int i;
     int j = 5;
     /* In declaration, operator '*' indicates pointer declaration.
     That is, the intention is to store memory addresses in this
     varable. The operator is not part of the variable name and
     can be placed together with the type, as shown below. */
    int* jpntr;
    jpntr = &j;
    /* Declarations for heap memory block allocation done later. */ 
     int *kvec;
     int *jvec;

    /* We first show that jpntr stores an undefined value, if it is not
        properly initialised . */ 
    printf("Value of jpntr before assignment: %p\n", (void*)jpntr);
    /* Here, the operator '*' returns a value stored in the memory location
        that has been stored in a pointer jpntr. */
    printf("Value stored at address pointed to by jpntr: %d\n",*jpntr);
    /* Now we properly initialise the pointer with a valid memory address of
        the stack variable j. Operator '&' returns a memory address of an object
        to which it is applied. The type of the variable and the type of the
        pointer must be compatibile. */
    printf("Value of jpntr (pointer address) after assignment: %p\n",jpntr); 
    printf("Value stored at address pointed to by jpntr: %d\n",*jpntr);

    /* We now look at pointers to heap memory block. Here, a block of 5 integers. */
    kvec = (int *)malloc(sizeof(int)*5);
    /* kvec pointer can be used as if it was an array name. */
    for (i = 0; i < 5; i++) {
    kvec[i] = -1;
    }
    kvec[3] = 42;
    printf("Value of kvec[3]: %d\n",kvec[3]); 

    /* Since each element of heap memory block has a known size in bites,
        C knows how to increment a pointer to each element in this block,
        starting from the memory address kvec (start of the memory block).
        Array element indexed by 'i' is located at (kvec+i). */
    /* We store the adress of the element indexed 1 in the memory block starting
    at memory address kvec to a new pointer jvec. I can still get to all
    following elements in the memory, but must be careful about the index in
    relation to kvec pointer.*/
    jvec = &(kvec[1]);
    /* Pointer jvec now points to the index 1 element, while kvec points
    to the location of the element indexed 0. */
    printf("Value of jvec[2]: %d ... jvec = &(kvec[1]) \n",jvec[2]);
    /* ... increment a pointer by one unit */ 
    jvec = jvec+1;
    /* We have moved the start of the memory block stored in jvec,
    so the indexing must also change if we are to recover the same element*/
    printf("Value of jvec[2]: %d ... jvec = kvec+2 \n",jvec[1]); 
    /* But the same can be done by directly dereferencing a pointer */  
    printf("Value of jvec[2]: %d ... *(kvec+1) \n", *(jvec+1)); 

    return(0);
}