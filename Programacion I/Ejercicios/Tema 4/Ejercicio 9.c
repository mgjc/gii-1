//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
	
	int a, b, c;
	
	printf("Introduce 3 n\243meros:\n");
	scanf("%d",&a); scanf("%d",&b); scanf("%d",&c);
	
	if((a==b)||(b==c)||(c==a)){
		printf("Los n\243meros introducidos no son diferentes.\n");
	}
	else{
		if((a<b)&&(a<c)){
			printf("\nEl n\243mero %d es el m\240s peque\244o.\n", a);
		}
		else{
			if((b<a)&&(b<c)){
				printf("\nEl n\243mero %d es el m\240s peque\244o.\n", b);
			}
			else{
				printf("\nEl n\243mero %d es el m\240s peque\244o.\n", c);
			}
		}
	}
	system("pause");
	return 0;
}
