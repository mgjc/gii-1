//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define TAM 100

int main (void){
	
	int vect[TAM]; int temp,num,i;
	
	do{
		puts("Escribe el n\243mero efectivo de elementos del vector");
		scanf("%d",&num);
	}while(num<=0||num>TAM);
	
	for(i=0;i<num;i++){
		puts("Escribe un elemento");
		scanf("%d",&vect[i]);
	}
	for(i=0;i<num-i;i++){
		temp=vect[num-1-i];
		vect[num-1-i]=vect[i];
		vect[i]=temp;
	}
	puts("");
	for(i=0;i<num;i++){
		printf("%d ",vect[i]);
	}
	
	system("pause");
	return 0;
}
