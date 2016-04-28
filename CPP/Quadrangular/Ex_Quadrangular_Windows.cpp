//+_+_+_+_+_+_+__+__+__+__+__+_+_
//_+__+_By: "Sir" Arthur_+__+__+_
//+_+_+_+_+_+_+__+__+__+__+__+_+_

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main (void)
{
    int gols[6][2],ti[4][8],t[4],contador = 0;
    int ponto_escolha[4],pontos[4];
    int x=0,a=0,y=-1;
    std::string cabecalho[9] = {"Nomes","Jogos","V","E","D","GolsPros","GolsContra","Saldo","Pontos"};
    char time[4][9]={"Time1","Time2","Time3","Time4"};
    std::string ranque[4];
    for (int i=0; i<4; i++){pontos[i] = 0;ponto_escolha[i] = 0;t[i] = 0;ranque[i]= "";}
    for (int i=0; i<7; i++) for (int j=0; j<3; j++) gols[i][j] = 0;
    for (int i=0; i<4; i++) for (int j=0; j<8; j++) ti[i][j] = 0;
    for(x; x < 3; x++){
        y = x + 1;
        for(y ; y < 4; y++){
            printf("\t\t***Quandrangular Final 2014***\n\n");
            printf("Tabela de classificacao:\n\n");
            printf("-------------------------------------------------------------------\n");
            printf("|%9s| %8s| %1s| %1s| %1s| %3s| %3s| %3s| %3s| \n", cabecalho[0].c_str(), cabecalho[1].c_str(), cabecalho[2].c_str(), cabecalho[3].c_str(), cabecalho[4].c_str(), cabecalho[5].c_str(), cabecalho[6].c_str(), cabecalho[7].c_str(),cabecalho[8].c_str());
            printf("|%9s| %8d| %1d| %1d| %1d| %8d| %10d| %5d| %6d| \n", time[0], ti[0][0], ti[0][1], ti[0][2], ti[0][3], ti[0][4], ti[0][5], ti[0][6],ti[0][7]);
            printf("|%9s| %8d| %1d| %1d| %1d| %8d| %10d| %5d| %6d| \n", time[1], ti[1][0], ti[1][1], ti[1][2], ti[1][3], ti[1][4], ti[1][5], ti[1][6],ti[1][7]);
            printf("|%9s| %8d| %1d| %1d| %1d| %8d| %10d| %5d| %6d| \n", time[2], ti[2][0], ti[2][1], ti[2][2], ti[2][3], ti[2][4], ti[2][5], ti[2][6],ti[2][7]);
            printf("|%9s| %8d| %1d| %1d| %1d| %8d| %10d| %5d| %6d| \n", time[3], ti[3][0], ti[3][1], ti[3][2], ti[3][3], ti[3][4], ti[3][5], ti[3][6],ti[3][7]);
            printf("-------------------------------------------------------------------\n\n");
            printf("Digite o numero de gols entre: %s vs %s\n\n",time[x],time[y]);
            printf("Digite o numero de gols do %s: ",time[x]);
            scanf ("%d",&gols[a][0]);
            printf("Digite o numero de gols do %s :",time[y]);
            scanf("%d",&gols[a][1]);
            t[0] = gols[0][0]+gols[1][0]+gols[2][0];
            t[1] = gols[0][1]+gols[3][0]+gols[4][0];
            t[2] = gols[1][1]+gols[3][1]+gols[5][0];
            t[3] = gols[2][1]+gols[4][1]+gols[5][1];
            for(int i=0; i < 5;i++) ti[i][4] = t[i];
            ti[x][5] = ti[x][5] + gols[a][1];
            ti[y][5] = ti[y][5] + gols[a][0];
            ti[x][0] = ti[x][0] + 1;
            ti[y][0] = ti[y][0] + 1;
                if (gols[a][0] > gols[a][1]){
                    ti[x][7] = ti[x][7] +3;
                    ti[x][1] = ti[x][1] +1;
                    ti[y][3] = ti[y][3] +1;
                }
                if (gols[a][0] < gols[a][1]){
                    ti[y][7] = ti[y][7] +3;
                    ti[x][3] = ti[x][3] +1;
                    ti[y][1] = ti[y][1] +1;
                }
                if (gols[a][0] == gols[a][1]){
                    ti[x][7] = ti[x][7] +1;
                    ti[y][7] = ti[y][7] +1;
                    ti[x][2] = ti[x][2] +1;
                    ti[y][2] = ti[y][2] +1;
                }
            for(int i=0; i < 5;i++)
                ti[i][6] = ti[i][4] - ti[i][5];
            system("cls");
            a++;
            }
        }
        for(int i = 0; i < 4;i++){
            if(ti[i][7])
                ponto_escolha[i] = ponto_escolha[i] +10000*ti[i][7];
            if(ti[i][1])
                ponto_escolha[i] = ponto_escolha[i] +100*ti[i][1];
            if(ti[i][4])
                ponto_escolha[i] = ponto_escolha[i] +1*ti[i][4];
        }
        for(int i = 0; i < 4;i++){
            pontos[i] = ponto_escolha[i];
        }
        int aux;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++)
                if(pontos[j]>pontos[j+1])
            {
                if(pontos[j] == pontos[j+1]){
                }else{
                aux = pontos[j];
                pontos[j] = pontos[j+1];
                pontos[j+1] = aux;
                }
            }
        }
    printf("\t\t***Quandrangular Final 2014***\n\n");
    printf("Tabela de classificacao:\n\n");
    printf("-------------------------------------------------------------------\n");
    printf("|%9s| %8s| %1s| %1s| %1s| %3s| %3s| %3s| %3s| \n", cabecalho[0].c_str(), cabecalho[1].c_str(), cabecalho[2].c_str(), cabecalho[3].c_str(), cabecalho[4].c_str(), cabecalho[5].c_str(), cabecalho[6].c_str(), cabecalho[7].c_str(),cabecalho[8].c_str());
    printf("|%9s| %8d| %1d| %1d| %1d| %8d| %10d| %5d| %6d| \n", time[0], ti[0][0], ti[0][1], ti[0][2], ti[0][3], ti[0][4], ti[0][5], ti[0][6],ti[0][7]);
    printf("|%9s| %8d| %1d| %1d| %1d| %8d| %10d| %5d| %6d| \n", time[1], ti[1][0], ti[1][1], ti[1][2], ti[1][3], ti[1][4], ti[1][5], ti[1][6],ti[1][7]);
    printf("|%9s| %8d| %1d| %1d| %1d| %8d| %10d| %5d| %6d| \n", time[2], ti[2][0], ti[2][1], ti[2][2], ti[2][3], ti[2][4], ti[2][5], ti[2][6],ti[2][7]);
    printf("|%9s| %8d| %1d| %1d| %1d| %8d| %10d| %5d| %6d| \n", time[3], ti[3][0], ti[3][1], ti[3][2], ti[3][3], ti[3][4], ti[3][5], ti[3][6],ti[3][7]);
    printf("-------------------------------------------------------------------\n\n");
    int r1=0,r2=0,r3=0;
    for(int i = 0; i < 4;i++){
        contador = 0;
        if(ponto_escolha[i] >= pontos[3]){
            ranque[0] = ranque[0]+ "1 Lugar "+ time[i] + "\n";
            contador = contador +1;
            r1++;
            continue;
        }
        if(r1 == 2 || (ponto_escolha[i] >= pontos[2])){
            ranque[1] = ranque[1]+ "2 Lugar "+ time[i]+ "\n";
            contador = contador +1;
            r2++;
        }
        if( (r2 == 2 || (ponto_escolha[i] >= pontos[1])) && contador ==0){
            ranque[2] = ranque[2]+ "3 Lugar "+ time[i]+ "\n";
            contador = contador +1;
            r3++;
            continue;
        }
        if( (r3 == 2 || (ponto_escolha[i] == pontos[0])) && contador ==0){
            ranque[3] = ranque[3]+ "4 Lugar "+ time[i]+ "\n";
            contador = contador +1;
            if ((pontos[1] == pontos[2]) && (pontos[0] != pontos[1])){
                ranque[3] = "";
                ranque[2] = ranque[2]+ "3 Lugar "+ time[i] + "\n";
            }
        }
    }
    for(int i = 0; i < 4;i++){
        printf("%s \n",ranque[i].c_str());
    }
    system("pause && scrnsave.scr /s%");
    system("cls");
    printf("\n\n\n\n\n\n\t By : Sir\n\n\n\n***** KISS FOR YOU: Keep it simple stupid!!! *****\n\n\n\n\n\n\n\n");
    return 0;
}

