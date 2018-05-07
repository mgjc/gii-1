//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define CAMBIO 166.386

int main (void){
	
	int pes500, pes200, pes100, pes50, pes25, pes10, pes5, pes1, totalpes, eur50, eur20, eur10, eur5;
	double suma, temp;
	const char present[]="MAQUINA DE CAMBIO DE MONEDAS DE PESETAS",guiones[]="---------------------------------", barra []="=======================================";
	puts(present); puts(barra);puts("Numero de monedas de PESETAS a CAMBIAR");puts(guiones);
	printf("Monedas de 500 pesetas?: "); scanf("%d",&pes500);
	printf("\nMonedas de 200 pesetas?: ");scanf("%d",&pes200);
	printf("\nMonedas de 100 pesetas?: ");scanf("%d",&pes100);
	printf("\nMonedas de 50 pesetas?: "); scanf("%d",&pes50);
	printf("\nMonedas de 25 pesetas?: ");scanf("%d",&pes25);
	printf("\nMonedas de 10 pesetas?: ");scanf("%d",&pes10);
	printf("\nMonedas de 5 pesetas?: "); scanf("%d",&pes5);
	printf("\nMonedas de 1 peseta?: "); scanf("%d",&pes1); puts("");
	totalpes=(pes500*500)+(pes200*200)+(pes100*100)+(pes50*50)+(pes25*25)+(pes10*10)+(pes5*5)+pes1; suma=totalpes/CAMBIO;
	printf("Importe total en PESETAS a cambiar: %d pesetas\n",totalpes);printf("Importe total en EUROS a entregar: %.2lf euros\n", suma);
	puts("Numero de billetes de EUROS A ENTREGAR"); puts(guiones);
	eur50=suma/50; temp=(int)suma%50;
	eur20=temp/20; temp=(int)temp%20;
	eur10=temp/10; temp=(int)temp%10;
	eur5=temp/5; temp=suma-((eur50*50)+(eur20*20)+(eur10*10)+(eur5*5));
	printf("Billetes de 50 euros: %d\n",eur50); printf("Billetes de 20 euros: %d\n",eur20);
	printf("Billetes de 10 euros: %d\n",eur10); printf("Billetes de 5 euros: %d\n",eur5);
	printf("Importe en euros que no puede dispensarse en billetes: %.2lf euros\n",temp);
	
	system("pause");
	return 0;
}
