#include <stdio.h>
#include <stdlib.h>
#define TAM 100

double vect [TAM]={0};double temp, suma=0; int num, i, j=0;
int main(void){
	
	do{
		puts("Numero efectivo?");
		scanf("%d",&num);
	}while(num<=0||num>TAM);
	
	for(i=0;i<num;i++){
		puts("Escribe un elemento:");
		scanf("%lf",&vect[i]);
		suma+=vect[i];
	}
	printf("suma: %lf", suma);
	
	do{
		for(i=0;i<num-1;i++){
			if(vect[i]>vect[i+1]){
				temp=vect[i+1];
				vect[i+1]=vect[i];
				vect[i]=temp;
			}
		}
		j++;
	}while(j<num);
	puts("");
	for(i=0;i<num;i++){
		printf("%lf ",vect[i]);
	}
	puts("");
	system("pause");
	return 0;
}
