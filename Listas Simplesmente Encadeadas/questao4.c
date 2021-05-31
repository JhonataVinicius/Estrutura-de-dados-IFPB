#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};
typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);
void inserir_ord(LISTA *lst, int dado);
void imprimir(LISTA *lst);
void apagar(LISTA *lst);

LISTA juntar_ord(LISTA *lst1, LISTA *lst2);

int main(){
  LISTA lst1;
  inicializar(&lst1);

  inserir_ord(&lst1, 70);
  inserir_ord(&lst1, 2);
  inserir_ord(&lst1, 35);
  inserir_ord(&lst1, 12);
  printf("LISTA 1:\n");
  imprimir(&lst1);
  
  
  LISTA lst2;
  inicializar(&lst2);
  inserir_ord(&lst2, 65);
  inserir_ord(&lst2, 10);
  inserir_ord(&lst2, 7);
  inserir_ord(&lst2, 12);
  printf("LISTA 2:\n");
  imprimir(&lst2);
  
  
  LISTA nova_lst = juntar_ord(&lst1, &lst2);
  printf("LISTA 3 ORDENADA:\n");
  imprimir(&nova_lst);
  
  apagar(&nova_lst);

  return 0;
}

void inicializar(LISTA *lst){
	lst->ini=NULL;
	lst->fim=NULL;
}

LISTA juntar_ord(LISTA *lst1, LISTA *lst2){
  struct sNODE *aux1 = lst1->ini;
  struct sNODE *aux2 = lst2->ini;
  struct sLISTA *lst_temp = (struct sLISTA*) malloc(sizeof(struct sLISTA ));
  inicializar(lst_temp);

  while(aux1 != NULL){
    inserir_ord(lst_temp, aux1->dado);
	  aux1 = aux1->prox;

  }
  while(aux2 != NULL){
	  inserir_ord(lst_temp, aux2->dado);
    aux2 = aux2->prox;
  }
  return *lst_temp;
}

void inserir_ord(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini, *ant = NULL;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
  novo->dado = dado;
  novo->prox = NULL;

  while(aux && dado > aux->dado){
	ant = aux;
	aux = aux->prox;
  }

  if (!lst->ini)
	lst->ini = lst->fim = novo;
  else if (aux == lst->ini){
	novo->prox = lst->ini;
	lst->ini = novo;
  } else if (!aux){
	(lst->fim)->prox = novo;
	lst->fim = novo;
  } else {
	ant->prox = novo;
	novo->prox = aux;
  }
}

void imprimir(LISTA *lst){
  struct sNODE *aux = lst->ini;
  printf("[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n\n");
}

void apagar(LISTA *lst){
  struct sNODE *aux = lst->ini, *ant;
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  lst->ini = lst->fim = NULL;
}
