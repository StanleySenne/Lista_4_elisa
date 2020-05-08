#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "com112_file.h"
#include "com112_sort.h"
#include <time.h>

int *lendo_arq(char *nome_arq, int *tam){

    int i = 0;
    FILE *arq;
    arq = fopen(nome_arq, "r");

    if(!arq){
        printf("[erro]: invalido, arquivo nao aberto  %s\n", nome_arq);
        return NULL;
    }  
    if(!fscanf(arq, "%d", tam)){
        printf("[erro]:arquivo nao foi lido %s\n", nome_arq);
        return NULL;
    }
    int *vetor = (int *)calloc(*tam, sizeof(int));
    if(!vetor){
        printf("[erro]: Nao foi possivel criar o vetor na leitura do arquivo %s\n", nome_arq);
        return NULL;
    }
    while(fscanf(arq, " %d", &vetor[i]) != EOF) {
        if(!arq){
        printf("[erro]: Nao foi possivel ler do arquivo %s\n", nome_arq);
        return NULL;
        }
        i++;
    } 
    fclose(arq);
    return vetor;
}

void gravar_arq(char *nome_arq, int *vetor, int tam){

    int i;
    FILE *arq;
    arq = fopen(nome_arq, "w");

    if(!arq){
        printf("[erro]: Nao foi possivel criar o arquivo %s\n", nome_arq);
        return;
    }  
    if(!fprintf(arq, "%d\n", tam)){
        printf("[erro]: Nao foi possivel escrever no arquivo %s\n", nome_arq);
        return;
    }
    for(i = 0; i < tam; i++){
        if(!fprintf(arq, "%d ", vetor[i])){
            printf("[erro]: Nao foi possivel escrever no arquivo %s\n", nome_arq);
            return;
        }
    }
    fclose(arq);
    free(vetor);
}

void gravar_nome(char *nome_arq, int tam){
    FILE *arq;
    arq = fopen(nome_arq, "a");
    fprintf(arq, "Numero de elementos ordenados: %d\n", tam);
    fclose(arq);
}

void gravando_relatorio(int *vet, char *nome_arq, int tam){

    gravar_nome(nome_arq, tam);
    
    int *vet0 = vet, *vet1 = vet, *vet2 = vet;
    int ctrl = 0;
    double *tempo;
    clock_t ticks[2];

    for (int i=0; i <= 3; i++){
        int comp = 0, mov = 0;
        char metodo[15];
        ticks[0] = clock();
        if(i == 0){
            bubbleSort(vet0, tam, &comp, &mov);
            strcpy(metodo, "Bubble Sort");
        }
        else if(i == 1){
            selectionSort(vet1, tam, &comp, &mov);
            strcpy(metodo,"Selection Sort");
        }
        else if(i == 2){
            insertionSort(vet2, tam, &comp, &mov);
            strcpy(metodo, "Insertion Sort");
        }

        ticks[1] = clock();
        *tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
     
        gravando_relatorio_dados(nome_arq, tam, metodo, *tempo, comp, mov);
    }

}

void gravando_relatorio_dados(char *nome_arq, int tam, char *metodo, double tempo, int comp, int mov){
    FILE *arq;
    arq = fopen(nome_arq, "a");

        if(!arq){
        printf("[erro]: Nao foi possivel criar o arquivo %s\n", nome_arq);
        return;
    }
 
    fprintf(arq, "\nMetodo %s\n", metodo);
    fprintf(arq, "\tTempo de execucao: %.3lf\n", tempo);
    fprintf(arq, "\tNumero de comparacoes: %d\n", comp);
    fprintf(arq, "\tNumero de movimentacoes: %d\n", mov);

    fclose(arq);
}
