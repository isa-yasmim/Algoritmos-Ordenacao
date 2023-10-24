#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void bubblesort(long vetor[], int tam){

  for (int x = tam; x>1; x--){
    for (int y = 0; y<x-1; y++){
        if (vetor[y] > vetor[y+1]){        
            int aux = vetor[y];
            vetor[y] = vetor[y+1];
            vetor[y+1] = aux;
      }
    }
  }  

}

void insertsort(long vetor[], int tam) {

    for (int x = 1; x < tam; x++) {
        int aux = vetor[x];
        int y = x - 1;
    while ((y >= 0) && (aux < vetor[y])) {
        vetor[y + 1] = vetor[y];
        y = y - 1;
        vetor[y + 1] = aux;
    }
  }

}

//

void mergeSort(long dados[], int esq, int dir)
{
    if(esq < dir){
        int meio = (esq + dir) / 2;
        mergeSort(dados, esq, meio);
        mergeSort(dados, meio+1, dir);
        merge(dados, esq, meio, dir);
    }
}

void merge(long dados[], int esq, int meio, int dir){
    int auxSize = dir - esq + 1;
    int aux[auxSize];

    for(int i = esq; i<=dir; i++){
        aux[i - esq] = dados[i];
    }

    int i = esq;
    int j = meio + 1;
    int k = esq;

    while(i <= meio && j <= dir){
        if(aux[i - esq] <= aux[j - esq]){
            dados[k] = aux[i - esq];
            i++;
        }else{
            dados[k] = aux[j - esq];
            j++;
        }
        k++;
    }

    while(i <= meio){
        dados[k] = aux[i - esq];
        k++;
        i++;
    }

    while(j <= dir){
        dados[k] = aux[j - esq];
        k++;
        j++;
    }
    
}

//

void radixSort(long dados[], long tam)
{
    int base = 10, r;
    int digit = 3;
    long *B = (long*) malloc(sizeof(long) * tam);
    long *C = (long*) malloc(sizeof(long) * tam);

    for(int m = 0; m < digit; m++)
    {
        for(int i = 0; i < base; ++i)
        {
            C[i] = 0;
        }
        for(int j = 0; j < tam; ++j)
        {
            r = (dados[j] / (long)(pow(10.0,m))) % base;
            ++C[r];
        }
        for(int i = 1; i < base; ++i)
        {
            C[i] += C[i - 1];
        }
        for(int j = tam - 1; j >= 0; --j)
        {
            r = (dados[j]/(int)(pow(10.0, m))) % base;
            int i = --C[r];
            B[i] = dados[j];
        }
        for(int j = 0; j < tam; ++j)
        {
            dados[j] = B[j];
        }
    }
}

//

int partitionHoare(long dados[], int esq, int dir){
    int meio = (esq + dir) / 2;
    int pivot = dados[meio];
    int down = esq;
    int up = dir;

    while(down < up){
        while(dados[down] <= pivot && down < dir){
            down++;
        }
        while(dados[up] > pivot){
            up--;
        }
        if(down < up){
            int aux = dados[down];
            dados[down] = dados[up];
            dados[up] = aux;
        }
    }

    dados[esq] = dados[up];
    dados[up] = pivot;

    return up;
}

void quickSortHoare(long dados[], int esq, int dir)
{
    int i;
    if(esq < dir){
        i = partitionHoare(dados, esq, dir);
        quickSortHoare(dados, esq, i-1);
        quickSortHoare(dados, i+1, dir);
    }

}

//

int partitionLomuto(long dados[], int esq, int dir){
    int meio = (esq + dir) / 2;
    int pivot = dados[meio];
    int i = esq - 1;

    for(int j = esq; j <= dir - 1; j++){
        if(dados[j] < pivot){
            i++;
            int aux = dados[i];
            dados[i] = dados[j];
            dados[j] = aux;
        }
    }

    int aux = dados[i+1];
    dados[i+1] = dados[dir];
    dados[dir] = aux;

    return i+1;
}

void quickSortLomuto(long dados[], int esq, int dir)
{
    int i;
    if(esq < dir){
        i = partitionLomuto(dados, esq, dir);
        quickSortLomuto(dados, esq, i-1);
        quickSortLomuto(dados, i+1, dir);
    }

}

// 

void heapifyDown(int dados[], long tam, int i)
{
    int maior = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;
           
    if(esq < tam && dados[esq] > dados[maior])
        maior = esq;

    if(dir < tam && dados[dir] > dados[maior])
        maior = dir;

    if(maior!=i)
    {
        int aux = dados[i];
        dados[i] = dados[maior];
        dados[maior] = aux;
        heapifyDown(dados, tam, maior);
    }
    
}

void heapSort(int dados[], long tam)
{
    for(int i = tam/2 - 1; i >= 0; --i)
    {
        heapifyDown(dados, tam, i);
    }
    for(int i = tam - 1; i >= 0; --i)
    {
        int aux = dados[0];
        dados[0] = dados[i];
        dados[i] = aux;
        heapifyDown(dados, i, 0);
    }
}