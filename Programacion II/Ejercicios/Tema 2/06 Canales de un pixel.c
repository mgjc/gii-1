#include <stdio.h>

typedef struct {
   unsigned bit0  : 1 ;
   unsigned bit1  : 1 ;
   unsigned bit2  : 1 ;
   unsigned bit3  : 1 ;
   unsigned bit4  : 1 ;
   unsigned bit5  : 1 ;
   unsigned bit6  : 1 ;
   unsigned bit7  : 1 ;
   unsigned bit8  : 1 ;
   unsigned bit9  : 1 ;
   unsigned bit10 : 1 ;
   unsigned bit11 : 1 ;
   unsigned bit12 : 1 ;
   unsigned bit13 : 1 ;
   unsigned bit14 : 1 ;
   unsigned bit15 : 1 ;
   unsigned bit16 : 1 ;
   unsigned bit17 : 1 ;
   unsigned bit18 : 1 ;
   unsigned bit19 : 1 ;
   unsigned bit20 : 1 ;
   unsigned bit21 : 1 ;
   unsigned bit22 : 1 ;
   unsigned bit23 : 1 ;
   unsigned bit24 : 1 ;
   unsigned bit25 : 1 ;
   unsigned bit26 : 1 ;
   unsigned bit27 : 1 ;
   unsigned bit28 : 1 ;
   unsigned bit29 : 1 ;
   unsigned bit30 : 1 ;
   unsigned bit31 : 1 ;
} TreintaydosBits;

typedef union {
   long n;
   TreintaydosBits b;
} CuatroBytes;

void ImprimeBitsdePixel (long);

int main (void) {

   CuatroBytes pixel;

   pixel.n = 0;

   puts("Todos los bits del pixel puestos a 0");
   ImprimeBitsdePixel(pixel.n);
   puts("");

   puts("Poner a 1 el bit menos significativo del canal Alfa (bit 24)");
	pixel.b.bit24=1;
   ImprimeBitsdePixel(pixel.n);
   puts("");

   puts("Poner todo el canal Azul a 1");
	pixel.b.bit0=1;
	pixel.b.bit1=1;
	pixel.b.bit2=1;
	pixel.b.bit3=1;
	pixel.b.bit4=1;
	pixel.b.bit5=1;
	pixel.b.bit6=1;
	pixel.b.bit7=1;
   ImprimeBitsdePixel(pixel.n);
   puts("");

   puts("Poner bit mas significativo canal Azul a 0 (bit 7)");
   pixel.b.bit7=0;
   ImprimeBitsdePixel(pixel.n);
   puts("");
    
	printf("Cuarto bit del canal Verde: %d",pixel.b.bit11);
   printf("\nQuinto bit del canal Azul: %d\n",pixel.b.bit4);

	return 0;
}

void ImprimeBitsdePixel (long nump) {

   CuatroBytes ff;

	ff.n=nump;

	printf("%d",ff.b.bit31);
	printf("%d",ff.b.bit30);
	printf("%d",ff.b.bit29);
	printf("%d",ff.b.bit28);
	printf("%d",ff.b.bit27);
	printf("%d",ff.b.bit26);
	printf("%d",ff.b.bit25);
	printf("%d",ff.b.bit24);
	printf("%d",ff.b.bit23);
	printf("%d",ff.b.bit22);
	printf("%d",ff.b.bit21);
	printf("%d",ff.b.bit20);
	printf("%d",ff.b.bit19);
	printf("%d",ff.b.bit18);
	printf("%d",ff.b.bit17);
	printf("%d",ff.b.bit16);
	printf("%d",ff.b.bit15);
	printf("%d",ff.b.bit14);
	printf("%d",ff.b.bit13);
	printf("%d",ff.b.bit12);
	printf("%d",ff.b.bit11);
	printf("%d",ff.b.bit10);
	printf("%d",ff.b.bit9);
	printf("%d",ff.b.bit8);
	printf("%d",ff.b.bit7);
	printf("%d",ff.b.bit6);
	printf("%d",ff.b.bit5);
	printf("%d",ff.b.bit4);
	printf("%d",ff.b.bit3);
	printf("%d",ff.b.bit2);
	printf("%d",ff.b.bit1);
	printf("%d",ff.b.bit0);

}
