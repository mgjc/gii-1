//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
	
	const char blanc=' ';
	char caract, ext;
	int alt, i, j, l;
	
	puts("Escribe un car\240cter interior");scanf("%c",&caract); fflush(stdin);
	puts("Escribe un car\240cter exterior");scanf("%c",&ext);

	printf("Escribe un n\243mero para la altura\n");
	scanf("%d",&alt);
	
	for(i=1;i<=alt;i++){
		
		for(j=1;j<=alt-i;j++){
			printf("%c",blanc);
		}
		for(j=1;j<=i;j++){
			printf("%c%c",caract,caract);
		}

	puts("");
	}
	for(i=1;i<=alt-1;i++){
		
		for(j=1;j<=i;j++){
			printf("%c",blanc);
		}
		for(j=1;j<=alt-i;j++){
			printf("%c%c",caract,caract);
		}
		
	puts("");
	
	}
	
	puts("");
	for(i=1;i<=alt;i++){
	
		for(j=1;j<=alt-i;j++){
			printf("%c",ext);
		}
		for(j=1;j<=i;j++){
			printf("%c%c",blanc,blanc);
		}
		for(l=alt;l<=(2*alt)-j;l++){
			printf("%c",ext);
		}
		puts("");
		}
		
	for(i=1;i<=alt-1;i++){
		
		for(j=1;j<=i;j++){
			printf("%c",ext);
		}
		for(j=1;j<=alt-i;j++){
			printf("%c%c",blanc,blanc);
		}
		for(l=alt;l<=(2*alt)-j;l++){
			printf("%c",ext);
		}
		puts("");
	}
	
	puts("");
	
	for(i=1;i<=alt;i++){
		
		for(j=1;j<=alt-i;j++){
			printf("%c",ext);
		}
		for(j=1;j<=i;j++){
			printf("%c%c",caract,caract);
		}
		for(l=alt;l<=(2*alt)-j;l++){
			printf("%c",ext);
		}
	puts("");
	}
		
	for(i=1;i<=alt-1;i++){
		
		for(j=1;j<=i;j++){
			printf("%c",ext);
		}
		for(j=1;j<=alt-i;j++){
			printf("%c%c",caract,caract);
		}
		for(l=alt;l<=(2*alt)-j;l++){
			printf("%c",ext);
		}
		puts("");
	}
	
	puts("");

	
	system("pause");
	return 0;
}
