#ifndef C0M112_FILE_H
#define	C0M112_FILE_H

int *lendo_arq(char *nome_arq, int *tam);
void gravar_arq(char *nome_arq, int *vetor, int tam);
void gravando_relatorio(int *vetor, char *nome_arq, int tam);
void gravando_relatorio_dados(char *nome_arq, int tam, char *metodo, double tempo, int comp, int mov);
void gravar_nome(char *nome_arq, int tam);
#endif
