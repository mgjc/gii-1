#ifndef _alumno__h
#define _alumno__h
#include <stdio.h>
typedef struct{int dia, mes, anio;}Fecha;
typedef struct {char nombre [81];
                Fecha fnacimiento;
                float notas[NOTAS];}Alumno;
void Presentacion(void);
void ModuloPrincipal(Alumno *,int);
#endif
