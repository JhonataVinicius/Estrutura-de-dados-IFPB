#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void enqueue(int elemento);
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
	if(pos)
		return l[0];
	else{
		printf("Não há elementos. Pilha vazia.\n");
		exit(1);
	}
}

void enqueue(int elemento){
  if (pos < MAX)
	l[pos++] = elemento;
  else
	printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int dequeue(){
  if (pos) {
	int dado = l[0];
	for (int i = 0 ; i < pos -1 ; i++)
  	l[i] = l[i+1];
	pos--;
	return dado;
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

int tamanho(){
  return pos;
}

void imprimir(){
  printf("F[ ");
  for (int i = 0 ; i < pos ; i++)
	printf("%d ",l[i]);
  printf("]\n");
}

void apagar(){
  pos = 0;
}
