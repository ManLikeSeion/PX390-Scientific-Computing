#include<stdio.h>

int numfactors(long k);

int main(void){
    int result = numfactors(100);
    printf("%d\n", result);
    return 0;
}

int numfactors(long k) {
    #include<math.h>
    long j;
    int nfacs = 0;
    for(j=1; j<=k; j++) 
    {
        if (k%j == 0) nfacs++;
    }
    return nfacs;
}