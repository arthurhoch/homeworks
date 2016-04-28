#include "lista.h"

infoLista *inicializarLista()
{
	infoLista *lista = malloc(sizeof(infoLista));
	lista->inicio = NULL;
	lista->fim = NULL;
}

void adicionar(int e, infoLista *lista)
{
	if(lista->inicio == NULL && lista->fim == NULL)
	{
		lista->inicio = malloc(sizeof(nodoLista));
		if(lista->inicio == NULL) erroComEAFV(memoria, arquivo_lista, "adicionar", "lista->inicio");
		lista->inicio->conteudo = e;
		lista->fim = lista->inicio;
		lista->fim->prox = lista->inicio->prox = NULL;
	}
	else if (lista->inicio->conteudo > e)
	{
		nodoLista *anterio;
		anterio = malloc(sizeof(nodoLista));
		if(anterio == NULL) erroComEAFV(memoria, arquivo_lista, "adicionar", "anterio");
		anterio->conteudo = e;
		anterio->prox = lista->inicio;
		lista->inicio = anterio;
	}
	else
	{
		nodoLista *percorer;
		nodoLista *anterio;

		percorer = lista->inicio;
		anterio = percorer;

		while(percorer != NULL && percorer->conteudo <= e){
			anterio = percorer;
			percorer = percorer->prox;
		}
		if(anterio->conteudo != e)
		{
			percorer = malloc(sizeof(nodoLista));
			if(percorer == NULL) erroComEAFV(memoria, arquivo_lista, "adicionar", "percorer");
			percorer->conteudo = e;
			percorer->prox = anterio->prox;
			anterio->prox = percorer;
			if(percorer->prox == NULL) lista->fim = percorer;
		}
	}

	return;
}

void adicionarFinal(int e, infoLista *lista)
{
	if(lista->inicio == NULL && lista->fim == NULL)
	{
		lista->inicio = malloc(sizeof(nodoLista));
		if(lista->inicio == NULL) erroComEAFV(memoria, arquivo_lista, "adicionarFinal", "lista->inicio");
		lista->inicio->conteudo = e;
		lista->fim = lista->inicio;
		lista->fim->prox = lista->inicio->prox = NULL;
	}
	else
	{
		nodoLista *sucessor;

		sucessor = malloc(sizeof(infoLista));
		if(sucessor == NULL) erroComEAFV(memoria, arquivo_lista, "adicionarFinal", "sucessor");
		sucessor->conteudo = e;
		sucessor->prox = NULL;
		lista->fim->prox = sucessor;
		lista->fim = sucessor;
	}

	return;
}

void remover(int e, infoLista *lista)
{
	int tem = possui(e, lista);

	if(tem == 1)
	{
		if(lista->inicio->conteudo == e)
		{
			if(lista->inicio->prox != NULL)
			{
				nodoLista *subsequente;
				subsequente = lista->inicio->prox;
				free(lista->inicio);
				lista->inicio = subsequente;
			}	
			else
			{
				free(lista->inicio);
				lista->fim = lista->inicio = NULL;
			}
				
			return;
		}
		else
		{	
			nodoLista *anterio;
			nodoLista *percorer;
			percorer = lista->inicio;

			while(percorer != NULL && percorer->conteudo != e)
			{
				anterio = percorer;
				percorer = percorer->prox;
			}
			if(percorer->conteudo == e)
			{
				anterio->prox = percorer->prox;
				if(anterio->prox == NULL)
					lista->fim = anterio;
				free(percorer);
			}
		}
	}
	else
		erroComEAFV(ponteiro, arquivo_lista, "remover", "tem");

	return;
}

int escreverLista(infoLista *lista)
{
	if(lista != NULL)
	{
		nodoLista *percorer;

 		percorer = lista->inicio;

		while(percorer != NULL){
			printf(" %d ", percorer->conteudo);
			percorer = percorer->prox;
		}
	}
	else
		erroComEAFV(ponteiro, arquivo_lista, "escreverLista", "lista");

	return 0;
}

int possui(int e, infoLista *lista)
{
	if (lista->inicio == NULL)
	{
		erroComEAFV(ponteiro, arquivo_lista, "possui", "fila->inicio");
		return 0;
	}
	
	nodoLista *percorer;

	percorer = lista->inicio;

	while(percorer != NULL)
	{
		if(percorer->conteudo == e)
		{
			return 1;
		}
		percorer = percorer->prox;
	}

	return 0;
}