//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define DIM 7
#define FIL 3
#define COL 4

int main (void){
	
	int vector[DIM]={25,40,55,70,85,100,115}, tabla[FIL][COL]={15,25,35,45,115,125,135,145,215,225,235,245};
	int i,j, *punt1,*punt2;
	punt1=&vector;
	punt2=&tabla;
	
	for(i=0;i<DIM;i++){
		printf("%d ",vector[i]);
	}
	puts("");
	
	for(i=0;i<DIM;i++){
		printf("%d ",*(vector+i));
	}
	puts("");
	
	for(i=0;i<DIM;i++){
		printf("%d ",*punt1++);
	}
	puts("");
	puts("");
	
	for(i=0;i<FIL;i++){
		for(j=0;j<COL;j++){
			printf("%d ",tabla[i][j]);
		}
		puts("");
	}
	puts("");
	
	for(i=0;i<FIL;i++){
		for(j=0;j<COL;j++){
			printf("%d ",*(*(tabla+i)+j));
		}
		puts("");
	}
	puts("");
	
	for(i=0;i<FIL;i++){
		for(j=0;j<COL;j++){
			printf("%d ",*punt2++);
		}
		puts("");
	}
	puts("");
	
	system("pause");
	return 0;
}
