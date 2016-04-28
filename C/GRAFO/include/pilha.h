#ifndef PILHA_H
#define PILHA_H

#include "libs.h"

#define arquivo_pilha "pilha.c"

#define DEBUG_PILHA 1

typedef struct nodo nodoPilha;

typedef struct infoPilha
{
	nodoPilha *topo;
}infoPilha;


infoPilha *inicializarPilha();
void empilhar(int e, infoPilha *topo);
void desempilhar(infoPilha *topo);
#if DEBUG_PILHA
	void desempilharTudo(infoPilha *topo);
#endif
int conteudoTopo(infoPilha *topo);

#endif