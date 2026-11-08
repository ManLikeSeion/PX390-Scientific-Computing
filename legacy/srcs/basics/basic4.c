#include<stdio.h>

int main(void){
    int x, y;
    scanf("%d %d", &x, &y);
    int z = x-y;
    
    if(z<0)
    {
        z = z *-1;
    }
    printf("%d\n", z);
    return 0;
}