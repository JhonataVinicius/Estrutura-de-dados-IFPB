#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned MAX = 100;
int l[MAX], pos = 0;
int parentesesA = 0;
int parentesesF = 0;
char str[100];

void push(int elemento);
void pop(int elemento);
void verifica_balanceamento();

void imprimir();

int main(void) {
	printf("Digite um string para saber se ela contém uma expressão com a parentização correta: ");
	gets(str);
	
	for(int i = 0; i < strlen(str);i++){
		push(str[i]);
	}

	for(int p = 0; p <= strlen(str)-1;p++){
		pop(l[p]);
	}
	
	verifica_balanceamento();
	
/*	testes
	(2+3)-(9/9)  ok 
	)2+3(-(9/9)  errado
	
	((2+3)-(9/9))  ok
	(2+3-(9/9) errado
	((2+3-(9/9)))  ok
*/
}

void verifica_balanceamento(){
	if (parentesesA == parentesesF)
		printf("OK");
	else
		printf("Não OK");
}

void push(int elemento){
  if (pos < MAX)
	l[pos++] = elemento;
  else
	printf("Não foi possível inserir %d. Pilha cheia.\n",elemento);
}

void pop(int elemento){
	if (elemento == (int)'('){
		parentesesA++;
	}
	else if (elemento == (int)')'){
		if (parentesesA > parentesesF)
			parentesesF++;
		else{
			printf("Não OK");
			exit(1);
		}	
	}
}

void imprimir(){
  printf("P[ ");
  for (int i = pos -1 ; i >= 0 ; i--)
	printf("%d ",l[i]);
  printf("]\n");
}

