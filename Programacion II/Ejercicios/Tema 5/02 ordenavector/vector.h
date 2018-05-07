#ifndef __VECTOR_H__
#define __VECTOR_H__
#define ALEATORIOMIN -50
#define ALEATORIOMAX  50

typedef int tipoDatoVector;

tipoDatoVector *CreaVector (int dim);
void LiberaVector (tipoDatoVector *v);
void PresentaVector (tipoDatoVector *v, int dim, const char *fmt);

#endif
