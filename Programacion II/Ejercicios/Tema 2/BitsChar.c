#include <stdio.h>
#define MAX 30

typedef struct{

	unsigned a:1;
	unsigned b:1;
	unsigned c:1;
	unsigned d:1;
	unsigned e:1;
	unsigned f:1;
	unsigned g:1;
	unsigned h:1;

} Octeto;

typedef union{

	char car;
	Octeto bit;

}Bits;

void VisualizarBits(Bits);

int main (void){

	char cadena[MAX];
	int i=0;
	Bits codigo;

	fgets(cadena,MAX,stdin);
	puts("");
	while(cadena[i]!='\0'){

		printf("%c: ",cadena[i]);
		codigo.car=*(cadena+i);
		VisualizarBits(codigo);
		puts("");
		i++;
	}
	puts("");

	return 0;
}

void VisualizarBits(Bits x){

	printf("%d%d%d%d%d%d%d%d",x.bit.h,x.bit.g,x.bit.f,x.bit.e,x.bit.d,x.bit.c,x.bit.b,x.bit.a);

}
