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

void enqueue(FILA *fi, int dado);
int dequeue(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){
	FILA fila1;
	criar(&fila1, 10);
	
	FILA fila2;
	criar(&fila2, 5);
	
	enqueue(&fila1, 100);
	enqueue(&fila1, 50);
	enqueue(&fila1, 200);
	
	enqueue(&fila2, 77);
	enqueue(&fila2, 69);
	enqueue(&fila2, 24);
	
	printf("Fila 1:  \n");
	imprimir(&fila1);
	printf("\nFila 2:  \n");
	imprimir(&fila2);
	
	printf("\nTamanho da Fila 1: %d\n", tamanho(&fila1));
	printf("Tamanho da Fila 2: %d\n", tamanho(&fila2));
	
	printf("\nDequeue em Fila1 -> %d\n",dequeue(&fila1));
	printf("Dequeue em Fila2 -> %d\n",dequeue(&fila2));
	
	printf("\nFila 1:  \n");
	imprimir(&fila1);
	printf("\nFila 2:  \n");
	imprimir(&fila2);
	
	printf("\nTamanho da Fila 1: %d\n", tamanho(&fila1));
	printf("Tamanho da Fila 2: %d\n", tamanho(&fila2));
	
	printf("\nApagando Fila 1:  \n");
	apagar(&fila1);
	imprimir(&fila1);
	printf("\nApagando Fila 2:  \n");
	apagar(&fila2);
	imprimir(&fila2);
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

void enqueue(FILA *fi, int dado){
  if ((fi->fim + 1) != fi->ini && !(fi->fim + 1 == fi->MAX && !fi->ini) ){
	fi->arr[fi->fim] = dado;
	//fim = (fim + 1) % MAX;
	fi->fim++;
	if (fi->fim == fi->MAX) fi->fim = 0;
  }
  else
	printf("Não foi possível inserir %d. Fila cheia.\n",dado);
}

int dequeue(FILA *fi){
  if (fi->ini != fi->fim) {
	int dado = fi->arr[fi->ini];
	//ini = (ini + 1) % MAX;
	fi->ini++;
	if (fi->ini == fi->MAX) fi->ini = 0;
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
