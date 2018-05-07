//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
	
	const char blanc=' ';
	char caract;
	int alt, i, j;
	
	printf("Escribe un car\240cter y un n\243mero:\n");
	scanf("%c",&caract); scanf("%d",&alt);
	
	for(i=1;i<=alt;i++){
		
		for(j=1;j<=alt-i;j++){
			printf("%c",blanc);
		}
		for(j=1;j<=i;j++){
			printf("%c",caract);
		}

	puts("");
	}
	for(i=1;i<=alt-1;i++){
		
		for(j=1;j<=i;j++){
			printf("%c",blanc);
		}
		for(j=1;j<=alt-i;j++){
			printf("%c",caract);
		}
	puts("");
	}
	puts("");
	
	system("pause");
	return 0;
}
