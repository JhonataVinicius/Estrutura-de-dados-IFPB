#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void enqueue(int dado);
int dequeue();
int getFront();

int tamanho();
void imprimir();
void apagar();

int main(void) {
	enqueue(7);
	enqueue(10);
	enqueue(24);
	enqueue(97);
	printf("Fila: \n");
	imprimir();
	printf("\nElemento do inicio da fila: ");
	printf("%d", getFront());
}

int getFront(){
	if (ini){
		int dado = ini->dado;
		return dado;
  	}
	else{
		printf("Não há elementos. Fila vazia.\n");
		exit(1);
	}
}

void enqueue(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
	ini = fim = novo;
  else{
	fim->prox = novo;
	fim = novo;
  }
}

int dequeue(){
  if (ini) {
	int dado = ini->dado;
	struct sNODE *tmp = ini;
    
	if (ini == fim)
  	   ini = fim = NULL;
	else
  	   ini = ini->prox;

	free(tmp);

	return dado;
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

void apagar(){
  struct sNODE *aux = ini, *ant = NULL;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  ini = fim = NULL;
}

int tamanho(){
  struct sNODE *aux = ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(){
  struct sNODE *aux = ini;
 
  printf("F[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}
