#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], ini = 0, fim = 0;

void enqueue(int elemento);
int dequeue();

int getFront();
int elementoNaFila(int elemento);
int indiceNaFila(int elemento);

int tamanho();
void imprimir();
void apagar();

int main(void) {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	imprimir();
	
	printf("\nElemento do inicio da fila --> %d\n", getFront());
	
	printf("\nO indice contem elemento? --> %d\n", indiceNaFila(0));
	printf("O indice contem elemento? --> %d\n\n", indiceNaFila(4));
		
	printf("O elemento esta presente na fila? --> %d\n", elementoNaFila(1));
	printf("O elemento esta presente na fila? --> %d\n\n", elementoNaFila(0));
	
	dequeue();
	imprimir();
	
	printf("\nElemento do inicio da fila --> %d\n", getFront());
	
	printf("\nO indice contem elemento? --> %d\n", indiceNaFila(0));
	
	printf("\nO elemento esta presente na fila? --> %d\n", elementoNaFila(1));
}

int getFront(){
	if (ini != fim) {
		int dado = l[ini];
		return dado;
	}
	else {
		printf("Não há elementos. Fila vazia.\n");
		exit(1);
	}	
}

int elementoNaFila(int elemento){
	if (ini != fim) {
		for (int i = ini ; i < fim; i++) {
			if (l[i] == elemento){
				return 1;
			}
		}
		return 0;
	}
	else {
		printf("Não há elementos. Fila vazia.\n");
		exit(1);
	}
}

int indiceNaFila(int elemento){
	if (ini != fim) {
		for (int i = ini ; i < fim; i++) {
			if (i == elemento){
				return 1;
			}
		}
		return 0;
	}
	else {
		printf("Não há elementos. Fila vazia.\n");
		exit(1);
	}
}

void enqueue(int elemento){
  if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
	l[fim] = elemento;
	//fim = (fim + 1) % MAX;
	fim++;
	if (fim == MAX) fim = 0;
  }
  else
	printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int dequeue(){
  if (ini != fim) {
	int dado = l[ini];
	//ini = (ini + 1) % MAX;
	ini++;
	if (ini == MAX) ini = 0;
	return dado;
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

int tamanho(){
  if (ini <= fim)
	return fim - ini;
  else
	return MAX - (ini - fim);
}

void imprimir(){
  printf("F[ ");
  for (int i = ini ;  ; i++) {
	if (i == MAX) i = 0;
	if (i == fim) break;
	printf("%d ",l[i]);
  }
  printf("]\n");
}

void apagar(){
  ini = fim = 0;
}
