//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int fact=1, n, i;
	printf("Escribe un n\243mero para calcular su factorial:\n"); scanf("%d",&n);
	system("cls");printf("Factorial con for:\n");
	for(i=n;i>1;i--){
		fact*=i;
	}
	printf("%d",fact);puts("");
	fact=1;i=n; printf("Factorial con while:\n");
	while(i>1){
		fact*=i;
		i--;
	}
	printf("%d",fact); puts("");
	fact=1; i=n; printf("Factorial con do-while:\n");
	do{
		fact*=i;
		i--;
	}while(i>1);
	printf("%d",fact);puts("");
	system("pause");
	return 0;
}
