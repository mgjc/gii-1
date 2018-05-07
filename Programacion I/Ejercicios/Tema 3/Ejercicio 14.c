//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int fecha, temp, a, b, c, d, e, f, suma, tarot;
	
	printf("Escribe tu cumplea\244os en el siguiente formato AAAAMMDD\n");
	scanf("%d",&fecha);
	
	a=fecha/1000000;
	temp=fecha%1000000;
	b=temp/100000;
	temp%=100000;
	c=temp/10000;
	temp%=10000;
	d=temp/1000;
	temp%=1000;
	e=temp/100;
	temp%=100;
	f=temp/10;
	temp%=10;
	
	suma= a+b+c+d+e+f+temp;
	
	while(suma>9){
		temp=suma%10;
		temp=temp+(suma/10);
		suma=temp;
	}
	tarot=suma;
	printf("Tu n\243mero del Tarot es el: %d\n",tarot);
	
	system("pause");
	return 0;
}
