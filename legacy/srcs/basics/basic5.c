#include <stdio.h>

int polygon_tesselates(int numsides);

int main(void){
    int test = -1;
    printf("Type a number to test tesselation\n");
    scanf("%d", &test);
    int result = polygon_tesselates(test);
    printf("%d\n", result);
    return 0;
}

int polygon_tesselates(int numsides){
    if(numsides == 3 || numsides == 4 || numsides == 6){
        return 1;
    }
    else{
        return 0;
    }
}