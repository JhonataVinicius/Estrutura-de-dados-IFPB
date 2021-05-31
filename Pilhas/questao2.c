#include <stdio.h>
#include <stdlib.h>

struct sPILHA{
  int pos, *arr;
  int MAX;
  
};
typedef struct sPILHA PILHA;

void criar(PILHA *pi, int tam_MAX);
void apagar(PILHA *pi);
void push(PILHA *pi, int dado);
int pop(PILHA *pi);
int tamanho(PILHA *pi);
int imprimir();


int main(void){
  PILHA p1;
  criar(&p1,10);

	push(&p1,25);
	push(&p1,75);
	push(&p1,17);
	push(&p1,99);
  push(&p1,12);
	push(&p1,26);
	push(&p1,85);
	push(&p1,69);
	imprimir();
  pop(&p1);
  imprimir();
  apagar(&p1);
}


void criar(PILHA *pi, int tam_MAX){
  pi->arr = (int*)malloc(sizeof(int)*tam_MAX);
	pi->pos = 0;
 	pi->MAX = tam_MAX;		
  }	

void apagar(PILHA *pi){
	pi->pos = 0;
  pi->MAX = 0;
  free(pi->arr);}

void push(PILHA *pi, int dado){
	if (pi->pos < pi->MAX){
		pi->arr[pi->pos] = dado;
    pi->pos++;
     
  }else
		printf("Não foi possível inserir %d. Pilha cheia.\n",dado);
}

int pop(PILHA *pi){
	if (pi->pos)
    return pi->arr[--pi->pos];
  else {
		printf("Não há elementos. Pilha vazia.\n");
	  exit(1);
  }return 0;}

int tamanho(PILHA *pi){
	return pi->pos;	}
	
int imprimir(PILHA *pi){
  printf("P[ ");
  for (int i = pi->pos -1 ; i >= 0 ; i--)
	printf("%d ",pi->arr[i]);
  printf("]\n");
return 0;}


