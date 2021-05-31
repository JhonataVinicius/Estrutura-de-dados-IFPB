
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
      char   string[20]; 
   } palavra;

palavra lista[10], aux;
int  cont=0;
char fim [] = "\0";

void inserir_ord(char elemento[20]){
	int i, k;
	//printf("%s\n", elemento);
	if(strncmp(lista[0].string, fim,1) == 0){
		
		strcpy(lista[0].string, elemento);
		//printf(" primeiro elemento: %s\n",lista[0].string);
	}
  
	//printf("%s\n", lista[0].string);	
	
  if (cont<10){
    for (i=0; i < cont; i++)
      if(strncmp(lista[i].string, fim,1) == 0)
        break;
      if( strcmp(elemento, lista[i].string) < 0)
          
          strcpy(aux.string, lista[i].string);
          
          strcpy(lista[i].string, elemento);
          
          strcpy(lista[i+1].string, aux.string);
          

          
          
        
      //printf("primeiro for: %s\n", lista[i].string);

    cont++;
    }
	

  for (i=0; i<cont; i++){
    // printf("%s\n", lista[i].string);
    for(k=0; k<cont; k++){
     // printf("%s\n", lista[k].string);
      if(strcmp(lista[i].string, lista[k].string) < 0){
        
        strcpy(aux.string, lista[i].string);
        
        strcpy(lista[i].string, lista[k].string);
        
        strcpy(lista[k].string, aux.string); 
        
      }	
      
      //printf("segundo for: %s\n", lista[i].string);	
    }
    //printf("segundo for: %s\n", lista[i].string);
  }					
	
}

void imprimir(){
  for (int i = 0 ; i < cont ; i++)
	  printf("%s\n", lista[i].string);
  printf("\n");
}


int main(void){
	
	inserir_ord("aleff");
  inserir_ord("geraldo");
  inserir_ord("zefa");
  inserir_ord("karla");
 

  imprimir();
 
  inserir_ord("ronaldo");
  imprimir();
	
  

	
  
	return 0;
}
