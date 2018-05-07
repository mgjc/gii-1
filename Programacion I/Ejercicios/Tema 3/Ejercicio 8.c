//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int num, temp;
	
	printf("Escribe un n\243mero de 4 cifras\n");
	scanf("%d",&num);
	
	if((num/10000)==0){
		
		system("cls");
		
		printf("N\243mero introducido....: %d\n\n",num);
		
		temp=num/1000;
		num-=temp*1000;
		
		printf("Unidades de millar.......: %d\n\n",temp);
		
		temp=num/100;
		num-=temp*100;
		
		printf("Centenas.................: %d\n\n",temp);
		
		temp=num/10;
		num-=temp*10;
		
		printf("Decenas..................: %d\n\n",temp);
		printf("Unidades.................: %d\n\n",num);
		
	}else{
		printf("El n\243mero introducido tiene m\240s de 4 cifras.\n");
	}
	
	
	system("pause");
	return 0;
}
