//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int suma(int);

int main(void){
	int num,sum;
	char esc;
	do{
		do{
			puts("Escribe la cantidad de n\243meros enteros que quieres sumar");
			scanf("%d",&num);
		}while(num<0);
	fflush(stdin);
	sum=suma(num); 
	printf("El resultado es: %d\n",sum);
	puts("Quieres hacer otra suma? (s/n)");
	scanf("%c",&esc);
	fflush(stdin);
	}while(esc=='s'||esc=='S');
	
	system("pause");
	return 0;
}

int suma(x){
	int y=0,i;
	for(i=1;i<=x;i++){
		y+=i;
	}
	
	return y;
}
