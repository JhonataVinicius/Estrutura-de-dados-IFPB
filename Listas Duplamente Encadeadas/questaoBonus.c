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
struct sNODE* encontra_ocupacao(LISTA *lst, char* ocupacao);

int main(){
  LISTA lst;
  inicializar(&lst);
  
  inserir_ord(&lst,"JOSÉ", "Supervisor",988.50);
  inserir_ord(&lst,"ANTONIO","Peão",750.00);
  inserir_ord(&lst, "ANA","Gerente", 1000.00);
  inserir_ord(&lst, "ÁQUILA","Gerente", 1500.00);
  inserir_ord(&lst,"MATEUS", "Supervisor",890.50);
  inserir_ord(&lst,"MARIA","Peão",1780.00);
 

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
  struct sNODE *aux , *ant = NULL;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
  strcpy(novo->nome,nome);
  strcpy(novo->ocupacao,ocupacao);
  novo->salario = salario;
  novo->ant = NULL;
  novo->prox = NULL;
  
  if (!lst->ini){
    lst->ini = lst->fim = novo;
  }else{
    if (strcmp(novo->ocupacao, "Gerente") == 0){
      aux = lst->ini;
    }else{
      aux = encontra_ocupacao(lst,ocupacao);
        if (aux == NULL){
          if(strcmp(novo->ocupacao, "Supervisor") == 0){
            aux = encontra_ocupacao(lst, "Peão");
          }
        }
    }

	while(aux && aux->salario > novo->salario  && (strcmp(aux->ocupacao, ocupacao) == 0)){
	  aux = aux->prox;
  }   
  if(aux != NULL){
    if (aux == lst->ini){
      lst->ini = novo;
    }else{
      aux->ant->prox = novo;
      novo->ant = aux->ant; 
    }novo->prox = aux;
    aux->ant = novo;
  }else if(aux == NULL){   
    lst->fim->prox = novo;
    novo->ant = lst->fim;
    lst->fim = novo;
  }
}}

struct sNODE* encontra_ocupacao(LISTA *lst, char* ocupacao){
  struct sNODE *aux = lst->ini;
  while(aux){
    if (strcmp(aux->ocupacao, ocupacao) == 0){
      return aux;
    }else{
	  aux = aux->prox;
    }
  } return NULL;
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
