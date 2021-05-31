#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *esq, *dir;
};

struct sNODE *raiz = NULL;

struct sNODE *inserir(struct sNODE *no, int dado);
struct sNODE *remover(struct sNODE *no, int dado);

void emOrdem(struct sNODE *no);
void preOrdem(struct sNODE *no);
void posOrdem(struct sNODE *no);

struct sNODE *buscar(struct sNODE *no, int dado);
int obter(struct sNODE *no);

struct sNODE *apagar(struct sNODE *no);

int getMax(struct sNODE *no);											//Letra - A
int getMin (struct sNODE *no);											//Letra - B
void mostrarFolhas (struct sNODE *no);									//Letra - C
void Auxiliar(struct sNODE *no, int *dist, int dado, bool *achou);		//Auxiliar - Letra - D
int distanciaDaRaiz (struct sNODE *no, int dado);						//Letra - D
int alturaArvore (struct sNODE *no);									//Letra - E
/*void distanciaEntre(struct sNODE *no, int dado1,int dado2);			//Letra - F    */


int main(void){
	raiz = inserir(raiz, 7);
	inserir(raiz, 3);
	inserir(raiz, 9);
	inserir(raiz, 1);
	inserir(raiz, 5);
	inserir(raiz, 4);

	printf("Maior elemento da Arvore: %d\n",getMax(raiz));
	printf("Menor elemento da Arvore: %d\n",getMin(raiz));
	
	printf("Elementos folhas da Arvore:	");
	mostrarFolhas(raiz);
	
	printf("\nAltura da Arvore: %d\n", alturaArvore(raiz));
	
	printf("Distancia (em numero de saltos) da raiz ate o elemento passado: %d\n\n",distanciaDaRaiz(raiz,4));
	
	printf("Removendo o maior elemento 9\n");
	remover(raiz,9);
	printf("Removendo o menor elemento 1\n\n");
	remover(raiz,1);
	
	printf("Maior elemento da Arvore: %d\n",getMax(raiz));
	printf("Menor elemento da Arvore: %d\n",getMin(raiz));
	
	printf("Elementos folhas da Arvore:	");
	mostrarFolhas(raiz);
	
	printf("\n\nRemovendo o elemento 4 \n\n");
	remover(raiz,4);
	
	printf("Altura da Arvore: %d\n", alturaArvore(raiz));
	
	printf("Distancia (em numero de saltos) da raiz ate o elemento passado: %d\n",distanciaDaRaiz(raiz,5));
}

int getMax (struct sNODE *no){
	if (no){
		if (no->dir !=NULL) return getMax(no->dir);
		else return no->dado;
	}
	else{
		printf("Arvore vazia. Nenhum dado maximo a ser retornado!");
		exit(0);
	}
}

int getMin (struct sNODE *no){
	if (no){
		if (no->esq !=NULL) return getMin(no->esq);
		else return no->dado;
	}
	else{
		printf("Arvore vazia. Nenhum dado minimo a ser retornado!");
		exit(0);
	}	
}

void mostrarFolhas(struct sNODE *no){
	if (no){
		if(no->esq == NULL && no->dir == NULL){
			printf("%d\t", no->dado);
			return;
		}
		mostrarFolhas(no->esq);
		mostrarFolhas(no->dir);
	}
	else return;
}

int alturaArvore (struct sNODE *no){   
	if (!no) 
		return -1; 
	else {
		int h_esq = alturaArvore(no->esq);
		int h_dir = alturaArvore(no->dir);
		if (h_esq < h_dir) return h_dir+1;
		else return h_esq+1;
	}
}

int distanciaDaRaiz (struct sNODE *no, int dado){
	int cont = 0;
	bool flag = false;
	Auxiliar(no, &cont,dado,&flag);
	return cont-1;
}

void Auxiliar(struct sNODE *no, int *cont, int dado, bool *flag){
	if (no != NULL){
		(*cont)++;
		if(no->dado == dado){
			*flag = true;
			return;
		}
		Auxiliar(no->esq, cont, dado, flag);
		if (!*flag){
			Auxiliar(no->dir, cont, dado, flag);
			if(!*flag)
				(*cont)--;
		}    
	}
	return;
}

struct sNODE *inserir(struct sNODE *no, int dado){
  if (!no) {
	no = (struct sNODE*) malloc(sizeof(struct sNODE));
	no->dado = dado;
	no->esq = no->dir = NULL;
  } else if (dado < no->dado)
	no->esq = inserir(no->esq,dado);
  else
	no->dir = inserir(no->dir,dado);

  return no;  
}

struct sNODE *remover(struct sNODE *no, int dado){
  struct sNODE *aux = NULL, *aux2 = NULL;

  if (no) {
	if (no->dado == dado) {
  	   if (no->esq == no->dir) {
    	      free(no);
    	      return NULL;
  	   }
  	   else if (!no->esq) {
    	      aux = no->dir;
    	      free(no);
    	      return aux;
  	   }
  	   else if (!no->dir) {
    	      aux = no->esq;
    	      free(no);
    	      return aux;
  	   } else {
    	      aux = aux2 = no->dir;
    	      while (aux->esq)
      	   aux = aux->esq;
    	      aux->esq = no->esq;
    	      free(no);
    	      return aux2;
  	   }
	}
	else {
  	   if (dado < no->dado)
    	      no->esq = remover(no->esq, dado);
  	   else
    	      no->dir = remover(no->dir, dado);
	}
  }
  return no;
}

void emOrdem(struct sNODE *no){
  if (no) {
	emOrdem(no->esq);
	printf("%d ",no->dado);
	emOrdem(no->dir);
  }
}

void preOrdem(struct sNODE *no){
  if (no) {
	printf("%d ",no->dado);
	preOrdem(no->esq);
	preOrdem(no->dir);
  }
}

void posOrdem(struct sNODE *no){
  if (no) {
	posOrdem(no->esq);
	posOrdem(no->dir);
	printf("%d ",no->dado);
  }
}

struct sNODE *buscar( struct sNODE *no, int dado){
  if (no) {
	if (no->dado == dado)
  	   return no;
	else if (dado < no->dado)
  	   return buscar(no->esq, dado);
	else
  	   return buscar(no->dir, dado);
  }
 
  return NULL;
}

int obter(struct sNODE *no) {
  if (no)
	return no->dado;
  else {
	printf("Nenhum dado para retornar.");
	exit(0);
  }
}

struct sNODE *apagar(struct sNODE *no){
  if (no) {
	no->esq = apagar(no->esq);
	no->dir = apagar(no->dir);
	free(no);
  }
  return NULL;
}
