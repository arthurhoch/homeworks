#include "erro.h"

int erroComEAFV(char *erro, char *arquivo, char *funcao, char *varriavel)
{
	separador();
	printf("%s%s\n", macroVarriavel, varriavel);
	printf("%s%s\n", macroFuncao, funcao);
	printf("%s%s\n", macroArquivo, arquivo);
	printf("%s%s\n", macroMotivo, erro);
	separador();
	return -1;
}

int erroComEAF(char *erro, char *arquivo, char *funcao)
{
	separador();
	printf("%s%s\n", macroFuncao, funcao);
	printf("%s%s\n", macroArquivo, arquivo);
	printf("%s%s\n", macroMotivo, erro);
	separador();
	return -1;
}

int erroComEA(char *erro, char *arquivo)
{
	separador();
	printf("%s%s\n", macroArquivo, arquivo);
	printf("%s\n", erro);
	separador();
	return -1;
}

int erroComT(char *erro)
{
	separador();
	printf("%s%s\n", macroMotivo, erro);
	separador();
	return -1;
}

void separador()
{
	printf("%s\n", macroSeparador);
	return;
}