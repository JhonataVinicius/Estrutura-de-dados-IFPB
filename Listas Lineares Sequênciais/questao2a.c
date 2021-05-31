#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void inserir(int elemento);
void imprimir();


int main(void) {
	inserir(2);
	inserir(3);
	inserir(3);

	imprimir();


  return 0;
}


//letra a da questão 2.
void inserir(int elemento){
  if (pos < MAX){
  	for (int i = 0; i < pos; i++){
  		if (l[i] == elemento){
  			printf("Nao foi possivel inserir %d. pois o elemento já se encontra na lista.\n",elemento);
  			return;
  		}
	}
	l[pos++] = elemento;
  }
  else
  	printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
}


void imprimir(){
  for (int i = 0 ; i < pos ; i++)
	printf("%d ",l[i]);
  printf("\n");
}

