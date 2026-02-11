#include<stdio.h>
#include "arvore.h"

int main(){

    AB *arvore = ArvoreCria();

    
    addNo(7, arvore);
    
    addNo(5, arvore);
    addNo(10, arvore);
    addNo(4, arvore);
    addNo(6, arvore);
    addNo(9, arvore);
    addNo(14, arvore);

    //somaValores(arvore);
    imprimeGeral(arvore);
    //removerValor(arvore, 10);
    printf("\n");
    //imprimeGeral(arvore);
    //numeroFolhas(arvore);
    ArvoreRemove(&arvore);


    return 0;
}