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
void remover(LISTA *lst, int dado);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);
void apagar(LISTA *lst);
//struct sNODE *buscar(LISTA *lst, int dado);
//int obter(struct sNODE *node);

int main(){
  LISTA lst1;
  inicializar(&lst1);

  inserir_ord(&lst1, 20);
  inserir_ord(&lst1, 10);
  inserir_ord(&lst1, 36);
  inserir_ord(&lst1, 5);
  inserir_ord(&lst1, 13);
  printf("LISTA 1:\n");
  imprimir(&lst1);
  printf("TAMANHO DA LISTA 1: %d\n\n",tamanho(&lst1));
  remover(&lst1,10);
  printf("REMOVENDO O INTEIRO 10 DA LISTA 1:\n");
  imprimir(&lst1);
  printf("TAMANHO DA LISTA 1: %d\n\n",tamanho(&lst1));
  
  remover(&lst1,36);
  printf("REMOVENDO O INTEIRO 36 DA LISTA 1:\n");
  imprimir(&lst1);
  printf("TAMANHO DA LISTA 1: %d\n\n",tamanho(&lst1));

  printf("\n\n");

  
  LISTA lst2;
  inicializar(&lst2);
  inserir_ord(&lst2, 40);
  inserir_ord(&lst2, 26);
  inserir_ord(&lst2, 17);
  inserir_ord(&lst2, 78);
  inserir_ord(&lst2, 16);
  printf("LISTA 2:\n");
  imprimir(&lst2);
  printf("TAMANHO DA LISTA 2: %d\n\n",tamanho(&lst2));
  remover(&lst2,40);
  printf("REMOVENDO O INTEIRO 40 DA LISTA 2:\n");
  imprimir(&lst2);
  printf("TAMANHO DA LISTA 2: %d\n\n",tamanho(&lst2));
 
  remover(&lst2,78);
  printf("REMOVENDO O INTEIRO 78 DA LISTA 2:\n");
  imprimir(&lst2);
	printf("TAMANHO DA LISTA 2: %d\n\n",tamanho(&lst2));


  apagar(&lst1);
  printf("TAMANHO DA LISTA 1 APÓS APAGAR: %d\n\n",tamanho(&lst1));
  apagar(&lst2);
  printf("TAMANHO DA LISTA 2 APÓS APAGAR: %d\n\n",tamanho(&lst2));
  return 0;
}


void inicializar(LISTA *lst){
	lst->ini=NULL;
	lst->fim=NULL;
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
  } 
  else if (!aux){
	  (lst->fim)->prox = novo;
	  lst->fim = novo;
  } 
  else {
	  ant->prox = novo;
	  novo->prox = aux;
  }
}

void remover(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini, *ant = NULL;

  while (aux){
	if (dado == aux->dado){
  	    if (aux == lst->ini)
    	        lst->ini = (lst->ini)->prox;
  	    else if(aux == lst->fim){
    	        ant->prox = NULL;
    	        lst->fim = ant;
  	    } else
    	        ant->prox = aux->prox;
 	 
  	    free(aux);
  	    return;
	}    
	ant = aux;
	aux = aux->prox;
  }
}

struct sNODE *buscar(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini;

  while (aux){
	if (dado == aux->dado)
  	    return aux;
	aux = aux->prox;
  }

  return NULL;
}

int obter(struct sNODE *node){
  if (!node){
	  printf("Erro ao obter dado. Ponteiro invalido.");
	  exit(0);
  }
 
  return node->dado;
}

int tamanho(LISTA *lst){
  struct sNODE *aux = lst->ini;
  int tam = 0; 
  while (aux){
	  tam++;
	  aux = aux->prox;
  } 
  return tam;
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
