#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  char piloto[50];
  char modelo_aeronave[20];
  int num_voo, num_passageiros;
  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

typedef struct sFILA FILA;

void criar(FILA *fi);

void adiciona_aviao(FILA *fi, char *piloto, char *modelo_aeronave, int num_voo, int num_passageiros);

int num_avioes_aguardando(FILA *fi);

void decola_primeiro(FILA *fi);

void avioes_em_espera(FILA *fi);

void primeiro_aviao(FILA *fi);

int main(void){
	FILA fila1;
	criar(&fila1);
	adiciona_aviao(&fila1,"Miguel","Airbus A320", 911, 154);
	adiciona_aviao(&fila1,"Joyce","Boeing 787", 245, 257);  
	adiciona_aviao(&fila1,"Julio","Cessna 172 Skyhawk", 111,4);
	adiciona_aviao(&fila1,"Jhonata","Airbus A350 XWB", 909, 295);
	
	printf("Quantidade de avioes em espera: %d\n\n", num_avioes_aguardando(&fila1));
	avioes_em_espera(&fila1);
	
	primeiro_aviao(&fila1);
	
	printf("Autorizando decolagem do primeiro aviao da fila\n\n");
	decola_primeiro(&fila1);
	
	primeiro_aviao(&fila1);
	
	printf("Quantidade de avioes em espera: %d\n\n", num_avioes_aguardando(&fila1));
	avioes_em_espera(&fila1);
	
}


void criar(FILA *fi){
  struct sNODE *fila = (struct sNODE*) malloc(sizeof(struct sNODE ));
	fi->ini=NULL;
	fi->fim=NULL;
}

void adiciona_aviao(FILA *fi, char *piloto, char *modelo_aeronave, int num_voo, int num_passageiros){
  struct sNODE *aux = fi->ini;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  
  strcpy(novo->piloto,piloto);
  strcpy(novo->modelo_aeronave, modelo_aeronave);
  novo->num_voo = num_voo;
  novo->num_passageiros = num_passageiros;
  novo->prox = NULL;

  if (!fi->ini)
    fi->ini = fi->fim = novo;
  else{
	fi->fim->prox = novo;
    fi->fim = novo;
  }
}

int num_avioes_aguardando(FILA *fi){
  struct sNODE *aux = fi->ini;
  int quantidade_avioes = 0; 
  while (aux){
	quantidade_avioes++;
	aux = aux->prox;
  } 
  return quantidade_avioes;
}

void decola_primeiro(FILA *fi){
	if (fi->ini){
		struct sNODE *tmp = fi->ini;
		
		if (fi->ini == fi->fim)
			fi->ini = fi->fim = NULL;
		else
			fi->ini = fi->ini->prox;
		
		free(tmp);
	}
	
	else{
		printf("Não há elementos. Fila vazia.\n");
		exit(1);
	}
}

void avioes_em_espera(FILA *fi){
	struct sNODE *aux = fi->ini; 
	printf("Fila de avioes esperando autorizacao para decolar:\n\n");
	int cont = 0;
	while (aux){
		cont++;
		printf("%d aviao na fila de espera:\n",cont);
		printf("Nome do piloto: %s\n",aux->piloto);
		printf("Numero do voo: %d\n\n",aux->num_voo);
		aux = aux->prox;
	}
}

void primeiro_aviao(FILA *fi){
	struct sNODE *aux = fi->ini; 
	printf("Informacoes do primeiro aviao da fila:\n\n");
	if(fi->ini){
		printf("Nome do piloto: %s\n",aux->piloto);
		printf("Modelo da aeronave: %s\n",aux->modelo_aeronave);
		printf("Numero do voo: %d\n",aux->num_voo);
		printf("Numero de passageiros: %d\n\n",aux->num_passageiros);
	}
}
