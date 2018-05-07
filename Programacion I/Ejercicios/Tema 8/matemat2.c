//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#include "matemat2.h"

int main(void){
	int x,y,temp; long prim; double grad,temp1;
	do{
		puts("Escribe un numero");
		scanf("%d",&x);
	}while(x<=0);
	do{
		puts("Escribe un numero superior al anterior");
		scanf("%d",&y);
	}while(y<=x);
	temp=numeroaleatorio(x,y);
	printf("El numero aleatorio es: %d",temp); puts("");
	puts("Escribe los grados a convertir:");
	scanf("%d",&grad);
	temp1=abs(grad);
	temp1=radianes(temp1);
	printf("Tu numero en radianes: %lf",temp1);puts("");
	do{
		puts("Escribe un numero para saber si es primo o no");
		scanf("%ld",&prim);
	}while(prim<=0);
	temp=primo(prim);
	if(temp==0)puts("El numero no es primo");
	else puts("El numero es primo");
	system("pause");
	return 0;
}
