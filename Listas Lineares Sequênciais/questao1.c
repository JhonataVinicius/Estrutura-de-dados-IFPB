#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void inserir(int elemento);
void inserir_ini(int elemento);
void imprimir();


int main(void) {
	inserir(2);
  inserir(3);
  imprimir();
  inserir_ini(1);
  imprimir();
	
	
  return 0;
}

void inserir(int elemento){
  if (pos < MAX)
	l[pos++] = elemento;
  else {
	printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
  }
}

void inserir_ini(int elemento){
	if (pos < MAX){
		for(int p = pos; p > 0; p--)
			l[p] = l[p-1];
		l[0] = elemento;
		pos++;
	}
	else
		printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
}
void imprimir(){
  for (int i = 0 ; i < pos ; i++)
	printf("%d ",l[i]);
  printf("\n");
}

