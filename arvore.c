#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"

struct no{

    int valor;
    struct no *direita;
    struct no*esquerda;
    int n;
    int nivel;

};

struct ab{

    No *raiz;
    
    //int n;

};

AB *ArvoreCria(void){

    AB *arvore = malloc(sizeof(AB));
    arvore->raiz = NULL;

    return arvore;


}

void ArvoreRemove(AB **arvore){

    if((*arvore)->raiz != NULL){
        arvoreRemoveRecursiva((*arvore)->raiz);
        (*arvore)->raiz = NULL;
    }

    free(*arvore);
    *arvore = NULL;


}

void arvoreRemoveRecursiva(No *aux){

    if(aux == NULL){
        return;
    }

    
    arvoreRemoveRecursiva(aux->esquerda);
    
    arvoreRemoveRecursiva(aux->direita);

    free(aux);


}

void addNo(int n, AB *arvore){

    if(arvore->raiz == NULL){

        arvore->raiz = criaNo(n, 0);
        return;
    }else{

        recurssaoAddNo(arvore->raiz, n, 1);

    }



}

void recurssaoAddNo(No* aux, int n, int level){

    if(aux == NULL){
        return;
    }

    if(n > aux->valor){
        if(aux->direita == NULL){
            aux->direita = criaNo(n, level);
            

        }else{
            recurssaoAddNo(aux->direita, n, level + 1);
        }    
    }
    if(n < aux->valor){
        if(aux->esquerda == NULL){
            aux->esquerda = criaNo(n, level);


        }else{
            recurssaoAddNo(aux->esquerda, n, level + 1);
        }
    }

    if(n == aux->valor){
        aux->n++;

    }

    return;

}

No* criaNo(int n, int level){

    No *novo = malloc(sizeof(No));

    novo->valor = n;
    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->n=0;
    novo->nivel = level;
    return novo;

}

void imprimeGeral(AB *arvore){

    //imprimePreOrdem(arvore->raiz);
    //imprimePosOrdem(arvore->raiz);
    //caminhamentoCentral(arvore->raiz);
    //imprimirNiveis(arvore->raiz, 3);
    //imprimirDecrescente(arvore->raiz);

    imprimeIntervalor(arvore->raiz, 5, 10);
}

void imprimePreOrdem(No *aux){

    if(aux == NULL){
        return;
    }

    printf(" %d -", aux->valor);
    imprimePreOrdem(aux->esquerda);
    imprimePreOrdem(aux->direita);
    

}

void imprimePosOrdem(No *aux){

    if(aux == NULL){
        return;
    }

    imprimePosOrdem(aux->esquerda);
    imprimePosOrdem(aux->direita);
    printf(" %d -", aux->valor);

}

void caminhamentoCentral(No *aux){

    if(aux == NULL){
        return;
    }

    caminhamentoCentral(aux->esquerda);
    printf(" %d %d-", aux->valor, aux->nivel);
    caminhamentoCentral(aux->direita);

}

void imprimirNiveis(No *aux, int controle){


    for(int i = 0; i < controle; i++){
        imprimirNivel(aux, i);
    }



}

void imprimirNivel(No *aux, int nivel){

    if(aux == NULL){
        return;
    }

    if(aux->nivel == nivel){
        printf(" %d -", aux->valor);

    }

    imprimirNivel(aux->esquerda, nivel);

    imprimirNivel(aux->direita, nivel);


}

void numeroFolhas(AB *arvore){

    int n = 0;
    contarFolhas(arvore->raiz, &n);

    printf("%d", n);

}

void contarFolhas(No *aux, int *n){

    if(aux == NULL){
        return;
    }

    if(aux->direita == NULL && aux->esquerda == NULL){
        *n = *n + 1;
    }

    contarFolhas(aux->esquerda, n);
    contarFolhas(aux->direita, n);



}

void somaValores(AB *arvore){

    int n = 0;

    somando(arvore->raiz, &n);

    printf("%d", n);

}

void somando(No *aux, int *n){

    if(aux == NULL){
        return;
    }

    *n = *n + aux->valor;

    somando(aux->esquerda, n);
    somando(aux->direita, n);

}


int removerValor(AB *arvore, int n){

    remocaoValor(&(arvore->raiz), n);
    return 1;

}

void remocaoValor(No **aux, int n){

    if(*aux == NULL){
        return;
    }

    if((*aux)->valor < n){
        remocaoValor(&(*aux)->direita, n);
        return;
    }
    if((*aux)->valor > n){
        remocaoValor(&(*aux)->esquerda, n);
        return;
    }

    if((*aux)->valor == n){

        No *reserva = *aux; 
        if((*aux)->direita == NULL && (*aux)->esquerda == NULL){
            free(*aux);
            *aux = NULL;
            return;
        }
        if((*aux)->esquerda == NULL ){
            *aux = (*aux)->direita;
            free(reserva);
            return;

        }else if((*aux)->direita == NULL){
            *aux = (*aux)->esquerda;
            free(reserva);
            return;
        }

        No *troca = maisProximo(*aux);

        (*aux)->valor = troca->valor;
        remocaoValor(&(*aux)->direita, troca->valor);


    }

}

No *maisProximo(No *aux){

    aux = aux->direita;

    while(aux->esquerda != NULL){
        aux = aux->esquerda;
    }

    return aux;



}


void imprimirDecrescente(No* aux){

    if(aux == NULL){
        return;
    }

    imprimirDecrescente(aux->direita);
    printf(" %d -", aux->valor);
    imprimirDecrescente(aux->esquerda);

}

void imprimeIntervalor(No *aux, int a, int b){

    if(aux == NULL){
        return;
    }
    if(aux->valor > a){
        imprimeIntervalor(aux->esquerda, a, b);
    }

    if(aux->valor > a && aux->valor < b){
        printf(" %d -", aux->valor);
    }

    if(aux->valor < b){
        imprimeIntervalor(aux->direita, a, b);
    }

   
    

}