#include<stdio.h>

int main(void) {
    int a = 5; //define an integer a
    int *b; //define a pointer b
    b = &a; //b points to a
    printf("Value of pointer b (memory location): %p \n",(void *) b);
    printf("Value at memory pointed to by b: %d \n",*b);
    a = 6;
    printf("We set value of a to %d \n",a);
    printf("And value at memory pointed to by b is now %d \n",*b);
    printf("Value of pointer b (memory location) still: %p \n",(void *) b);
    return 0;
}