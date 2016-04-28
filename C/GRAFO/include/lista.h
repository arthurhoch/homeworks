#ifndef LISTA_H
#define LISTA_H

#include "libs.h"

#define arquivo_lista "lista.c"

typedef struct nodo nodoLista;

typedef struct infoLista
{
	nodoLista *inicio;
	nodoLista *fim;
}infoLista;

infoLista *inicializarLista();
void adicionar(int e, infoLista *inicio);
void adicionarFinal(int e, infoLista *inicio);
void remover(int e, infoLista *inicio);
int escreverLista(infoLista *inicio);
int possui(int e, infoLista *inicio);

#endif