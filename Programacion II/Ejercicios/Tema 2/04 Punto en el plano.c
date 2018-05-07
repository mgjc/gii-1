#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { float x, y; } Punto;

typedef enum {
  CUADRADO,
  RECTANGULO,
  PUNTO,
  LINEA_VERTICAL,
  LINEA_HORIZONTAL
} Figura;

void LeerPunto(Punto *);
void EscribirPunto(Punto, Punto);
float DistanciaPuntos(Punto, Punto);
Punto PuntoMedio(Punto, Punto);
Figura FiguraDefinenPuntos(Punto, Punto);
float AreaFiguraPuntos(Punto, Punto);

int main(void) {

  Punto x1, x2, m;
  float area;

  LeerPunto(&x1);
  LeerPunto(&x2);
  EscribirPunto(x1, x2);
  m = PuntoMedio(x1, x2);
  printf("El punto medio entre el punto (%.2f,%.2f) y el punto (%.2f,%.2f) es "
         "el punto (%.2f,%.2f)\n",
         x1.x, x1.y, x2.x, x2.y, m.x, m.y);
  area = AreaFiguraPuntos(x1, x2);
  if (area == 0)
    puts("No tiene area");
  else
    printf("El area es: %.2f\n", area);
  return 0;
}

void LeerPunto(Punto *p) {

  printf("Escribe las coordenadas en X de tu punto: ");
  scanf("%f", &p->x);
  printf("Escribe las coordenadas en Y de tu punto: ");
  scanf("%f", &p->y);
}

void EscribirPunto(Punto x, Punto y) {

  printf("Punto 1 -> (%.2f,%.2f)\nPunto 2 -> (%.2f,%.2f)\n",x.x,x.y,y.x,y.y);
}

float DistanciaPuntos(Punto x, Punto y) {
  float z;
  z = sqrt(pow(x.x - y.x, 2) + pow(x.y - y.y, 2));
  return z;
}

Punto PuntoMedio(Punto x, Punto y) {
  Punto z;
  z.x = (x.x + y.x) / 2;
  z.y = (x.y + y.y) / 2;
  return z;
}

Figura FiguraDefinenPuntos(Punto x, Punto y) {

  Figura t;
  Punto z;
  float dist1, dist2;

  z.x = x.x;
  z.y = y.y;
  dist1 = DistanciaPuntos(x, z);
  dist2 = DistanciaPuntos(y, z);

  if (x.x == y.x && x.y == y.y)
    return PUNTO;

  if (x.x == y.x) {
    if (x.y == y.y) {
      t = 2;
    } else
      t = 3;
  } else {
    if (x.y == y.y)
      t = 4;
    else {
      if (dist1 == dist2)
        t = 0;
      else
        t = 1;
    }
  }
  return t;
}
float AreaFiguraPuntos(Punto x, Punto y) {

  Figura t;
  Punto z;
  float r, dist1, dist2;

  z.x = x.x;
  z.y = y.y;
  dist1 = DistanciaPuntos(x, z);
  dist2 = DistanciaPuntos(y, z);
  t = FiguraDefinenPuntos(x, y);

  if (t == CUADRADO || t == RECTANGULO) {
    if (RECTANGULO)
      puts("La figura es un rectangulo");
    else
      puts("La figura es un cuadrado");
    r = dist1 * dist2;
    return r;
  } else
			switch(t){
				case LINEA_HORIZONTAL:
    			puts("La figura es una linea horizontal");
					break;
				case LINEA_VERTICAL:
    			puts("La figura es una linea vertical");
					break;
				case PUNTO:
    			puts("La figura es un punto");
					break;
			}
  return 0;
}
