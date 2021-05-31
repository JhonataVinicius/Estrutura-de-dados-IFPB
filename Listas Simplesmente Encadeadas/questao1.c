#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

void inserir(int dado);
void inserir_ini(int dado);
void imprimir();


int main(){


  inserir(20);
  inserir(10);
  inserir(36);
  printf("INSERINDO NO FINAL:\n");
  imprimir();

  inserir_ini(5);
  inserir_ini(13);
  printf("INSERINDO 5 E 13 NO INICIO:\n");
  imprimir();
  return 0;
}


struct sNODE *ini = NULL, *fim = NULL;


void inserir(int dado){
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

void inserir_ini(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (ini == NULL)
	  ini = novo;
  else{
	  novo->prox = ini;
	  ini = novo;
  }
  }

void imprimir(){
  struct sNODE *aux = ini;
 
  printf("[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n\n");
}

