#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sNODE{
  char nome[30];
  float nota1;
  float nota2;
  float media;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);
void inserir_ord(LISTA *lst, char *nome, float nota1, float nota2);
void imprimir(LISTA *lst);
void apagar(LISTA *lst);

int main(){
  LISTA lst;
  inicializar(&lst);
  
  inserir_ord(&lst, "Ana", 7.8, 10.0);
  inserir_ord(&lst,"Mateus", 6.0, 8.0);
  inserir_ord(&lst,"Cauã", 8.7,5.2);
  inserir_ord(&lst,"Severino",9.0,8.0);
  inserir_ord(&lst,"Cláudia",6.2,5.9);
  inserir_ord(&lst,"Bruna",9.0,8.2);
  printf("\nMÉDIA DOS ALUNOS EM ORDEM DECRESCENTE:\n\n");
  imprimir(&lst);
  apagar(&lst);
  return 0;
}


void inicializar(LISTA *lst){
	lst->ini=NULL;
	lst->fim=NULL;
}

void inserir_ord(LISTA *lst, char *nome, float nota1, float nota2){
  struct sNODE *aux = lst->ini, *ant = NULL;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
  strcpy(novo->nome,nome);
  novo->nota1 = nota1;
  novo->nota2 = nota2;
  novo->media = ((novo->nota1) + (novo->nota2))/2;
  novo->prox = NULL;

  while(aux && novo->media <= aux->media){
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

void imprimir(LISTA *lst){
  struct sNODE *aux = lst->ini;
 
 // printf(" ");
  while (aux){
    
    printf("- %s: ", aux->nome);
	  printf(" %.2f\n", aux->media);
	  aux = aux->prox;
  }
  //printf("\n\n");
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
