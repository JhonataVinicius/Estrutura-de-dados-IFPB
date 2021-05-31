#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

void bubbleSort(char l[][MAX], int tam);

int main(void) {
	//char l[][MAX] = {"joao","jose","jhonata","joyce","josefa"}; 
	char l[][MAX] = {"acb","aca","abc","aab","aaa"};
	int tam = 5;
	
	bubbleSort(l, tam);
	
	for (int i = 0 ; i < tam ; i++)
		printf("%s ",l[i]);
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
