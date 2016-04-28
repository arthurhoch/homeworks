#ifndef ERRO_H
#define ERRO_H

#include "libs.h"

#define macroSeparador "\n************ERRO************ERRO************ERRO************"

#define macroVarriavel "\nVarriavel : "
#define macroFuncao "\nFunção    : "
#define macroArquivo "\nArquivo   : "
#define macroMotivo "\nMotivo    : "

#define memoria "Memoria insuficiente para alocar"
#define ponteiro "Ponterio retornando valor NULL"

int erroComEAFV(char *erro, char *arquivo, char *funcao, char *varriavel);
int erroComEAF(char *erro, char *arquivo, char *funcao);
int erroComEA(char *erro, char *arquivo);
int erroComE(char *erro);
void separador();

#endif