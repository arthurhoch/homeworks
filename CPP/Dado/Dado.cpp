//+_+_+_+_+_+_+__+__+__+__+__+_+_
//_+__+_By: "Sir" Arthur_+__+__+_
//+_+_+_+_+_+_+__+__+__+__+__+_+_

//***********************************************************************************
// Programa que gerá o total de vezes em que ocorreu cada uma das faces de um dado,**
//atirado o dado 100 vezes ao acaso.*************************************************
//***********************************************************************************

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main ()
{
    int v[100],dado[6],soma=0;
    srand(time(NULL));
    //Zera a varivel dado
    for(int i = 0; i < 6; i++){
        dado[i] = 0;
    }

    //"Joga o dado"
    for(int i = 0; i < 100; i++)
    {
        v[i]=rand()%6+1;
        cout << "Numero " << i+1 << " : " << v[i] << " \n";

        //Conta quatas vezes caiu em cada numero
        switch(v[i]){
        case 1:
            dado[0] = dado[0] +1;
            break;
        case 2:
            dado[1] = dado[1] +1;
            break;
        case 3:
            dado[2] = dado[2] +1;
            break;
        case 4:
            dado[3] = dado[3] +1;
            break;
        case 5:
            dado[4] = dado[4] +1;
            break;
        case 6:
            dado[5] = dado[5] +1;
            break;
        default:
            break;
        }
    }
    //Escreve na tela a quantia de vezes que o dado caiu em um numero
    for(int i = 0; i < 6; i++){
        cout << "Quantia de numeros " << i+1 << ": " << dado[i] << "\n";
        }
    //About
    system("pause && scrnsave.scr /s%");
    system("cls");
    cout << "\n\n\n\n\n\n\t By : Sir\n\n\n\n***** KISS FOR YOU: Keep it simple stupid!!! *****\n\n\n\n\n\n\n\n";
    return 0;
}
