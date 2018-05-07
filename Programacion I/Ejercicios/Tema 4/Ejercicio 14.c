//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

int main (void){
	const char barra[]="======================================", calc []="		CALCULO DE AREAS", rect[]="a) De un rect\240ngulo", tri[]="b) De un tri\240ngulo", circ[]="c) De un c\241rculo", trap[]="d) De un trapecio", salir[]="s) Salir.";
	double area, x, y, z; char a;
	
		puts(barra);puts(calc);puts(barra);
		puts(rect); puts(tri);puts(circ);puts(trap); puts(salir);
		scanf("%c",&a);
		switch(a){
			case 'a':
				printf("Base? Altura?\n"); scanf("%lf",&x); scanf("%lf",&y);
				area=x*y;
				break;
			case 'b':
				printf("Base? Altura?\n"); scanf("%lf",&x); scanf("%lf",&y);
				area=(x*y)/2;
				break;
			case 'c':
				printf("Radio?\n"); scanf("%lf",&x);
				area=PI*x*x;
				break;
			case 'd':
				printf("Altura? Lado A? Lado B?\n"); scanf("%lf",&x); scanf("%lf",&y); scanf("%lf",&z);
				area=((y+z)*x)/2;
				break;
			case 's':
				break;
			
		}
	printf("%lg",area);
	puts("");
	
	system("pause");
	return 0;
}
