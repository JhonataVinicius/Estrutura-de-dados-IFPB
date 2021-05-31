#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSort(int l[], int tam){
  int trocou = 1;
  for (int i = 0 ; i < tam && trocou; i++) {
    trocou = 0;
    for (int j = 0 ; j < tam - 1 - i; j++)
      if (l[j] < l[j+1]) {
        troca(&l[j],&l[j+1]);
        trocou = 1;
      }
  }
}

int main(void) {
  int l[] = {1,2,3,4,5}, tam = 5;
  //int l[] = {3,2,5,4,1}, tam = 5;

  bubbleSort(l, tam);

  for (int i = 0 ; i < tam ; i++)
    printf("%d ",l[i]);
  return 0;
}
