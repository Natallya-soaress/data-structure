#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.c"
#include <sys/time.h>

int main(){

    struct timeval t0;
    struct timeval t1;
    float elapsed;
    int N = 10000-1;
    int *dados = (int*) malloc(sizeof(int)*N);
    int cont = 0;

    int size = 10007;
    Hash *table = criar_hash_enc_separado(size);
    //Hash *table = criaHash(size);

    printf("");
    for(int i = 0; i <= N; i++){
        dados[i] = (rand() % 10000);
    }

    struct aluno al, a[10000];

   for(int i=0; i <= N; i++){
       strcpy(a[i].nome, "Nat");
       a[i].matricula = dados[i];
       a[i].n1 = 8.8;
       a[i].n2 = 6.8;
       a[i].n3 = 8.4;
   }

    /*

    // Testes com endereço encadeado

    for(int i=0; i <= N; i++){
        insere_hash_enc_separado(table, a[i], &cont);
    }

    buscar_hash_encadSep(table, 748, &al);
    printf("\n%s, %d\n", al.nome, al.matricula); 

    
    printf("\ncont: %d \n", cont); */


    /*

    // Testes com enderaçamento aberto

    for(int i=0; i <= N; i++){
        insereHash_EnderAberto(table, a[i], &cont);
    }

    buscaHash_EnderAberto(table, 748, &al);
    printf("\n%s, %d\n", al.nome, al.matricula);
    
    printf("\ncont: %d \n", cont); */

    /*

    // Teste sem tratamento de colisões

    for(int i=0; i <= N; i++){
        insereHash_SemColisao(table, a[i], &cont);
    }
    
    buscaHash_SemColisao(table, 748, &al);
    printf("\n%s, %d\n", al.nome, al.matricula); 

    printf("\ncont: %d \n", cont);

    */

    return 0;
}   


