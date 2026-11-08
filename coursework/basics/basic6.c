#include<stdio.h>

int main(void){
    //Establish an input
    int test;
    scanf("%d", &test);

    //Repeatedly do integer division until the value is 1
    while(test > 1){
        printf("%d\n", test);
        test = test / 2;
    }

    printf("%d\n", test);
    return 0;
}