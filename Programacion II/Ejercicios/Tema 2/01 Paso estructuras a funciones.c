#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char  prnombre[25];
  long  prcodigo;
  float prprecio;
} Producto;

void MostrarProducto (Producto);
void ModificarProducto (Producto *);
void ImprimirProductoV (Producto);
void ImprimirProductoR (const Producto *);
void LeerProducto (Producto *);

int main (void) {
  Producto prod = {"DESTORNILLADOR", 7785456, 12.25};
 
  puts("VALORES DEL PRODUCTO:");
  MostrarProducto(prod);

  puts("PROCEDEMOS A MODIFICAR EL PRODUCTO:");
  ModificarProducto(&prod);

  puts("PRODUCTO MODIFICADO:");
  MostrarProducto(prod);

  return 0;
}

void MostrarProducto (Producto pr) {
ImprimirProductoV(pr);
ImprimirProductoR(&pr);
}

void ImprimirProductoV (Producto pr) {
puts(pr.prnombre);
printf("Codigo: %ld\nPrecio: %.2f\n",pr.prcodigo,pr.prprecio);
}

void ImprimirProductoR (const Producto *ppr) {
puts(ppr->prnombre);
printf("Codigo: %ld\nPrecio: %.2f\n",ppr->prcodigo,ppr->prprecio);
}

void ModificarProducto (Producto *ppr) {
ImprimirProductoV(*ppr);
LeerProducto(ppr);
}

void LeerProducto (Producto *ppr) {
scanf("%[^\n]",ppr->prnombre);
scanf("%ld",&ppr->prcodigo);
scanf("%f",&ppr->prprecio);
}
