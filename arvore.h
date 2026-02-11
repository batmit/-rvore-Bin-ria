#ifndef ARVORE_H
#define ARVORE_H


typedef struct no No;
typedef struct ab AB;


//funções que o usuário acessa
AB *ArvoreCria(void);
void addNo(int n, AB *arvore);
void ArvoreRemove(AB **arvore);
void imprimeGeral(AB *arvore);
void numeroFolhas(AB *arvore);
void imprimirNiveis(No *aux, int controle);
void somaValores(AB *arvore);
void procuraValor(No *aux, int n);
int removerValor(AB *arvore, int n);

//Auxiliares
No* criaNo(int n, int level);
void recurssaoAddNo(No* aux, int n, int level);
void arvoreRemoveRecursiva(No *aux);
void imprimePreOrdem(No *aux);
void imprimePosOrdem(No *aux);
void caminhamentoCentral(No *aux);
void imprimirNivel(No *aux, int nivel);
void contarFolhas(No *Aux, int *n);
void somando(No *aux, int *n);
void remocaoValor(No **aux, int n);
No *maisProximo(No *aux);
void imprimirDecrescente(No* aux);
void imprimeIntervalor(No *aux, int a, int b);

#endif