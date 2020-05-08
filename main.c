#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "com112_file.h"
#include "com112_sort.h"

#define TAM 10;
#define ARQ_ENTRADA "com112_entrada.txt"
#define ARQ_SAIDA "com112_saida.txt"
#define ARQ_RELATORIO "com112_relatorio.txt"


int *cria_vetor(int tam){
  
  int i;
  int *vet = (int *)calloc(tam, sizeof(int));

  if(!vet){
    printf("[erro]: Nao foi possivel criar o vetor de numeros aleatorios.\n");
    return NULL;
  }

  for(i = 0; i < tam; i++){
    vet[i] = rand() % 10;
  }

  return vet;
}

int menu(int *vet, int tam, double *tempo, int *comp, int *mov){

  int ctrl, i;
  clock_t ticks[2];

  do{
    printf("Escolha a opcao que voce deseja ordenar:\n1. BubbleSort\n2. Selection Sort\n3. Insertion Sort\nOpcao: ");
    scanf("%d", &i);

    ctrl = 0;
    ticks[0] = clock();

    switch(i){
      case 1:
        bubbleSort(vet, tam, comp, mov);
        break;
      case 2:
        selectionSort(vet, tam, comp, mov);
        break;
      case 3 :
        insertionSort(vet, tam, comp, mov);
        break;
      default:
        printf("Opcao invalida!\n\n");
        ctrl = 1;
    }

    ticks[1] = clock();
    *tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

  } while(ctrl != 0);

  return i;
}

void relatorio(int i, double tempo, int comp, int mov, char *realt, int tam){

  char metodo[15];
  if(i == 1){
    strcpy(metodo, "Bubble Sort");
  }else if(i == 2){
    strcpy(metodo, "Selection Sort");
  } else if(i==3) {
    strcpy(metodo, "Insertion Sort");
  }
    
  printf("\nEstatisticas de desempenho do metodo %s:\n", metodo);
  printf("1. Tempo de execucao: %.3lf\n", tempo);
  printf("2. Numero de comparacoes entre elementos do vetor: %d\n", comp);
  printf("3. Numero de movimentações entre elementos do vetor: %d\n", mov);

}

int main(){

  int *vet, *vetaux, i, comp = 0, mov = 0, tam = TAM;
  double tempo;
  char *entrada = ARQ_ENTRADA;
  char *saida = ARQ_SAIDA;
  char *relat = ARQ_RELATORIO;

  vet = cria_vetor(tam);
  vetaux = vet;
  gravar_arq(entrada, vet, tam);

  vet = ler_arq(entrada, &tam);

  i = menu(vet, tam, &tempo, &comp, &mov);

  gravar_arq(saida, vet, tam);

  relatorio(i, tempo, comp, mov, relat, tam);

  gravar_relatorio(vetaux, relat, tam);

  return 0;

}
