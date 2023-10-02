#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "func.c"
#include "sort.c"

//gerar arquivo
int main(){
    FILE *ran, *inv, *ord;
    long *vetor;
    char nome[30];
    int menu = 0, tam = 1000000, submenu = 0;
    double Tempo = 0.0;
    struct timeval begin, end;

    //tamanho do arquivo
    printf("Tamanho do arquivo\n");
    scanf("%d", &tam);

    //tipo de arquivo
    printf("Escolher arquivo\n");
    printf("1 - Aleatorio\n");
    printf("2 - Invertido\n");
    printf("3 - Ordenado\n");

    scanf("%d", &submenu);

    switch (submenu){
        case 1:
            fileGenerator(ran, tam);
            sprintf(nome, "random%d.txt", tam);
            fileReader(ran, vetor, nome);
            break;
        case 2:
            invertedFileGenerator(inv, tam);
            sprintf(nome, "invertido%d.txt", tam);
            fileReader(inv, vetor, nome);
            break;
        case 3:
            orderedFileGenerator(ord, tam);
            sprintf(nome, "ordenado%d.txt", tam);
            fileReader(ord, vetor, nome);
            break;
        default:
            printf("Opcao invalida");
            break;
    }

    printf("Escolher metodo de ordenacao\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Insert Sort\n");
    printf("3 - Merge Sort\n");
    printf("4 - Radix Sort\n");
    printf("5 - Quick Sort Hoare\n");
    printf("6 - Quick Sort Lomuto\n");
    scanf("%d", &menu);
    
    vetor = (long*)malloc(tam*sizeof(long));

    switch (menu){
        case 1:
            gettimeofday(&begin, NULL);
            insertsort(vetor, tam);
            gettimeofday(&end, NULL);
            Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
            break;
        case 2:
            gettimeofday(&begin, NULL);
            insertsort(vetor, tam);
            gettimeofday(&end, NULL);
            Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
            break;
        case 3:
            gettimeofday(&begin, NULL);
            mergeSort(vetor, 0, tam-1);
            gettimeofday(&end, NULL);
            Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
            break;
        case 4:
            gettimeofday(&begin, NULL);
            radixSort(vetor, tam);
            gettimeofday(&end, NULL);
            Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
            break;
        case 5:
            gettimeofday(&begin, NULL);
            quickSortHoare(vetor, 0, tam-1);
            gettimeofday(&end, NULL);
            Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
            break;
        case 6:
            gettimeofday(&begin, NULL);
            quickSortLomuto(vetor, 0, tam-1);
            gettimeofday(&end, NULL);
            Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
            break;
        default:
            printf("Opcao invalida");
            break;
    }

    //imprimir vetor ordenado sim ou nao
    vetorOrdenado(vetor, tam);

    printf("-------------------------------------------------------\n");
    printf("Tempo de execucao: %.8f\n", Tempo);

    return 0;
}

