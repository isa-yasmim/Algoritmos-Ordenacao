#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fileGenerator(FILE *ran, int tam){
    char nome[30];

    sprintf(nome, "random%d.txt", tam);
    ran = fopen(nome, "w");
    if (ran == NULL){
        printf("Erro na abertura do arquivo");
        return;
    }
    for(int i = 0; i < tam; i++){
        fprintf(ran, "%d\n", rand() % tam);
    }
    fclose(ran);
    printf("Arquivo gerado com sucesso\n");
}

void invertedFileGenerator(FILE *inv, int tam){
    char nome[30];
    sprintf(nome, "invertido%d.txt", tam);
    inv = fopen(nome, "w");
    if (inv == NULL){
        printf("Erro na abertura do arquivo");
        return;
    }
    for(int i = tam; i > 0; i--){
        fprintf(inv, "%d\n", i);
    }
    fclose(inv);
    printf("Arquivo gerado com sucesso\n");
}

void orderedFileGenerator(FILE *ord, int tam){
    char nome[30];
    sprintf(nome, "ordenado%d.txt", tam);
    ord = fopen(nome, "w");
    if (ord == NULL){
        printf("Erro na abertura do arquivo");
        return;
    }
    for(int i = 0; i < tam; i++){
        fprintf(ord, "%d\n", i);
    }
    fclose(ord);
    printf("Arquivo gerado com sucesso\n");
}

void fileReader(FILE *arq, long vetor[], char nome[]){
    int num = 0, i=0;

    arq = fopen(nome, "r");
    if (arq == NULL){
        printf("Erro na abertura do arquivo");
        return;
    }
    while(fscanf(arq, "%d", &num) != EOF){
        vetor[i] = num;
        i++;
    }
    fclose(arq);
}


//////////////vetor ordenado

void vetorOrdenado(long vetor[], int tam){
    int imprimir = 2;   
    printf("Mostrar vetor ordenado?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    scanf("%d", &imprimir);

    if(imprimir == 1){
        printf("Vetor ordenado:\n");
        for(int i = 0; i < tam; i++){
            printf("%d. %ld\n", i, vetor[i]);
        }
    }
}