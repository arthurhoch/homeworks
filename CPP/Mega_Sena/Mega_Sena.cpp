//+_+_+_+_+_+_+__+__+__+__+__+_+_
//_+__+_By: "Sir" Arthur_+__+__+_
//+_+_+_+_+_+_+__+__+__+__+__+_+_

#include <stdio.h>
int main()
{
	int l[6];
	int id[2];
	int n_usuario[2][6];
	int acertos[2];
	acertos[0] = 0;
	acertos[1] = 0;
	for(int i=0;i<6;i++){
		//Le os numeros sorteados
		printf("Digite o numero %d sorteado : ",i+1);
		scanf("%d",&l[i]);
	}
	for(int i=0;i<2;i++) {
		//Le o id do usuario
		printf("Digite seu id %d: ",i+1);
		scanf("%d",&id[i]);
		for(int j=0;j<6;j++){
			//Le os numeros dos usuarios
			printf("Digite seu %d numero : ",i+1);
			scanf("%d",&n_usuario[i][j]);
		}
	}

	for(int i=0;i<2;i++) {
		for(int j=0;j<6;j++){
			for(int x=0;x<6;x++){
				if(l[j] == n_usuario[i][x]){
					acertos[i] = acertos[i] + 1;
				}
            		}
                	if(j == 5)
				printf("\nO numero de acetos do usuario %d foi de: %d\n\n",id[i],acertos[i]);
		}
	}
	return 0;
	
}
