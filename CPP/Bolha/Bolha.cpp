//+_+_+_+_+_+_+__+__+__+__+__+_+_
//_+__+_By: "Sir" Arthur_+__+__+_
//+_+_+_+_+_+_+__+__+__+__+__+_+_

#include <iostream>
#include <stdlib.h>
using namespace std;
int main ()
{
	int vet[10],i,j,aux;
	for(i=0; i < 10; i++)
	{
		cout << "\nDigite o " << (i+1) << "elemento do vetor: ";
		cin >> vet[i];
	}
	for(i = 0; i < 9; i ++)
		{
			for(j = i; j < 9; j++)
			{
				if(vet[i] < vet[j+1])
				{
					aux = vet[i];
					vet[i] = vet[j+1];
					vet[j+1] = aux;
				}
			}
		}
	cout << "\nVetor ordenado de forma decrescente";
	for(i = 0; i < 10; i++)
	{
		cout << "\n" << vet[i];
		cout << "\n";
	}
return 0;
}
