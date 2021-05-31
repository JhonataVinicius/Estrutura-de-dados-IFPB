#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  unsigned col;
  unsigned dado;
  struct sNODE *prox;
};

struct sMATRIZ{
  int lin, col;
  struct sNODE **m;
};

struct sMATRIZ m;

void inicializar(unsigned t_lin, unsigned t_col);

void atribuir(unsigned lin, unsigned col, int dado);
int acessar(unsigned lin, unsigned col);

int tamanho();
void imprimir();
void apagar();

int getMax();
int getMin();
void diagonalP();
void diagonalS();
int count(int valor);

int main(void){
	inicializar(5,5);
	
	atribuir(3,2,6);
	atribuir(1,3,1);
	atribuir(4,4,9);
	atribuir(3,1,5);
	atribuir(0,0,4);
	atribuir(1,2,7);
	atribuir(2,1,9);
	atribuir(0,4,2);
	atribuir(2,2,9);

//	inicializar(2,2);
//	atribuir(0,1,2);
//	atribuir(0,0,9);
//	atribuir(1,0,1);
//	atribuir(1,1,9);
	
	imprimir();
	
	printf("\nMaior elemento da Matriz: %d\n", getMax());
	printf("Menor elemento da Matriz: %d\n", getMin());
	
	diagonalP();
	diagonalS();
	
	printf("\nO valor buscado aparece %d vezes na Matriz!\n", count(9));
}

int getMax(){
	int maior = NULL;
	for (int i = 0 ; i < m.lin ; i++) {
		struct sNODE *aux = m.m[i];
		
		for (int j = 0 ; j < m.col ; j++) {
			if ((aux && j == aux->col) && maior == NULL) {
				maior = aux->dado;
				aux = aux->prox;
			} 
			else if(aux && j == aux->col){
				if(aux->dado > maior) maior = aux->dado;
				aux = aux->prox;
			}
		}
	}
	return maior;
}

int getMin(){
	int menor = NULL;
	for (int i = 0 ; i < m.lin ; i++) {
		struct sNODE *aux = m.m[i];
		
		for (int j = 0 ; j < m.col ; j++) {
			if ((aux && j == aux->col) && menor == NULL) {
				menor = aux->dado;
				aux = aux->prox;
			} 
			else if(aux && j == aux->col){
				if(aux->dado < menor) menor = aux->dado;
				aux = aux->prox;
			}
			else return 0;
		}
	}
	return menor;
}

void diagonalP(){
	printf("\nDiagonal Principal:\n");
	printf("M[\n");
	for (int i = 0 ; i < m.lin ; i++) {
		for (int j = 0 ; j < m.col ; j++) {
			if (i == j) {
				printf("%d",acessar(i,j));
			} 
			else printf("    ");
		}
		printf("\n");
	}
	printf("]\n");
}

void diagonalS(){
	printf("\nDiagonal Secundaria:\n");
	printf("M[\n");
	for (int i = 0 ; i < m.lin ; i++) {
		for (int j = 0 ; j < m.col ; j++) {
			if (i == m.col - 1 - j) {
				printf("%d",acessar(i,j));
			} 
			else printf("    ");
		}
		printf("\n");
	}
	printf("]\n");
}

int count(int valor){
	int cont = 0;
	for (int i = 0 ; i < m.lin ; i++) {
		struct sNODE *aux = m.m[i];
		
		for (int j = 0 ; j < m.col ; j++) {
			if (aux && j == aux->col) {
				if (valor == aux->dado) cont += 1;
				aux = aux->prox;
				}
			} 
		}
	return cont;
}

void inicializar(unsigned t_lin, unsigned t_col){
  m.lin = t_lin;
  m.col = t_col;
  m.m = (struct sNODE **) malloc(sizeof(struct sNODE *) * m.lin);

  for (int i = 0 ; i < m.lin ; i++)
	m.m[i] = NULL;
}

void atribuir(unsigned lin, unsigned col, int dado) {
  if (lin < m.lin && col < m.col) {
	struct sNODE *aux = m.m[lin], *ant = NULL;

	while (aux && col > aux->col) {
  	ant = aux;
  	aux = aux->prox;
	}

	if (aux && aux->col == col){
  	   if (dado == 0) {
    	      if (ant == NULL) m.m[lin] = aux->prox;
    	      else ant->prox = aux->prox;

    	   free(aux);

  	} else aux->dado = dado;

	} else if (dado != 0) {
  	   struct sNODE *novo = (struct sNODE *) malloc(sizeof(struct sNODE));
  	   novo->col = col;
  	   novo->dado = dado;
  	   novo->prox = aux;
  	   if (ant == NULL) m.m[lin] = novo;
  	   else ant->prox = novo;
	}

  } else {
	printf("Não é possível inserir elementos fora da Matriz.\n");
	exit(0);
  }
}

int acessar(unsigned lin, unsigned col) {
  if (lin < m.lin && col < m.col) {
	struct sNODE *aux = m.m[lin];

	while (aux && col > aux->col)
  	   aux = aux->prox;
    
	if (aux && col == aux->col)
  	return aux->dado;
    
	return 0;
  } else {
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
    	      printf("%4d ",aux->dado);
    	      aux = aux->prox;
  	   } else printf("%4d ",0);
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
