#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void selectionSort(int l[], int tam){
	for(int i=0; i<tam; i++){
		int im = i;
		for(int j = i+1; j<tam; j++){
			if(l[im] < l[j])
			im = j;
		}
		troca(&l[i],&l[im]);
	}
}

int main(void) {
	int l[] = {1,2,3,4,5}, tam = 5;
	//int l[] = {3,2,5,1,4}, tam = 5;
	
	selectionSort(l, tam);
	
	printf("Array ordenado de forma decrescente: \n");
	for (int i = 0 ; i < tam ; i++) printf("%d ",l[i]);
}



