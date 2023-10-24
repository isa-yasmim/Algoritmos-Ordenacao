#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "func.c"
#include "sort.c"

//gerar arquivo
int main(){
    FILE *ran, *inv, *ord;
    long *vetor;
    char nome[30];
    int menu = 99, tam = 1000000, submenu = 0;
    double Tempo = 0.0;
    struct timeval begin, end;
    
    vetor = (long*)malloc(tam*sizeof(long));

    while(menu != 0){
        printf("\n\n\n-------------------------------------------------------\n");
        printf("Escolher metodo de ordenacao\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Insert Sort\n");
        printf("3 - Merge Sort\n");
        printf("4 - Radix Sort\n");
        printf("5 - Quick Sort Hoare\n");
        printf("6 - Quick Sort Lomuto\n");
        printf("7 - Heap Sort\n");
        printf("10 - Gerar arquivo\n");
        printf("20 - Escolher arquivo\n");
        printf("30 - Imprimir vetor\n");
        printf("0 - Sair\n");
        scanf("%d", &menu);

        switch (menu){
            case 1:
                gettimeofday(&begin, NULL);
                bubblesort(vetor, tam);
                gettimeofday(&end, NULL);
                Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
                printf("Tempo de execucao: %.8f\n", Tempo);
                free(vetor);
                vetor = (long*)malloc(tam*sizeof(long));
                break;
            case 2:
                gettimeofday(&begin, NULL);
                insertsort(vetor, tam);
                gettimeofday(&end, NULL);
                Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
                printf("Tempo de execucao: %.8f\n", Tempo);
                free(vetor);
                vetor = (long*)malloc(tam*sizeof(long));
                break;
            case 3:
                gettimeofday(&begin, NULL);
                mergeSort(vetor, 0, tam-1);
                gettimeofday(&end, NULL);
                Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
                printf("Tempo de execucao: %.8f\n", Tempo);
                free(vetor);
                vetor = (long*)malloc(tam*sizeof(long));
                break;
            case 4:
                gettimeofday(&begin, NULL);
                radixSort(vetor, tam);
                gettimeofday(&end, NULL);
                Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
                printf("Tempo de execucao: %.8f\n", Tempo);
                free(vetor);
                vetor = (long*)malloc(tam*sizeof(long));
                break;
            case 5:
                gettimeofday(&begin, NULL);
                quickSortHoare(vetor, 0, tam-1);
                gettimeofday(&end, NULL);
                Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
                printf("Tempo de execucao: %.8f\n", Tempo);
                free(vetor);
                vetor = (long*)malloc(tam*sizeof(long));
                break;
            case 6:
                gettimeofday(&begin, NULL);
                quickSortLomuto(vetor, 0, tam-1);
                gettimeofday(&end, NULL);
                Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
                printf("Tempo de execucao: %.8f\n", Tempo);
                free(vetor);
                vetor = (long*)malloc(tam*sizeof(long));
                break;
            case 7:
                gettimeofday(&begin, NULL);
                heapSort(vetor, tam);
                gettimeofday(&end, NULL);
                Tempo = (double)(end.tv_sec - begin.tv_sec) + ((double)(end.tv_usec - begin.tv_usec) / 1000000);
                printf("Tempo de execucao: %.8f\n", Tempo);
                free(vetor);
                vetor = (long*)malloc(tam*sizeof(long));
                break;
            case 10:
                printf("Tamanho do arquivo\n");
                scanf("%d", &tam);
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
                break;
            case 20:
                printf("Escolher arquivo\n");
                printf("1 - Aleatorio\n");
                printf("2 - Invertido\n");
                printf("3 - Ordenado\n");
                scanf("%d", &submenu);
                printf("Escolher tamanho do arquivo\n");
                scanf("%d", &tam);

                switch (submenu)
                {
                case 1:
                    sprintf(nome, "random%d.txt", tam);
                    fileReader(ran, vetor, nome);
                    break;
                case 2:
                    sprintf(nome, "invertido%d.txt", tam);
                    fileReader(inv, vetor, nome);
                    break;
                case 3:
                    sprintf(nome, "ordenado%d.txt", tam);
                    fileReader(ord, vetor, nome);
                    break;
                default:
                    printf("Opcao invalida");
                    break;
                }
                break;
                case 30:
                    vetorOrdenado(vetor, tam);

                    printf("-------------------------------------------------------\n");
                    printf("Tempo de execucao: %.8f\n", Tempo);
                break;
            default:
                printf("Opcao invalida");
                break;
        }
    }

    return 0;
}

