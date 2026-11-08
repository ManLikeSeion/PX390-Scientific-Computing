#include<stdio.h>
void dolittle(int a) {
    printf("increase value of a in dolittle\n");
    a = a + 5;
}

void dosomething(int *a) {
    printf("increase value of a in dosomething\n");
    *a = *a + 5;
}

int main(void) {
    int a = 5;
    printf("Value of a: %d \n", a);
    dolittle(a); //applies dolittle to a, making a copy of it that is never returned to the original memory address of a.
    printf("Value of a after dolittle: %d \n", a); //so this prints 5
    dosomething(&a); //applies dosomething to the memory at address of a
    printf("Value of a after dosomething: %d \n", a); //so this prints 10 like you'd expect
    return 0;
}