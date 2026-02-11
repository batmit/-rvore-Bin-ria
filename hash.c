#include "hash.h"
#include<stdlib.h>
#include<stdio.h>


struct celula{

    struct celula *prox;
    int chave;
    int valor;

};

struct hash{

    int n;

    Celula **celulas; // se fosse apenas um ponteiro aqui faria uma lista encadeada simples
    //Como eu desejo um vetor de listas encadeadas precisa ser ponteiro de ponteiro

};

Hash *criaHash(int n){

    Hash *hash = malloc(sizeof(Hash));
    hash->n = n;
    hash->celulas = malloc(n * sizeof(Celula*));
    for(int i = 0; i < n; i++){

        hash->celulas[i] = NULL;
    }

    return hash;

}

int pos(int chave){

    return chave % M;

}

void criarCelula(int n, Hash *hash){

    Celula *nova = malloc(sizeof(Celula));
    nova->valor = n;
    nova->chave = n;
    nova->prox = NULL;
    colocarnoHash(hash, nova);
}

void colocarnoHash(Hash *hash, Celula *celula){
    int posicao = pos(celula->chave);
    Celula *aux = hash->celulas[posicao];
    
    if(aux == NULL){
        hash->celulas[pos(celula->chave)] = celula;
    }else{

        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = celula;

    }



}

void printHash(Hash *hash){


    for(int i = 0; i < hash->n; i++){
        
        printf("%d -", i);

        Celula *aux = hash->celulas[i];

        while(aux != NULL){

            printf("%d - ", aux->valor);
            aux = aux->prox;

        }
        

        printf("\n");

    }

}

void busca(Hash *hash, int chave){

    int local = pos(chave);

    Celula *aux = hash->celulas[local];

    while(aux != NULL){

        if(aux->valor == chave){
            printf("Achado na linha %d\n\n", local);
            return;
        }
        aux = aux->prox;

    }


}

void removerCelula(Hash *hash, int chave){

    int posicao = pos(chave);

    Celula *aux = hash->celulas[posicao];
    if(aux == NULL){
        printf("Não encontrado\n");
        return;
    }
    if(aux->chave == chave){
        hash->celulas[posicao] = aux->prox;
        free(aux);
        return;
    }else{

        while (aux->prox != NULL){

            if(aux->prox->chave == chave){

                Celula *salvar = aux->prox;
                aux->prox = salvar->prox;
                free(salvar);
                return;

            }

            aux = aux->prox;
            
        }

    }

    

}
