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
void inserir(LISTA *lst, int dado);
void imprimir(LISTA *lst);

void bubbleSort(LISTA *lst);

int main(void){
	LISTA lst;
	inicializar(&lst);
	
	//pior caso
	inserir(&lst, 5);
	inserir(&lst, 4);
	inserir(&lst, 3);
	inserir(&lst, 2);
	inserir(&lst, 1);
	inserir(&lst, 0);
	printf("Lista Inicial:\n");
	imprimir(&lst);
	
	bubbleSort(&lst);
	printf("Lista apos ordenacao:\n");
	imprimir(&lst);
	
	inserir(&lst, 10);
	inserir(&lst, 9);
	inserir(&lst, 8);
	inserir(&lst, 7);
	inserir(&lst, 6);
	printf("Inserindo mais elementos na lista:\n");
	imprimir(&lst);
	
	bubbleSort(&lst);
	printf("Lista apos ordenacao:\n");
	imprimir(&lst);
}

void inicializar(LISTA *lst){
	lst->ini=NULL;
	lst->fim=NULL;
}

void inserir(LISTA *lst, int dado){
	struct sNODE *aux = lst->ini, *ant = NULL;
	struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
	novo->dado = dado;
	novo->prox = NULL;
	
	while(aux && dado > aux->dado){
		ant = aux;
		aux = aux->prox;
	}
	
	if (!lst->ini){
		lst->ini = lst->fim = novo;
	}
	else{
		(lst->fim)->prox = novo;
		lst->fim = novo;
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

void bubbleSort(LISTA *lst){
	struct sNODE *aux = lst->ini;
	struct sNODE *temp, *inicio = aux;
	unsigned char troca = 1;
	while(troca){
		troca = 0;
		aux = inicio;
		while(aux->prox){
			temp = aux->prox;
			if(aux->dado > temp->dado){
				int num = temp->dado;
				temp->dado = aux->dado;
				aux->dado = num;
				troca = 1;
			}
			aux = aux->prox;
		}
	}
}
