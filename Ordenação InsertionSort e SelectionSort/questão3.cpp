#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

void insertionSort(char l[][MAX], int tam){
	char eleito[MAX];
	for (int i = 1 ; i < tam ; i++) {
		strcpy(eleito, l[i]);
		int j = i - 1;
		
		while (j >= 0 && (strcmp(l[j], eleito) > 0)) {
			strcpy(l[j+1], l[j]);	
			j = j - 1;
		}
		strcpy(l[j+1], eleito);
	}
}

int main(void){
	printf("Strings ordenadas em ordem crescente: \n\n");
	char l[][MAX] = {"cba","bac","aab","aac","abc"};
	//char l[][MAX] = {"jose","jhonata","joyce","joaquim","joao"}; 
	int tam = 5;
	
	insertionSort(l, tam);
	
	for (int i = 0 ; i < tam ; i++) printf("%d String: %s \n",i+1,l[i]);
}



