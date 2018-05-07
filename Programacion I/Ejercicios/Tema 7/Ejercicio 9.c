//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define FIL 3
#define COL 4
#define TAM 10

int main (void){


	char vletras[TAM]={'A','F','H','K','L','O','S','U','X','Z'};
	char mat[FIL][COL], *mapa[FIL][COL];
	int i,j,k=0,comp[FIL][COL]={0};

	for(i=0;i<FIL;i++){
		for(j=0;j<COL;j++){
			printf("Escribe car\240cter [%d][%d]:\n",i+1,j+1);
			mat[i][j]=getchar();
			fflush(stdin);
		}
	}

	for(i=0;i<FIL;i++){
		for(j=0;j<COL;j++){
			mat[i][j]=toupper(mat[i][j]);
		}
	}
	
	for(k=0;k<TAM;k++){
		for(i=0;i<FIL;i++){
			for(j=0;j<COL;j++){
				if(comp[i][j]==0){
					if(mat[i][j]==vletras[k]){
						mapa[i][j]=&vletras[k];
						comp[i][j]=1;
					}else{
						mapa[i][j]= NULL;
					}
				}
			}
		}
	}
	puts("");
	for(i=0;i<FIL;i++){
		for(j=0;j<COL;j++){
			if(mapa[i][j]==NULL){
				printf("* ");
			}else{
				printf("%c ",*mapa[i][j]);
			}
		}
		puts("");
	}
	puts("");
	system("pause");
	return 0;
}
