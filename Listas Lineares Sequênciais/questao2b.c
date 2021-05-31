#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void inserir(int elemento);
void remover(int elemento);
int buscar(int elemento);
void imprimir();


int main(void) {
	inserir(2);
	inserir(3);
	inserir(3);
	inserir(3);
	imprimir();
	remover(3);
	imprimir();
  return 0;
}


//funçao inserir adaptada para testar a letra b da questão 2.
void inserir(int elemento){
  if (pos < MAX){
    l[pos++] = elemento;
  //	for (int i = 0; i < pos; i++){
  //		if (l[i] == elemento){
  //			printf("Nao foi possivel inserir %d. O elemento ja se encontra na lista.\n",elemento);
  //			return;
  		}
//	}
	//l[pos++] = elemento;
 // }
  else
  	printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
}

int buscar(int elemento){
  for (int i = 0 ; i < pos ; i++){
	if (l[i] == elemento)
  		return i;
  }
  return -1;
}
//remover todas as ocorrencias
void remover(int elemento){
	while(1){
		int p = buscar(elemento);
		if (p == -1)
		return;
		for (int i = p ; i < pos -1; i++)
			l[i] = l[i+1];
  		pos--;
	}
}


void imprimir(){
  for (int i = 0 ; i < pos ; i++)
	printf("%d ",l[i]);
  printf("\n");
}

