#ifndef GRAFO_H
#define GRAFO_H

#include "libs.h"
#include "fila.h"
#include "lista.h"
#include "pilha.h"

typedef struct nodoGrafo
{
	int conteudo;
	struct nodoGrafo *prox;
	infoLista  *adj;
}nodoGrafo;

typedef struct infoGrafo
{	nodoGrafo *inicio;
}infoGrafo;

infoGrafo *inicializarGrafo();
void criarNodo(int e, infoGrafo *grafo);
void deletarNodo(int e, infoGrafo *grafo);
void conectar(int de, int para, infoGrafo *grafo);
void conectarAmbos(int de, int para, infoGrafo *grafo);
void desconectar(int de, int para, infoGrafo *grafo);
nodoGrafo *ponteiroPara(int e, infoGrafo *grafo);
void imprimirListaAdj(infoGrafo *grafo);
void percursoLargura();
void percursoProfundidade();

#endif