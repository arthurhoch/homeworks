#include "fila.h"

infoFila *inicializarFila()
{
	infoFila *fila;
	fila = malloc(sizeof(infoFila));
	if(fila == NULL) erroComEAF(memoria, arquivo_fila, "inicializarFila");
	fila->inicio = fila->fim = NULL;

	return fila;
}

void enfilerar(int e, infoFila *fila)
{	
	if(fila->inicio == NULL && fila->fim == NULL)
	{	
		fila->inicio = malloc(sizeof(nodoFila));
		if(fila->inicio == NULL) erroComEAFV(memoria, arquivo_fila, "enfilerar", "fila->inicio");
		fila->inicio->conteudo = e;
		fila->fim = fila->inicio;
	}
	else if(contem(e, fila) == 0)
	{
		nodoFila *velhoFim;
		velhoFim = fila->fim;
		fila->fim = malloc(sizeof(nodoFila));
		if(fila->fim == NULL) erroComEAFV(memoria, arquivo_fila, "enfilerar", "fila->fim");
		fila->fim->conteudo = e;
		velhoFim->prox = fila->fim;
		fila->fim->prox = NULL;
	}

	return;
}

void desinfilerar(infoFila *fila)
{
	if(fila->inicio != NULL)
	{
		if(fila->inicio == fila->fim)
		{
			free(fila->inicio);
			fila->inicio = fila->fim = NULL;
		}
		else
		{
			nodoFila *velhoInicio;
			velhoInicio = fila->inicio;
			fila->inicio = fila->inicio->prox;
			free(velhoInicio);
		}
	}
	else erroComEAF(ponteiro, arquivo_fila, "desinfilerar");

	return;
}

int contem(int e, infoFila *fila)
{
	nodoFila *percorer = fila->inicio;

	while(percorer != NULL){
		if(percorer->conteudo == e) return 1;
		percorer = percorer->prox;
	}
	return 0;
}

int conteudoInicio(infoFila *fila)
{
	if(fila->inicio != NULL) return fila->inicio->conteudo;
	else return NULL;
}

void escreverFila(infoFila *fila)
{
	nodoFila *percorer = fila->inicio;

	while(percorer != NULL)
	{
		printf("%d\n", percorer->conteudo);
		percorer = percorer->prox;
	}
}