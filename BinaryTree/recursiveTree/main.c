#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinaria.h"
#include "ArvoreBinaria.c"

int main(){
    
    ArvBin* raiz = cria_ArvBin();

    insere_ArvBin(raiz, 25);
    insere_ArvBin(raiz, 28);
    insere_ArvBin(raiz, 27);
    insere_ArvBin(raiz, 29);
    insere_ArvBin(raiz, 20);
    insere_ArvBin(raiz, 19);
    insere_ArvBin(raiz, 21);
    

    emOrdem_ArvBin(raiz);

    //libera_NoPar(raiz);

    

    printf("\n%d", totalNoFolha_ArvBin(raiz));
    //printf("\n%d", totalNoNaoFolha_ArvBin(raiz));
    emOrdem_ArvBin(raiz);

    //printf("\n%d", e_folha(raiz));

    return 0;
}
