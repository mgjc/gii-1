//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define FIL 100
#define COL 100
void CargarMatriz(int *,int,int,int);
void VerMatriz(int *,int,int);
int ExtraeColumnaMaximo(int*,int,int,int*);
void VerColumna(int*,int);
int main (void){
	
	int mat[FIL][COL],vec[FIL],numc,numf,numero;
	
	do{
		puts("Cuantas filas vas a usar?");
		scanf("%d",&numf);
	}while(numf<0||numf>FIL);
	do{
		puts("Cuantas columnas vas a usar?");
		scanf("%d",&numc);
	}while(numc<0||numc>COL);
	do{
		puts("Escribe un numero entero:");
		scanf("%d",&numero);
	}while(numf<1||numf>FIL*COL);
	CargarMatriz(&mat,numf,numc,numero);
	VerMatriz(mat,numf,numc);
	ExtraeColumnaMaximo(mat,numf,numc,vec);
	VerColumna(vec,numf);
	system("pause");
	return 0;
}
void CargarMatriz(int *matrizA,int nfil,int ncol,int num){
	int temp=3,i;
	for(i=0;i<nfil*ncol;i++){
		if(i==0){
			*(matrizA)=num;
			continue;
		}
		*(matrizA+i)=*(matrizA+i-1)+temp;
		if(temp<0)
			temp=temp-1;
		else
			temp=temp+1;
		temp*=-1;
	}
}
void VerMatriz(int *matrizA,int nfil,int ncol){
	int i;
	for(i=0;i<nfil*ncol;i++){
		printf("%d\t",*(matrizA+i));
		if(i&&((i+1)%ncol)==0)puts("");
	}
}
int ExtraeColumnaMaximo(int *matrizA,int nfil,int ncol, int *VectorX){
	int i,j=0,temp=*matrizA,temp1=0;
	if(matrizA==NULL||VectorX==NULL)return -1;
	for(i=0;i<(nfil*ncol)-1;i++){
		if(*(matrizA+i+1)>temp){
			temp=*(matrizA+i+1);
			temp1=(i%ncol)+1;
		}
	}
	printf("El maximo es %d y esta en la columna %d\n",temp,temp1+1);
	for(i=0;i<nfil*ncol;i++){
		if(j==temp1)*(VectorX++)=*(matrizA+i);
		j++;
		if(j==ncol)j=0;
	}
	
	return 0;
}
void VerColumna(int *VectorX,int dim){
	int i;
	for(i=0;i<dim;i++)
		printf("%d\n",*(VectorX+i));
}
