//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main (void){
	int num, ramd, x, temp, i=0;
	srand(time(NULL));
	ramd=rand()%1001;
	puts("Introduce un numero");
	do{
	
	printf("%d intento:\n",++i);
	scanf("%d",&num);
	system("cls");
	if(num<0)break;
	x=abs(num-ramd);
	if(x<=100){
		temp=2;
		if(x<=10){
			temp=3;
			if(x<=5){
				temp=4;
			}
		}
	}else{
		temp=1;
	}
	
	switch(temp){
		case 1:
			puts("Muy frio");
			break;
		case 2:
			puts("Frio");
			break;
		case 3:
			puts("Caliente");
			break;
		case 4:
			puts("Muy caliente");
			break;
	}
	if(num!=ramd){printf("Numero anterior: %d\n",num);(num<ramd)?printf("Mi numero es mayor, "):printf("Mi numero es menor, ");}
	
	}while(num!=ramd);
	system("cls");
	(num<0)?printf("Abandonas con %d intentos, el numero era %d\n\n",i,ramd):printf("Has acertado en %d intentos!\n\n",i);
	
	system("pause");
	return 0;
}
