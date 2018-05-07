#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	float *v;
	int dimv;
}vectC;

typedef struct{
	float **m;
	int numRows, numCols;
}matF;

matF *CrearMatriz(int,int);
vectC *ExtraeColumna(matF,int);
void VerMatriz(matF*);
void VerVector(vectC*);
void LiberaMatriz(matF*);
void LiberaVector(vectC*);

int main (void){

	matF *mat;
	vectC *vec;

	int fil,col,x;

	do{
		puts("Introduce las filas");
		scanf("%d",&fil);
	}while(fil<1);
	do{
		puts("Introduce las columnas");
		scanf("%d",&col);
	}while(col<1);

	mat=CrearMatriz(fil,col);
	do{
		puts("Que columna quieres ver?");
		scanf("%d",&x);
	}while(x<1||x>col);
	vec=ExtraeColumna(*mat,x-1);
	vec->dimv=col;
	VerMatriz(mat);
	puts("");
	VerVector(vec);
	LiberaMatriz(mat);
	LiberaVector(vec);

	return 0;
}

matF *CrearMatriz(int nfil, int ncol){

	matF *x;
	int i,j;

	srand(time(NULL));
	if((x=malloc(sizeof(matF)))==NULL){free(x);exit(-1);}

	if((x->m=calloc(nfil,sizeof(float)))==NULL){free(x->m);exit(-1);}

	x->numRows=nfil;
	x->numCols=ncol;

	for(i=0;i<nfil;i++)
		if((x->m[i]=calloc(ncol,sizeof(float)))==NULL){
			for(i=0;i<nfil;i++) free(x->m[i]);
			exit(-1);}

	for(i=0;i<nfil;i++){
		for(j=0;j<ncol;j++){
			x->m[i][j]=rand()%10+1;
		}
	}

	return x;
}

vectC *ExtraeColumna(matF m,int ncol){

	vectC *x;
	int i;

	if((x=malloc(sizeof(vectC)))==NULL){exit (-1);}
	if((x->v=calloc(m.numRows,sizeof(float)))==NULL){
		exit (-1);
	}

	x->dimv=m.numRows;

	for(i=0;i<x->dimv;i++){
		x->v[i]=m.m[i][ncol];
	}

	return x;
}

void VerMatriz (matF *x){

	int i,j;

	for(i=0;i<x->numRows;i++){
		for(j=0;j<x->numCols;j++){
			printf("%.2f  ",x->m[i][j]);
		}
		puts("");
	}


}
void VerVector(vectC *x){

	int i;

	for(i=0;i<x->dimv;i++)printf("%.2f\n",x->v[i]);

}
void LiberaMatriz(matF *x){

	free(x);
}
void LiberaVector(vectC *x){
	free(x);
}
