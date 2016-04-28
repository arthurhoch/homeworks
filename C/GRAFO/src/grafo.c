#include "grafo.h"

infoGrafo *inicializarGrafo()
{
	infoGrafo *grafo = malloc(sizeof(infoGrafo));
	grafo->inicio = NULL;
	
	return grafo;
}

void criarNodo(int e, infoGrafo *grafo)
{
	if(grafo->inicio == NULL)
	{
		grafo->inicio = malloc(sizeof(nodoGrafo));
		grafo->inicio->conteudo = e;
		grafo->inicio->adj = inicializarLista();
	}
	else if (grafo->inicio->conteudo > e)
	{
		nodoGrafo *anterio;
		anterio = malloc(sizeof(nodoGrafo));
		anterio->adj = inicializarLista();
		anterio->conteudo = e;
		anterio->prox = grafo->inicio;
		grafo->inicio = anterio;
	}
	else
	{
		nodoGrafo *percorer;
		nodoGrafo *anterio;

		percorer = grafo->inicio;

		while(percorer != NULL && percorer->conteudo <= e){
			anterio = percorer;
			percorer = percorer->prox;
		}
		if(anterio->conteudo != e)
		{
			percorer = malloc(sizeof(nodoGrafo));
			percorer->conteudo = e;
			percorer->adj = inicializarLista();
			percorer->prox = anterio->prox;
			anterio->prox = percorer;
		}
	}

	return;
}

void deletarNodo(int e, infoGrafo *grafo)
{
	if (grafo->inicio == NULL)
	{
		return NULL;
	}
	else if(grafo->inicio->conteudo == e)
	{
		if(grafo->inicio->prox == NULL)
		{
			free(grafo->inicio);
			grafo->inicio = NULL;
		}
		else
		{
			nodoGrafo *anterio;
			anterio = grafo->inicio;
			grafo->inicio = grafo->inicio->prox;
			free(anterio->adj);
			free(anterio);
		}
	}
	else
	{	
		nodoGrafo *anterio;
		nodoGrafo *percorer;
		percorer = grafo->inicio;

		while(percorer != NULL && percorer->conteudo != e)
		{
			anterio = percorer;
			percorer = percorer->prox;
		}
		if(percorer->conteudo == e)
		{
			anterio->prox = percorer->prox;
			free(anterio->adj);
			free(percorer);
		}
	}

	return;
}

void conectar(int de, int para, infoGrafo *grafo)
{
	nodoGrafo *deNodo, *paraNodo;

	paraNodo = ponteiroPara(para, grafo);

	if(paraNodo == NULL)
	{
		criarNodo(para, grafo);
	}

	deNodo = ponteiroPara(de, grafo);

	if(deNodo == NULL)
	{
		criarNodo(de, grafo);
		deNodo = ponteiroPara(de, grafo);
	}

	adicionar(para, deNodo->adj);

	return;
}

void conectarAmbos(int de, int para, infoGrafo *grafo)
{
	conectar(de, para, grafo);
	conectar(para, de, grafo);

	return;
}

void desconectar(int de, int para, infoGrafo *grafo)
{
	nodoGrafo *deNodo = ponteiroPara(de, grafo);
	
	if(deNodo != NULL)
	{
		remover(para, deNodo->adj);
	}

	return;
}

nodoGrafo *ponteiroPara(int e, infoGrafo *grafo)
{
	nodoGrafo *para;
	para = grafo->inicio;
	while(para != NULL && para->conteudo != e){
		para = para->prox;
	}
	if(para == NULL) return NULL;
	else return para;
}

void imprimirListaAdj(infoGrafo *grafo)
{
	nodoGrafo *percorer = grafo->inicio;

	while(percorer != NULL)
	{
		printf("%d --> ", percorer->conteudo);
		escreverLista(percorer->adj);
		putchar('\n');
		percorer = percorer->prox;
	}

	return;
}

//pode dar erro caso o numero nao esteja no grafo
//tratar

void percursoLargura(int e, infoGrafo *grafo)
{
	infoLista *resultado = inicializarLista();
	infoFila  *cache = inicializarFila();

	nodoGrafo *posicao = ponteiroPara(e, grafo);

	if(posicao != NULL)
	{	
		nodoLista *percorerLista;
		enfilerar(posicao->conteudo, cache);
		adicionar(posicao->conteudo, resultado);
		do
		{	
			percorerLista = posicao->adj->inicio;
			while(percorerLista != NULL)
			{
				if((possui(percorerLista->conteudo, resultado)) == 0)
				{				
					enfilerar(percorerLista->conteudo, cache);
					adicionarFinal(percorerLista->conteudo, resultado);
				}
				percorerLista = percorerLista->prox;
			}
			desinfilerar(cache);
			if (cache->inicio != NULL)
			{
				posicao  = ponteiroPara(conteudoInicio(cache), grafo);
			}
		}while(posicao != NULL && cache->inicio != NULL);
	}
	escreverLista(resultado);

	return;
}

int valorProximoPonteiro(infoLista *resultado, nodoGrafo *posicaoAtual)
{
	nodoLista *percorerLista = posicaoAtual->adj->inicio;

	while(percorerLista != NULL)
	{
		if(possui(percorerLista->conteudo, resultado) == 0)
		{
			return percorerLista->conteudo;
		}
		percorerLista = percorerLista->prox;
	}

	return -1;
}

void percursoProfundidade(int e, infoGrafo *grafo)
{
	int proximoValor = e;

	infoLista *resultado = inicializarLista();
	infoPilha *cache = inicializarPilha();

	nodoGrafo *posicao = ponteiroPara(e, grafo);

	empilhar(e, cache);
	adicionarFinal(e, resultado);
	
	while(conteudoTopo(cache) != -10)
	{
		posicao = ponteiroPara(conteudoTopo(cache), grafo);
		proximoValor = valorProximoPonteiro(resultado, posicao);
		if(proximoValor == -1)
		{
			desempilhar(cache);
		}
		else
		{
			empilhar(proximoValor, cache);
			adicionarFinal(proximoValor, resultado);
		}
	}
	escreverLista(resultado);

	return;
}

void menu()
{
	printf("(0) Sair\n");
	printf("(1) Conectar\n");
	printf("(2) Desconectar\n");
	printf("(3) PercursoLargura\n");
	printf("(4) PercursoProfundidade\n");
	printf("(5) ImprimirListaAdj\n");

}

int main(){

	int op =  500000;
	int de, para;
	int inicio;



	infoGrafo *g = inicializarGrafo();
	

	while(op != 0)
	{
		menu();
		scanf("%d", &op);

		switch(op)
		{
			case 0:
				exit(0);
			case 1:
				printf("Digite os dois valores para serem conectados: \n");
				printf("De --> ");
				scanf("%d", &de);
				printf("Para --> ");
				scanf("%d", &para);
				conectar(de, para, g);
				putchar('\n');
				break;
			case 2:
				printf("Digite o valor para desconectar: \n");
				printf("De --> ");
				scanf("%d", &de);
				printf("Para --> ");
				scanf("%d", &para);
				desconectar(de, para, g);
				putchar('\n');
				break;
			case 3:
				printf("Digite o nodo para o inicio do percurso: \n");
				scanf("%d", &inicio);
				printf("PercursoLargura:\n");
				percursoLargura(inicio, g);
				putchar('\n');
				break;
			case 4:
				printf("Digite o nodo para o inicio do percurso: \n");
				scanf("%d", &inicio);
				printf("PercursoProfundidade:\n");
				percursoProfundidade(inicio, g);
				putchar('\n');
				break;
			case 5:
				printf("ImprimirListaAdj: \n");
				imprimirListaAdj(g);
				putchar('\n');
				break;
			default:
				printf("Opção invalida: \n");
				break;



		}

	}
	
	


}