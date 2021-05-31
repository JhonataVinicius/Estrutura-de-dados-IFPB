#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  unsigned col;
  char dado[30];
  struct sNODE *prox;
};

struct sMATRIZ{
  int lin, col;
  struct sNODE **m;
};

struct sMATRIZ m;

void inicializar(unsigned t_lin, unsigned t_col);

void atribuir(unsigned lin, unsigned col, char *dado);
char* acessar(unsigned lin, unsigned col);

int tamanho();
void imprimir();
void apagar();

int main(void) {
	
	inicializar(2,2);
	atribuir(0,0,"caio");
	atribuir(0,1,"jhon");
	atribuir(1,1,"dudu");
	atribuir(1,0,"joao");
	
//	inicializar(2,2);
//	atribuir(0,0,"j");
//	atribuir(0,1,"h");
//	atribuir(1,1,"o");
//	atribuir(1,0,"n");
	
//	inicializar(4,4);
//	atribuir(0,3,"o");
//	atribuir(0,2,"h");
//	atribuir(0,1,"j");
//	atribuir(3,3,"v");
//	atribuir(2,2,"a");
//	atribuir(3,1,"a");
//	atribuir(3,0,"t");
//	atribuir(2,0,"n");
//	atribuir(1,1,"o");
//	atribuir(0,0,"j");
	
	imprimir();
	
	printf("\nString contida na posicao buscada: %s\n",acessar(0,1));
	
	printf("\nTamanho total da Matriz: %d\n\n",tamanho());
	
	apagar();
	
	imprimir();
}

void inicializar(unsigned t_lin, unsigned t_col){
	m.lin = t_lin;
	m.col = t_col;
	m.m = (struct sNODE **) malloc(sizeof(struct sNODE *) * m.lin);
	
	for (int i = 0 ; i < m.lin ; i++)
		m.m[i] = NULL;
}

void atribuir(unsigned lin, unsigned col, char *dado) {
	if (lin < m.lin && col < m.col) {
		struct sNODE *aux = m.m[lin], *ant = NULL;
		
		while (aux && col > aux->col) {
			ant = aux;
			aux = aux->prox;
		}
		
		if (aux && aux->col == col){
			if (strcmp(dado, "") == 0) {
				if (ant == NULL) m.m[lin] = aux->prox;
				else ant->prox = aux->prox;
				free(aux);
			
			} 
			else (strcpy(aux->dado, dado));
		
		} 
		else if ((strcmp(dado, "") > 0) || (strcmp(dado, "") < 0)) {
			struct sNODE *novo = (struct sNODE *) malloc(sizeof(struct sNODE));
			novo->col = col;
			(strcpy(novo->dado, dado));
			novo->prox = aux;
			if (ant == NULL) m.m[lin] = novo;
			else ant->prox = novo;
		}
		
	} 
	else {
		printf("Não é possível inserir elementos fora da Matriz.\n");
		exit(0);
	}
}

char* acessar(unsigned lin, unsigned col) {
	if (lin < m.lin && col < m.col) {
		struct sNODE *aux = m.m[lin];
		
		while (aux && col > aux->col)
		aux = aux->prox;
		
		if (aux && col == aux->col)
		return aux->dado;
	} 
	else {
		printf("Não é possível acessar elementos fora da Matriz.\n");
		exit(0);
	}
}

int tamanho() {
	return m.lin * m.col;
}

void imprimir(){
	printf("M[\n");
	for (int i = 0 ; i < m.lin ; i++) {
		struct sNODE *aux = m.m[i];
		
		for (int j = 0 ; j < m.col ; j++) {
			if (aux && j == aux->col) {
				printf("%s ",aux->dado);
				aux = aux->prox;
			} 
			else printf("  ");
		}
		printf("\n");
	}
	printf("]\n");
}

void apagar(){
	for (int i = 0 ; i < m.lin ; i++) {
		struct sNODE *aux = m.m[i], *ant = NULL;
		
		while (aux) {
			ant = aux;
			aux = aux->prox;
			free(ant);
		}
	}
	free(m.m);
}
