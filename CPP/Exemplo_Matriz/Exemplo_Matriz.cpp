//+_+_+_+_+_+_+__+__+__+__+__+_+_
//_+__+_By: "Sir" Arthur_+__+__+_
//+_+_+_+_+_+_+__+__+__+__+__+_+_

#include <stdio.h>
int main()
{
	int m[5][5] = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
		for(int i=0 ; i<5; i++){
			printf("\n\n\n\n");
			for(int j=0 ; j<5; j++)
				printf ("[%d][%d]\t",i,j);
			}
		printf("\n\n\n\n");
		for(int i=0 ; i<5; i++){
			printf("\n");;
			for(int j=0 ; j<5; j++)
				printf ("%5d\t",m[i][j]);
			}
		printf("\n\n");
}
