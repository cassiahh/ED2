#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

int main(){
	int x, valor;
	arvAVL *raiz;

	raiz = cria_arvAVL();

	liberar_arvAVL(raiz);

	if(vazia_arvAVL(raiz)){
		printf("A arvore esta vazia.");
	}else{
		printf("A arvore possui elementos.");
	}
	printf("\n");

	x = altura_arvAVL(raiz);
	printf("Altura da arvore: %d", x);

	x = totalNO_arvAVL(raiz);
	printf("Total de nos na arvore: %d", x);

	preOrdem_arvAVL(raiz);

	emOrdem_arvAVL(raiz);

	posOrdem_arvAVL(raiz);

	raiz = cria_arvAVL();

	x = insere_arvAVL (raiz, 100);
	x = insere_arvAVL (raiz, 140);
	x = insere_arvAVL (raiz, 160);
	x = insere_arvAVL (raiz, 130);
	x = insere_arvAVL (raiz, 150);
	x = insere_arvAVL (raiz, 110);
	x = insere_arvAVL (raiz, 120);

	if(x){
		printf("Elemento inserido com sucesso.");
	}else{
		printf("Erro, não foi possivel inserir o elemento.");
	}

	x = remove_arvAVL(raiz, valor);
	if(x){
		printf("Elemento removido com sucesso!.");
	}else{
		printf("Erro, não foi possível remover o elemento.");
	}


	printf("\nBusca na Arvore AVL:\n");
	if(consulta_arvAVL(raiz, 140)){
		printf("\nConsulta realizada com sucesso!");
	}else{
		printf("\nElemento nao encontrado...");
	}
}

