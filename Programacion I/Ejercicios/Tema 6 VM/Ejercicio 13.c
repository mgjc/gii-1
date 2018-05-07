//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define FIL 4
#define COL 5
int main (void){
	int mat[FIL][COL]={11,12,13,14,15,21,22,23,24,25,31,32,33,34,35,41,42,43,44,45};
	int i,j;
	puts("Original:");
	for(i=0;i<FIL;i++){
		for(j=0;j<COL;j++){
			printf("%d ",mat[i][j]);
		}
		puts("");
	}
	puts("Descendente por filas, ascendente por columnas");
	for(i=FIL-1;i>=0;i--){
		for(j=0;j<COL;j++){
			printf("%d ",mat[i][j]);
		}
		puts("");
	}
	puts("Descendente por columnas, descendente por filas");
	for(i=COL-1;i>=0;i--){
		for(j=FIL-1;j>=0;j--){
			printf("%d ",mat[j][i]);
		}
		puts("");
	}
	puts("Ascendentre por columnas, ascendente por filas");
	for(i=0;i<COL;i++){
		for(j=0;j<FIL;j++){
			printf("%d ",mat[j][i]);
		}
		puts("");
	}
	
	
	
	
	system("pause");
	return 0;
}
