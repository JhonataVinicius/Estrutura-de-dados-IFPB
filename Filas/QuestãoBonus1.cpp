#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

typedef struct sFILA FILA;

void criar(FILA *fi);

void inserir_ini(FILA *fi, int dado);
int remover_ini(FILA *fi);	//dequeue

void inserir_fim(FILA *fi, int dado);	//enqueue
int remover_fim(FILA *fi);

void imprimir(FILA *fi);

int main(void){
	FILA fila1;
	criar(&fila1);
	
	inserir_fim(&fila1,2);
	inserir_fim(&fila1,3);
	inserir_fim(&fila1,4);
	printf("Fila inicial:  ");
	imprimir(&fila1);
	
	inserir_ini(&fila1,1);
	printf("Inserindo um novo elemento no inicio da Fila:  ");
	imprimir(&fila1);
	
	inserir_fim(&fila1,5);
	printf("Inserindo um novo elemento no final da Fila:  ");
	imprimir(&fila1);
	
	inserir_ini(&fila1,0);
	printf("Inserindo um novo elemento no inicio da Fila:  ");
	imprimir(&fila1);
	
	inserir_fim(&fila1,6);
	printf("Inserindo um novo elemento no final da Fila:  ");
	imprimir(&fila1);
	
	printf("Removendo o elemento %d do final da Fila:  ",remover_fim(&fila1));
	imprimir(&fila1);
	
	printf("Removendo o elemento %d do inicio da Fila:  ",remover_ini(&fila1));
	imprimir(&fila1);
	
	printf("Removendo o elemento %d do final da Fila:  ",remover_fim(&fila1));
	imprimir(&fila1);
}

void criar(FILA *fi){
	struct sNODE *fila = (struct sNODE*) malloc(sizeof(struct sNODE ));
	fi->ini=NULL;
	fi->fim=NULL;
}

void inserir_ini(FILA *fi, int dado){
	struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
	novo->dado = dado;
	novo->prox = fi->ini;
	
	if (fi->ini == NULL)
		fi->ini = novo;
	else{
		novo->prox = fi->ini;
		fi->ini = novo;	
	}
}

int remover_ini(FILA *fi){
	if (fi->ini){
		int dado = (fi->ini)->dado;
		struct sNODE *tmp = fi->ini;
	
		if (fi->ini == fi->fim)
			fi->ini = fi->fim = NULL;
		else
			fi->ini = (fi->ini)->prox;
	
		free(tmp);
	
		return dado;
	}
	else{
		printf("Não há elementos. Fila vazia.\n");
		exit(1);
	}
}

void inserir_fim(FILA *fi, int dado){
	struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
	novo->dado = dado;
	novo->prox = NULL;
	
	if (!fi->ini)
		fi->ini = fi->fim = novo;
	else{
		(fi->fim)->prox = novo;
		(fi->fim)= novo;
	}
}

int remover_fim(FILA *fi){
	struct sNODE *aux = fi->ini;
	int dado = (fi->fim)->dado;
	if(aux->prox == NULL){
		printf("Não há elementos. Fila vazia.\n");
		exit(1);
	}
	else{
		struct sNODE *final = aux->prox, *antecessor = aux;
	
		while(final->prox != NULL){
			antecessor = final;
			final = final->prox;
		}    
		antecessor->prox = NULL;
		return final->dado;  
	}
 }

void imprimir(FILA *fi){
	struct sNODE *aux = fi->ini;
	
	printf("F[ ");
	while (aux){
		printf("%d ", aux->dado);
		aux = aux->prox;
	}
	printf("]\n\n");
}
