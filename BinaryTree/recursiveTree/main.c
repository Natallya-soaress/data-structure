#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinaria.h"
#include "ArvoreBinaria.c"

int main(){

    struct timeval t0;
    struct timeval t1;
    float elapsed;
    int N = 100000;
    int *dados =(int*) malloc(sizeof(int)*N);

    srand(time(NULL));
    for(int i = 0; i <=  N; i++){
        dados[i] = (rand() % 1000000);
    }    
    
    ArvBin* raiz = cria_ArvBin();
    
    

    for(int i=0; i < N; i++)    
        insere_ArvBin(raiz, dados[i]);

    
    //libera_ArvBin(raiz);

    gettimeofday(&t0, 0);
    preOrdem_ArvBin(raiz);
    gettimeofday(&t1, 0);
    
    elapsed = timedifference_msec(t0, t1);

    

    printf("Code executed in %f milliseconds.\n", elapsed);
    return 0;
}
