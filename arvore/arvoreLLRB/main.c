#include <stdio.h>
#include <stdlib.h>
#include "arvoreLLRB.h"

int main(){
	int x;
	ArvBin *raiz;
	arvoreLLRB *raiz;
	
	raiz = cria_arvoreLLRB();
	
	liberar_arvoreLLRB(raiz);
	
	if(vazia_arvoreLLRB(raiz)){
		printf("A arvore esta vazia.");
	}else{
		printf("A arvore possui elementos.");
	}
	printf("\n");
	
	x = altura_arvoreLLRB(raiz);
	printf("Altura da arvore: %d", x);
	
	x = totalNO_arvoreLLRB(raiz);
	printf("Total de nos na arvore: %d", x);
	
	preOrdem_arvoreLLRB(raiz);
	
	emOrdem_arvoreLLRB(raiz);
	
	posOrdem_arvoreLLRB(raiz);
	
	raiz = cria_arvoreLLRB();
	
	x = insere_arvoreLLRB (raiz, 150);
	x = insere_arvoreLLRB (raiz, 110);
	x = insere_arvoreLLRB (raiz, 100);
	x = insere_arvoreLLRB (raiz, 130);
	x = insere_arvoreLLRB (raiz, 120);
	x = insere_arvoreLLRB (raiz, 140);
	x = insere_arvoreLLRB (raiz, 160);
	
	remove_arvoreLLRB(raiz, 100);
	
	printf("\nBusca na Arvore Binaria:\n");
	if(consulta_arvoreLLRB(raiz, 140)){
		printf("\nConsulta realizada com sucesso!");
	}else{
		printf("\nElemento nao encontrado...");
	}
}

