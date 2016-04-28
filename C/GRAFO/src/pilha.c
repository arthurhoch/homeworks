#include "pilha.h"

infoPilha *inicializarPilha()
{
	infoPilha *pilha = malloc(sizeof(infoPilha));
	pilha->topo = NULL;
	return pilha;
}

void empilhar(int e, infoPilha *pilha)
{
	if (pilha->topo == NULL)
	{
		pilha->topo = malloc(sizeof(nodoPilha));
		if(pilha->topo == NULL) erroComEAFV(memoria, arquivo_pilha, "empilhar", "pilha->topo");
		pilha->topo->conteudo = e;
		pilha->topo->prox = NULL;
		return;
	}
	else
	{
		nodoPilha *novoTopo;
		novoTopo = malloc(sizeof(nodoPilha));
		if(novoTopo == NULL) erroComEAFV(memoria, arquivo_pilha, "empilhar", "novoTopo");
		novoTopo->prox = pilha->topo;
		novoTopo->conteudo = e;
		pilha->topo = novoTopo;
	}

	return;
}

void desempilhar(infoPilha *pilha)
{
	if(pilha->topo == NULL)
	{
		erroComEAFV(ponteiro, arquivo_pilha, "desempilhar", "pilha->topo");
		return;
	}
	else
	{
		if(pilha->topo->prox != NULL && pilha->topo != NULL)
		{
			nodoPilha *velhoTopo;
			velhoTopo = pilha->topo;
			pilha->topo = pilha->topo->prox;
			free(velhoTopo);
		}
		else
		{
			free(pilha->topo);
			pilha->topo = NULL;
		}
	}

	return;
}

void desempilharTudo(infoPilha *pilha)
{
	if(pilha->topo != NULL)
	{
		while(pilha->topo != NULL)
		{
			printf("%d\n", pilha->topo->conteudo);
			desempilhar(pilha);
		}
	}
	else
		erroComEAFV(ponteiro, arquivo_pilha, "desempilharTudo", "pilha->topo");

	return;
}

int conteudoTopo(infoPilha *pilha)
{
	if(pilha->topo != NULL) return pilha->topo->conteudo;
	else return -10;
}