#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int particao(int l[], int ini, int fim) {
	int pivo = l[(ini+fim)/2];
	int i = ini-1, j = fim+1;
	
	while ( i < j ) {
		while (l[--j] < pivo);
		while (l[++i] > pivo);
		if (i < j) troca(&l[i],&l[j]);
	}
	
	return j;
}

void quickSort(int l[], int ini, int fim){
	if (ini < fim){
		int p = particao(l,ini,fim);
		quickSort(l,ini,p);
		quickSort(l,p+1,fim);
	}
}

int main(void){
	int l[10] = {9,7,6,8,3,5,4,1,2,0};
	//int l[10] = {9,6,3,8,5,2,0,7,4,1};
	quickSort(l, 0, 9);
	
	for (int i = 0 ; i <= 9 ; i++) printf("%d ",l[i]);
}
