//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define TAM 15

int main(void){
	
	int mat[TAM][TAM],num,i,j,temp=0,sumaFil=0,sumaCol=0,sumaDia1=0,sumaDia2=0;
	
	do{
		puts("Escribe el orden la matriz:");
		scanf("%d",&num);
	}while((num%1)!=0 | num>15);
	
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			mat[i][j]=-1;
		}
	}

	for(temp=1;temp<=(num*num);temp++){
		if(temp==1){
			i=0;
			j=(num/2);
			mat[i][j]=temp;
		}else{
			i--;
			if(i<0){
				i=num-1;
			}
			if(i==num){
				i=0;
			}
			if(j==num){
				j=0;
			}
			if(j<0){
				j=num-1;
			}
			j++;
			if(i<0){
				i=num-1;
			}
			if(i==num){
				i=0;
			}
			if(j==num){
				j=0;
			}
			if(j<0){
				j=num-1;
			}
			if(mat[i][j]!=-1){
				j--;
				if(i<0){
				i=num-1;
				}
				if(i==num){
					i=0;
				}
				if(j==num){
					j=0;
				}
				if(j<0){
					j=num-1;
				}
				i++;
				if(i<0){
				i=num-1;
				}
				if(i==num){
					i=0;
				}
				if(j==num){
					j=0;
				}
				if(j<0){
					j=num-1;
				}
				i++;
				if(i<0){
				i=num-1;
				}
				if(i==num){
					i=0;
				}
				if(j==num){
					j=0;
				}
				if(j<0){
					j=num-1;
				}
				
				mat[i][j]=temp;
			}else{
				mat[i][j]=temp;
			}	
		}	
		
	}
	
	
	temp=0;
//	Matriz
	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			printf("%d ",mat[i][j]);
		}
		puts("");
	}
//	Suma de filas
	for(i=0;i<num;i++){
		temp=0;
		for(j=0;j<num;j++){
			temp+=mat[i][j];
		}
		printf("Suma de la fila %d: %d\n",i+1,temp);
		sumaFil+=temp;
	}
	temp=0;
//	Suma de columnas
	for(j=0;i<num;i++){
		temp=0;
		for(i=0;j<num;j++){
			temp+=mat[i][j];
		}
		printf("Suma de la columna %d: %d\n",j+1,temp);
		sumaCol+=temp;
	}
	temp=0;
//	Suma de diagonal
	for(i=0;i<num;i++){
		for(j=i;j<num;j++){
			if(i==j){
			sumaDia1+=mat[i][j];
			}
			continue;
		}
	}
	printf("Suma de una diagonal: %d\n",sumaDia1);
//	Suma de diagonal
	for(i=num-1;i>=0;i--){
		for(j=i;j>=0;j--){
			if(i==j){
			sumaDia2+=mat[i][j];
			}
			continue;
		}
	}
	printf("Suma de la otra diagonal: %d\n",sumaDia2);

	puts("Es un cuadro m\240gico.");
	printf("El n\243mero m\240gico es el: %d\n\n",sumaDia2);
	system("pause");
	return 0;
}
