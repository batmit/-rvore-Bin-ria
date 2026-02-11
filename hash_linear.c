#include<stdlib.h>
#include<stdio.h>

#include "hash.h"


struct hash{

    int n;

    int *verificacao;
    int *vet;

};

Hash *criaHash(int n){

    Hash *hash = malloc(sizeof(Hash));

    hash->n = n;
    hash->verificacao = calloc(n, sizeof(int));
    hash->vet = malloc(n * sizeof(int));

    return hash;

}

void hashLibera(Hash *hash){


    free(hash->verificacao);
    free(hash->vet);

    free(hash);

}

void imprimirHash(Hash *hash){


    for(int i = 0; i < hash->n; i++){

        printf("%d - ", i);
        if(hash->verificacao[i] == 1){
            printf("%d ", hash->vet[i]);
        }
        printf("\n");

    }

}

void addHash(Hash *hash, int n){

    int posicao = pos(n);

    int cont = 0;

    while (hash->verificacao[posicao] != 0 && cont < M){
        if(hash->vet[posicao] == n){
            printf("Valor %d já está na tablela\n", n);
            return;
        }
        posicao = aumentarPos(posicao);
        cont++;
        
    }

    if(cont == hash->n){
        printf("Tabela cheia!\n");
        return;
    }


    hash->vet[posicao] = n;
    hash->verificacao[posicao] = 1;
    


}


int aumentarPos(int n){

    if( (n + 1) >= M){
        n = 0;
    }else{
        n++;
    }

    return n;


}


int pos(int chave){

    return chave % M;

}


void buscaLinear(Hash *hash, int n){

    int posicao = pos(n);
    int cont = 0;
    while(hash->vet[posicao] != n && cont < M){

        posicao = aumentarPos(posicao);
        cont++;


    }

    if(cont == M ){
        printf("Valor não encontrado\n");
        return;
    }

    printf("Valor encontrado na posicao: %d\n\n", posicao);
    


}