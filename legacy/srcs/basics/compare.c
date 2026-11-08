#include<stdio.h>

int main(void){
    int a; //declare a
    scanf("%d", &a); //ask the user for an input and point it to the memory location of a

    if(a > 0){
        printf("Positive Number\n");
    }
    else if(a == 0){
        printf("Zero\n");
    }
    else{
        printf("Negative Number\n");
    }

    return 0;
}