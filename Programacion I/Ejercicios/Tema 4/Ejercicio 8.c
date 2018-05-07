//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
	char barras []="========================================", name [40], calcu []="CALCULO DE FACTURA HOSPITALARIA", fact []="FACTURA HOSPITALARIA";
	int dia, mes, ano, diasIngresado, diasFacturados, temp;
	double totalAPagar, costeDiarioTotal, costeTotal, totalReturn, costeDiario, costeConsulta, costeMedicina, costeDiverso, deducSeguro, deducMedicina, deducTotal;
	
	puts(barras); puts(calcu); puts(barras); puts("DATOS DEL PACIENTE");
	printf("Nombre: "); gets(name); puts("Fecha de ingreso"); 
	printf("D\241a: "); scanf("%d",&dia); printf("Mes: "); scanf("%d",&mes); printf("A\244o: "); scanf("%d",&ano);
	printf("N\243mero de d\241as ingresado: "); scanf("%d",&diasIngresado); puts("COSTES");
	printf("Coste por d\241a...........: "); scanf("%lf",&costeDiario); printf("Coste consultas.........: "); scanf("%lf",&costeConsulta);
	printf("Coste medicamentos......: "); scanf("%lf",&costeMedicina); printf("Costes diversos.........: "); scanf("%lf",&costeDiverso);
	puts("DEDUCCIONES");
	printf("Deducci\242n diaria del Seguro................: "); scanf("%lf",&deducSeguro);
	printf("Porcentaje deducci\242n ayuda medicamentos....: "); scanf("%lf",&deducMedicina);
	
	system("cls"); puts(barras); puts(fact); puts(barras);
	
	diasFacturados=diasIngresado-(diasIngresado/4);
	costeDiarioTotal=costeDiario*diasFacturados;
	costeTotal=costeDiarioTotal+costeConsulta+costeDiverso+costeMedicina;
	deducMedicina=(costeMedicina>90)?(costeMedicina*(deducMedicina/100)):(0);
	deducSeguro=(diasIngresado>2)?((diasIngresado-2)*deducSeguro):(0);
	deducTotal=deducMedicina+deducSeguro;
	totalAPagar=costeTotal-deducTotal;
	totalAPagar=(totalAPagar<=0)?(0):(totalAPagar);
	temp=(diasIngresado>2)?(diasIngresado-2):(0);
	
	printf("PACIENTE....................: ");puts(name); printf("INGRESO.....................: %d/%d/%d\n", dia, mes, ano);
	printf("DIAS INGRESADO..............: %d\n", diasIngresado); printf("DIAS FACTURADOS.............: %d\n", diasFacturados);
	printf("COSTE TOTAL DIAS ESTANCIA...: %.2lf\n", costeDiarioTotal); printf("COSTE TOTAL.................: %.2lf\n", costeTotal);
	printf("DIAS DEDUCCION SEGURO.......: %d\n", temp); printf("DEDUCCION SEGURO............:-%.2lf\n", deducSeguro);
	printf("DEDUCCION POR MEDICAMENTOS..:-%.2lf\n", deducMedicina); printf("DEDUCCION TOTAL.............:-%.2lf\n", deducTotal);
	printf("TOTAL A PAGAR...............: %.2lf\n", totalAPagar);
	
	system("pause");
	return 0;
}
