//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int num,num1=1,num2=0,temp=0;
	puts("Sucesi\242n de Fibonacci.");
	puts("Introduce el n\243mero de t\202rminos a representar.");
	printf("(Entre 1 y 50)==> ");scanf("%d",&num);
	puts("");
	if(num>0&&num<51){
		while(num>0){
			printf("%d ",num1);
			num1=num1+num2;
			num2=num1-num2;
			num--;
		}	
	}else{
		puts("El n\242mero no est\240 en el rango");
	}
	puts("");
	system("pause");
	return 0;
}
