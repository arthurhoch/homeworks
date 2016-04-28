/**************************************************************/
// * * * * * * ** * * * * * * * * *  * * * * ** * * * * * ** * * 
// * * * * * * ** * ARTHUR JAHNKE HOCH - m96600 * * * * * * ** *
// * * * * *  * * ** ** * ** * * * * ** * * * ** *2014/2* * * **
// * * * * * * * * * * * * * * ** * * * * * ** * *** * ** * ** *
/**************************************************************/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include <term.h>
#include <stdio.h>

#define row 10
#define col 8

//Jogo
int iniciar_jogo();
//Sortear
void gerar_senha(int vetor[]);
bool teste_repete(int x, int vetor[]);
//Tela user
void limpar_matriz(int matriz[][col]);
void ler_senha(int matriz[][col], int ult_linha_lida);
void desenha_tela(int matriz[][col]);
//Checar resposta
bool comparar_senha(int matriz[][col], int vetor[], int ult_linha_lida);
bool verificar_igualdade(int matriz[][col], int vetor[], int ult_linha_lida);
void colocar_resposta(int matriz[][col], int vetor[], int ult_linha_lida);
void mostrar_resposta(int vetor[]);
//Aux
void limpar_tela();
void primeira_execucao(int matriz[][col], int vetor[]);
bool interface_user(int matriz[][col], int ult_linha_lida, int vetor[]);
void ultima_palavra(bool ganhou);
bool continuar();
//Telas desprovidas de lógica
void tela(int status);
void boas_vindas();
void voce_ganhou();
void voce_perdeu();
void boa_viajem();
void carregamento(int status);
void set_color(int cor);
void reset_color();


int main(){
	return iniciar_jogo(); 	
}

int iniciar_jogo(){
	//Inteiras
	int senha[row/2], tela[row][col];
	int ult_linha_lida=0;
	int status = 0;
	//Boelanas
	bool terminou = false, ganhou = false, jogando = true;
	//Outro
	srand (time (0));
			
	carregamento(0);
	
	while(jogando == true){

		//Limpa, gera senha
		primeira_execucao(tela,senha);

		do{
			ganhou = interface_user(tela,ult_linha_lida,senha);
			ult_linha_lida++;		
		}while(ult_linha_lida != 10 && ganhou == false);

		desenha_tela(tela);
		ultima_palavra(ganhou);

		jogando = continuar();

		if(jogando == true){
			ult_linha_lida = 0;
			ganhou = false;
		}
		
	}

	carregamento(3);
	system("clear");
	printf("\n\n");

 	putp(exit_attribute_mode);

	return 0;
}

/**************************************************************/
//Auxiliares - (High level :P)
/**************************************************************/
void primeira_execucao(int matriz[][col], int vetor[]){
	limpar_tela();
	gerar_senha(vetor);
	//mostrar_resposta(vetor);
	limpar_matriz(matriz);
}

bool interface_user(int matriz[][col], int ult_linha_lida, int vetor[]){
	desenha_tela(matriz);
	ler_senha(matriz,ult_linha_lida);
	return comparar_senha(matriz,vetor,ult_linha_lida);
}

/**************************************************************/
//Operaçoes com a senha
/**************************************************************/

void gerar_senha(int vetor[]){
	int i=0;
	bool repetido = false;

	while(i != 5){
		vetor[i] = rand() % 6 + 1;
		repetido = teste_repete(i,vetor);
		if(repetido == false)
			i++;
	}
}

bool teste_repete(int x, int vetor[]){
    bool repitido = false;
    for (int y=0; y<x; y++){
        if (vetor[y]==vetor[x] ){
            repitido=true;
        }
    }
    return repitido;
}

bool comparar_senha(int matriz[][col], int vetor[], int ult_linha_lida){
	colocar_resposta(matriz,vetor,ult_linha_lida);
	bool resposta = verificar_igualdade(matriz,vetor,ult_linha_lida);
	if(resposta == true)
		return true;
	else
		return false;
}

bool verificar_igualdade(int matriz[][col], int vetor[], int ult_linha_lida){
	for(int i=0; i<col/2; i++)
		if(matriz[ult_linha_lida][i] != vetor[i])
			return false;
	return true;
}

void colocar_resposta(int matriz[][col], int vetor[], int ult_linha_lida){
	int local = col/2;
	int iguais = 0;
	int lugardiferente = 0;
	int escreva[col/2];
	int escreva_posicao[col/2+1];
	int cont=0;
	bool teste;
	bool teste_posicao;
	//Comparar por posição
	for(int i=0; i<col/2; i++)
		if(matriz[ult_linha_lida][i] == vetor[i]){
			matriz[ult_linha_lida][local] = 8;
			escreva_posicao[iguais] = vetor[i];
			local++;
			iguais++;
		}
	for(int i=0; i<col/2; i++){
		for (int j=0;j<col/2;j++){
			if (matriz[ult_linha_lida][i]==vetor[j]){
	    		escreva[cont] = vetor[j];
	        	teste = teste_repete(cont,escreva);
	        	escreva_posicao[iguais+1] = vetor[j];
	        	teste_posicao = teste_repete(iguais+1,escreva_posicao);
	            if(teste == false && teste_posicao == false && escreva_posicao[iguais] != vetor[j]){
	            	cont++;
	            	lugardiferente++;
	            }
	       	}
	    }
	}
	for(int i=local; i<(local+lugardiferente); i++)
		matriz[ult_linha_lida][i] = 7;

}

void mostrar_resposta(int vetor[]){
	for(int i=0; i<col/2; i++)
		printf(" %d ", vetor[i]);
	printf("\n");
}


/**************************************************************/
//Operaçoes com a interface com o usuario
/**************************************************************/

void limpar_matriz(int matriz[][col]){
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			matriz[i][j] = 0;
}

void ler_senha(int matriz[][col], int ult_linha_lida){
	printf("\nDigite o numero conforme a cor:  \n");
	set_color(1);
	printf("1 - Vermelho\n");
	set_color(2);
	printf("2 - Verde\n");
	set_color(3);
	printf("3 - Amarelo\n");
	set_color(4);
	printf("4 - Azul\n");
	set_color(5);
	printf("5 - Roxo\n");
	set_color(6);
	printf("6 - Cyan\n");
	reset_color();
	printf("Insira da seguinte forma: (n1 n2 n3 n4)\n\n");
	printf(">>> ");
	for(int i=0; i<4; i++){
		scanf("%d%*c", &matriz[ult_linha_lida][i]);
	}
}

void desenha_tela(int matriz[][col]){
	printf("\nRespostas\t\tCerto = 8 / Lugar errado = 7\n");
	for(int i=0; i<row; i++){
		printf("\n |");
		for(int j=0; j<col; j++){
			if(j == 4)
				printf(" |");
			set_color(matriz[i][j]);
			printf(" %2d  |", matriz[i][j]);
			reset_color();
		}
	}
	printf("\n");
}
/**************************************************************/
//Auxiliares
/**************************************************************/

void ultima_palavra(bool ganhou){
	if(ganhou == true)
		carregamento(1);
	else
		carregamento(2);
}

bool continuar(){
	char sn = 'S';
	bool continuar = true;

	printf("\n\nJogar novamente ? S/n\n");
	printf(">>> ");
	scanf("%c%*c", &sn);

	if(sn == 'n' || sn == 'N')
		continuar = false;

	return continuar;
}

void limpar_tela(){
	system("clear");
}

/**************************************************************/
//Logica não encontrada
/**************************************************************/
void tela(int status){
	switch(status){
		case 0:
			set_color(4);
			boas_vindas();
			reset_color();
			break;
		case 1:
			set_color(6);
			voce_ganhou();
			reset_color();
			break;
		case 2:
			set_color(1);
			voce_perdeu();
			reset_color();
			break;
		case 3:
			set_color(2);
			boa_viajem();
			reset_color();
			break;
	}
}

void carregamento(int status){
	int tam_barra = 50;
	char carregamento[tam_barra];
	for(int x=0; x<tam_barra; x++){
		carregamento[x] = '-';
		if(x == 0)
			carregamento[x] = '[';
		if(x == tam_barra-1)
			carregamento[x] = ']';
	}
	for(int j=0; j<tam_barra; j++){
		if(j>0 && j != tam_barra-1){
			if(j % 2 == 0)
				carregamento[j] = 'c';
			else
				carregamento[j] = 'C';
			if(j>2)
				carregamento[j-2] = ' ';
			if(j == tam_barra-2)
				carregamento[j] = ' ';

		}
		system("clear");
		tela(status);
		printf("\n\n");
		for(int i=0; i<tam_barra; i++){
			printf("%c", carregamento[i]);
		}
		fflush(stdout);
		usleep(70000);
		fflush(stdout);
	}

	fflush(stdout);
	usleep(900000);
	fflush(stdout);
	printf("\n");

}

void boas_vindas(){
	printf("\n");
	printf("########   ########   ###     ###\n");
	printf("#    ###   #          # ##    # #\n");
	printf("# #####    #          #  ##  ## #\n");
	printf("###        #####      #    ##   #\n");
	printf("# #####    #          #         #\n");
	printf("#   ####   #          #         #\n");
	printf("#######    ########   #         #\n");
	printf("\n\n");
	printf("\t#            #   #   ##      #   ######         #######   \n");
	printf("\t #          #        # #     #   #    ###      ##     ##  \n");
	printf("\t  #        #     #   #  #    #   #     ##     ##       ## \n");
	printf("\t   #      #      #   #   #   #   #      ##   ##         ##\n");
	printf("\t    #    #       #   #    #  #   #      ##    ##       ## \n");
	printf("\t     #  #        #   #     # #   #     ###     ##     ##  \n");
	printf("\t       #         #   #      ##   #######        #######   \n");

}

void voce_ganhou(){
	printf("\n");
	printf("\t#                   #   #   ##      #\n");
	printf("\t #                 #        # #     #\n");
	printf("\t  #               #     #   #  #    #\n");
	printf("\t   #      ##     #      #   #   #   #\n");
	printf("\t    #    #  #   #       #   #    #  #\n");
	printf("\t     #  #    # #        #   #     # #\n");
	printf("\t       #      #         #   #      ##\n");
}

void voce_perdeu(){
	setupterm(NULL, STDOUT_FILENO, NULL);
	putp(tparm(set_a_foreground, 1));
	printf("\n");
	printf("#            #######   ##########   #########\n");
	printf("#           ##     ##   #           #        \n");
	printf("#          ##       ##   #          #        \n");
	printf("#         ##         ##    ####     #####    \n");
	printf("#          ##       ##          #   #        \n");
	printf("#           ##     ##          #    #        \n");
	printf("#######      #######     ######     #########\n");
}

void boa_viajem(){
	printf("\n");
	printf("########   #       #   #########\n");
	printf("#    ###    #     #    #        \n");
	printf("# #####      #   #     #        \n");
	printf("###           # #      #####    \n");
	printf("# #####        #       #        \n");
	printf("#   ####        #      #        \n");
	printf("#######          #     #########\n");
}

/**************************************************************/
//Corres
/*************************************************************/

void set_color(int cor){
	setupterm(NULL, STDOUT_FILENO, NULL);
	putp(tparm(set_a_foreground, cor));
}
void reset_color(){
	putp(exit_attribute_mode);
}

/**************************************************************/
//Fim do arquivo
/**************************************************************/
