#include <stdio.h>
#include <stdlib.h>

int buscaBin(int l[], int ini, int fim, int num);

int main(void){
	int l[] = {1,3,5,7,9,11}, tam = 6, ini = 0, fim = tam -1;
	
	printf("Achei 1 na posicao %d \n",buscaBin(l,ini, fim, 1));
	printf("Achei 3 na posicao %d \n",buscaBin(l,ini, fim, 3));
	printf("Achei 5 na posicao %d \n",buscaBin(l,ini, fim, 5));
	printf("Achei 7 na posicao %d \n",buscaBin(l,ini, fim, 7));
	printf("Achei 9 na posicao %d \n",buscaBin(l,ini, fim, 9));
	printf("Achei 11 na posicao %d \n",buscaBin(l,ini, fim, 11));
	printf("Achei 12 na posicao %d \n",buscaBin(l,ini, fim, 12));
}

int buscaBin(int l[], int ini, int fim, int num){
	int meio = (ini + fim) / 2;
	
	if (ini > fim) return -1;
	
	if (l[meio] == num) return meio;
	
	if(l[meio] < num) return buscaBin(l, meio+1, fim, num);
	
	else return buscaBin(l, ini, meio-1, num);
}
