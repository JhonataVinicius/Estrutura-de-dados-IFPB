#include <stdio.h>
#include <stdlib.h>

struct sFILA{
  int dado;
  int *arr, ini, fim;
  int MAX;
};

typedef struct sFILA FILA;

void criar(FILA *fi, int tam_MAX);
void apagar(FILA *fi);

void inserir_ini(FILA *fi, int dado);
void inserir_fim(FILA *fi, int dado);

int remover_ini(FILA *fi);
int remover_fim(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){
	FILA fila1;
	criar(&fila1,6);
	
	inserir_fim(&fila1,2);
	inserir_fim(&fila1,3);
	inserir_fim(&fila1,4);
	printf("Fila inicial:  ");
	imprimir(&fila1);
	
	inserir_ini(&fila1,1);
	printf("\nInserindo um novo elemento no inicio da Fila:  ");
	imprimir(&fila1);
	
	printf("\nRemovendo o elemento %d do inicio da Fila:  ",remover_ini(&fila1));
	imprimir(&fila1);
	
	inserir_fim(&fila1,5);
	printf("\nInserindo um novo elemento no final da Fila:  ");
	imprimir(&fila1);
		
	printf("\nRemovendo o elemento %d do final da Fila:  ",remover_fim(&fila1));
	imprimir(&fila1);
	
	inserir_ini(&fila1,1);
	printf("\nInserindo um novo elemento no inicio da Fila:  ");
	imprimir(&fila1);
	
	inserir_fim(&fila1,5);
	printf("\nInserindo um novo elemento no final da Fila:  ");
	imprimir(&fila1);
	
	printf("\nRemovendo o elemento %d do final da Fila:  ",remover_fim(&fila1));
	imprimir(&fila1);
	
	inserir_ini(&fila1,0);
	printf("\nInserindo um novo elemento no inicio da Fila:  ");
	imprimir(&fila1);
}

void criar(FILA *fi, int tam_MAX){
	fi->MAX = tam_MAX;
	fi->ini = 0;
	fi->fim = 0;
	fi->arr = (int*) malloc(sizeof(int)*tam_MAX);
}

void apagar(FILA *fi){
  fi->ini = fi->fim = 0;
}

void inserir_ini(FILA *fi, int dado){
	if ((fi->fim + 1) != fi->ini && !(fi->ini == 0 && (fi->fim == fi->MAX))){
		if (fi->ini == 0) fi->ini = fi->MAX;
		fi->arr[fi->ini-1] = dado;
		fi->ini--;
	}
	else
		printf("Não foi possível inserir %d. Fila cheia.\n",dado);	
}

int remover_ini(FILA *fi){
  if (fi->ini != fi->fim) {
	int dado = fi->arr[fi->ini];
	fi->ini++;
	if (fi->ini == fi->MAX) fi->ini = 0;
		return dado;
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

void inserir_fim(FILA *fi, int dado){
  if ((fi->fim + 1) != fi->ini && !(fi->fim + 1 == fi->MAX && !fi->ini) ){
	fi->arr[fi->fim] = dado;
	fi->fim++;
	if (fi->fim == fi->MAX) fi->fim = 0;
  }
  else
	printf("Não foi possível inserir %d. Fila cheia.\n",dado);
}

int remover_fim(FILA *fi){
	if (fi->ini != fi->fim) {
		int dado = fi->arr[fi->fim-1];
		fi->fim--;
		if (fi->fim == fi->MAX) fi->fim = 0;
			return dado;
	}
	else {
		printf("Não há elementos. Fila vazia.\n");
		exit(1);
	}	
}

int tamanho(FILA *fi){
  if (fi->ini <= fi->fim)
	return fi->fim - fi->ini;
  else
	return fi->MAX - (fi->ini - fi->fim);
}

void imprimir(FILA *fi){
  printf("F[ ");
  for (int i = fi->ini ;  ; i++) {
	if (i == fi->MAX) i = 0;
	if (i == fi->fim) break;
	printf("%d ",fi->arr[i]);
  }
  printf("]\n");
}
