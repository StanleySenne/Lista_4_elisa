#include <stdlib.h> 
#include <stdio.h>
#include "com112_file.h"
#include "com112_sort.h"

void bubbleSort(int *vetor, int tam, int *comp, int * mov){

  int i, continua, aux;

  do{
    continua = 0;
    for(i = 0; i < tam-1; i++){

      *comp += 1;
      if(vetor[i] > vetor[i+1]){

        *mov += 1;
        aux = vetor[i];
        vetor[i] = vetor[i+1];
        vetor[i+1] = aux;
        continua = i;
      }
    }
    tam--;
  } while(continua != 0);
}

void selectionSort(int *vetor, int tam, int *comp, int * mov){

  int i, j, menor, troca;

  for(i = 0; i < tam-1; i++){
    menor = i;
    for(j = i+1; j < tam; j++){

      *comp += 1;
      if(vetor[j] < vetor[menor]){
        menor = j;
      }
    }
    if(i != menor){
      *mov += 1;
      troca = vetor[i];
      vetor[i] = vetor[menor];
      vetor[menor] = troca;
    }
  }
}

void insertionSort(int *vetor, int tam, int *comp, int * mov){
    
  int i, j, aux;
    
  for(i = 1; i < tam; i++){
    aux = vetor[i];
    for(j = i; ((j > 0) && (aux < vetor[j-1])); j--){
      *comp += 1;
      *mov += 1;
      vetor[j] = vetor[j-1];
    }
    vetor[j] = aux;
  }
}
