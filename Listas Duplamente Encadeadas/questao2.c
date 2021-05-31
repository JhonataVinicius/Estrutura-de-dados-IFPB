#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sNODE{
  char nome[30];
  char ocupacao[30];
  float salario;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);
void inserir_ord(LISTA *lst, char *nome,char *ocupacao, float salario);
void imprimir(LISTA *lst);
void apagar(LISTA *lst);

int main(){
  LISTA lst;
  inicializar(&lst);
  
  inserir_ord(&lst, "ANA","GERENTE", 1000.00);
  inserir_ord(&lst,"JOSÉ", "SUPERVISOR",988.50);
  inserir_ord(&lst,"ANTONIO","PEÃO",780.00);
  inserir_ord(&lst,"PEDRO","CHEFE",2500.00);

  printf("\nSALÁRIO DOS FUNCIONARIOS EM ORDEM DECRESCENTE:\n\n");
  printf(" NOME  OCUPAÇÃO SALÁRIO\n\n");
  imprimir(&lst);

  apagar(&lst);
  return 0;
}


void inicializar(LISTA *lst){
	lst->ini=NULL;
	lst->fim=NULL;
}

void inserir_ord(LISTA *lst, char *nome,char *ocupacao, float salario){
  struct sNODE *aux = lst->ini, *ant = NULL;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
  strcpy(novo->nome,nome);
  strcpy(novo->ocupacao,ocupacao);
  novo->salario = salario;
  novo->ant = NULL;
  novo->prox = NULL;

  while(aux && novo->salario <= aux->salario){
	  ant = aux;
	  aux = aux->prox;
  }
  if (!lst->ini)
	  lst->ini = lst->fim = novo;
  else if (aux == lst->ini){
	  novo->prox = lst->ini;
	  lst->ini->ant = novo;
	  lst->ini = novo;
  } else if (!aux){
	   lst->fim->prox = novo;
	  novo->ant = lst->fim;
	lst->fim = novo;
  } else {
	  aux->ant->prox = novo;
	  novo->ant = aux->ant;
	  novo->prox = aux;
	  aux->ant = novo;
  }
}


void imprimir(LISTA *lst){
  struct sNODE *aux = lst->ini;
 
 // printf(" ");
  while (aux){
    
    printf(" %s ", aux->nome);
    printf("  %s ", aux->ocupacao);
	  printf(" %.2f\n", aux->salario);
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
