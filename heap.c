#include<stdio.h>
#include<stdlib.h>

void refazHeap(int *heap, int n, int i);

void heapSort(int *heap, int n, int i);

int main(){

    int vet[7] = {9, 10, 20, 6, 3, 8, 17};

    // i = n/2 -1
    heapSort(vet , 7, 7);

    printf("[ ");
    for(int i = 0; i < 7; i++){
        printf("%d, ", vet[i]);
    }
    printf(" ]");

    return 0;
}

void refazHeap(int *heap, int n, int i){


    if(i < 0){
        return;
    }
    int aux;
    
    int maior = 0;

    int f1 = 2 * i + 1; 
    int f2 = 2 * i +2;
    

    if(f1 >= n){
        f1 = -1;
    }
    if(f2 >= n){
        f2 = -1;
        maior = f1;
    }
    if(maior == 0){
        if(heap[f1] > heap[f2]){
            if(heap[f1] > heap[i]){
                aux = heap[f1];
                heap[f1] = heap[i];
                heap[i] = aux;
            }
        }else{
            if(heap[f2] > heap[i]){
                aux = heap[f2];
                heap[f2] = heap[i];
                heap[i] = aux;
            }
        }
    }else if(maior == f1){
        if(heap[f1] > heap[i]){
            aux = heap[f1];
            heap[f1] = heap[i];
            heap[i] = aux;
        }

    }
    refazHeap(heap, n, i -1);

}

void heapSort(int *heap, int n, int i){

    if(n == i){
        refazHeap(heap, n, (n/2) -1);
    }
    if(i == 1){
        return;
    }
    int aux;
    //Acho último nó = i-1

    aux = heap[0];
    heap[0] = heap[i -1];
    heap[i - 1] = aux;

    refazHeap(heap, i -1, ((i -1) /2) -1);

    heapSort(heap, n, i-1);


}
