#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int buscaBin(char l[][MAX], int tam, const char *str);
void bubbleSort(char l[][MAX], int tam);

int main(){
	char l[][MAX] = {"acb","aca","abc","aab","aaa","aba"};
	//char l[][MAX] = {"joao","jose","jhonata","joyce","josefa","janaina"}; 
	int tam = 6;
	
	bubbleSort(l, tam);
	
	printf("Array ordenado: ");
	
	for (int i = 0 ; i < tam ; i++) printf("%s ",l[i]);
	
	printf("\n\n");
	
	printf("Achei aca na posicao %d \n",buscaBin(l, tam, "aca"));
	printf("Achei abc na posicao %d \n",buscaBin(l, tam, "abc"));
	
	//printf("Achei jhonata na posicao %d \n",buscaBin(l, tam, "jhonata"));
	//printf("Achei joyce na posicao %d \n",buscaBin(l, tam, "joyce"));
}

int buscaBin(char l[][MAX], int tam, const char *str){
	int ini = 0, fim = tam -1;
	int meio = (ini + fim) / 2;
	
	while (ini <= fim){
		if (strcmp(l[meio], str) == 0)
			return meio;
		else{
			if (strcmp(str, l[meio]) < 0)
				fim = meio - 1;
			else
				ini = meio + 1;
			meio = (ini + fim) / 2;
		}
	}
	return -1;
}

void bubbleSort(char l[][MAX], int tam){
	int trocou = 1;
	char t[MAX];
	for (int i = 0 ; i < tam && trocou; i++) {
		trocou = 0;
		for (int j = 0 ; j < tam - 1 - i; j++)
			if (strcmp(l[j], l[j+1]) > 0) {
				strcpy(t, l[j]); 
				strcpy(l[j], l[j+1]); 
				strcpy(l[j+1], t);
				trocou = 1;
			}
	}
}
