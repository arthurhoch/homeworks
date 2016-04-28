#ifndef FILA_H
#define FILA_H

#include "libs.h"

#define arquivo_fila "fila.c"

typedef struct nodo nodoFila;

typedef struct infoFila
{
	nodoFila *inicio;
	nodoFila *fim;
}infoFila;

infoFila *inicializarFila();
void enfilerar(int e, infoFila *fila);
void desinfilerar(infoFila *fila);
int naoContem(int e, infoFila *fila);
int conteudoInicio(infoFila *fila);
void escreverFila(infoFila *fila);

#endif