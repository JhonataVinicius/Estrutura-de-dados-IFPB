#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    char conteudo;
    struct celula *prox;
} sNODE;

typedef struct pilha {
    struct celula *topo;
} pilha;

void empilha(char c, pilha *p);
char desempilha(pilha *p);

int main() {
    char frase[50];
    pilha p;
    p.topo = NULL;
    printf("Digite a frase a ser invertida: ");
    gets(frase);
    printf("\nInvertida: ");
    for (int i = 0; frase[i] != '\0'; i++) {
        for (; frase[i] != '\0' && frase[i] != ' '; i++) {
            empilha(frase[i], &p);
        }
        while (p.topo != NULL) {
            char x=desempilha(&p);
            if (x != '\n')
            	putchar(x);
        }
        if(frase[i] == ' ')
        	putchar(' ');
        else
        	putchar('\n');
    }
    return 0;
}

void empilha(char c, pilha *p) {
    sNODE *nova = (sNODE *) malloc(sizeof(sNODE));
    nova->conteudo = c;
    nova->prox = p->topo;
    p->topo = nova;
}

char desempilha(pilha *p) {
    sNODE *pt = p->topo;
    char c = pt->conteudo;
    p->topo = pt->prox;
    free(pt);
    return c;
}
