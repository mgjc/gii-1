#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#define NUM   10

typedef struct empleados {
    char apellidos[30];
    char nombre[15];
    int  matricula;
    //char bufferRelleno[50000];
} tipoEmpleado;

void cargarRegistrosAleatorios(tipoEmpleado * empleados, int numEmpleados);
void cargarUnRegistro(tipoEmpleado * empleado);
void mostrarRegistro(tipoEmpleado empleado);
void mostrarRegistrosRef(tipoEmpleado ** refsEmpleados, int numEmpleados);
void mostrarRegistros(tipoEmpleado * empleados, int numEmpleados);
void ordenarRegistrosRefApellido(tipoEmpleado ** refsEmpleados, int numEmpleados);
void ordenarRegistrosApellido(tipoEmpleado * empleados, int numEmpleados);


int main(void)
{
    tipoEmpleado regEmpleados[NUM], unEmpleado;
    tipoEmpleado *regEmpleadosRef[NUM];
    int i;
    clock_t tiempoInicial, tiempoFinal;
    
    cargarRegistrosAleatorios(regEmpleados, NUM);
    
    printf("\n\n Jugando con un único registro: \n");
    unEmpleado = regEmpleados[2];
    mostrarRegistro(unEmpleado);
    mostrarRegistro(regEmpleados[2]);
    mostrarRegistros(&unEmpleado, 1);
    
    for (i = 0; i < NUM; i++)
	    regEmpleadosRef[i] = &regEmpleados[i];
    
    printf("\n\nValores no clasificados (a través matriz punteros): \n");
    mostrarRegistrosRef(regEmpleadosRef, NUM);
    
    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosRefApellido(regEmpleadosRef, NUM);
    tiempoFinal = clock ();

    printf("\n\nValores clasificados (a través matriz punteros): \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistrosRef(regEmpleadosRef, NUM);
    
    printf("\n\nAhora valores no clasificados matriz de registros original: \n");
    mostrarRegistros(regEmpleados, NUM);
    
    tiempoInicial = tiempoFinal = clock ();
    ordenarRegistrosApellido(regEmpleados, NUM);
    tiempoFinal = clock ();
    
    printf("\n\nAhora valores clasificados matriz de registros original: \n");
    printf("Tiempo tardado: %f\n",(tiempoFinal-tiempoInicial)/(double)CLOCKS_PER_SEC);
    mostrarRegistros(regEmpleados, NUM);
    
    return 0;
}

void cargarRegistrosAleatorios(tipoEmpleado * empleados, int numEmpleados)
{
    int i;
    static char apellidos [][15] = {"ALONSO","ALVAREZ","ARBESU",
        "DOMINGUEZ","FERNANDEZ","FLORIANO",
        "GONZALEZ","GOMEZ","GUTIERREZ",
        "MARTIN", "MORO", "PEREZ","TURRION",
        "ZAMBRANO"};
    static char nombres [][15] = {"ALVARO","ARSENIO","DOMINGO",
        "FELIPE","FATIMA","FABIAN",
        "GONZALO","PEDRO","PATRICIA",
        "TOMAS", "ZOILO"};
    int numApellidos = sizeof(apellidos)/15;
    int numNombres = sizeof(nombres)/15;
    char buffer[5];
    
    srandom(time(NULL));
    for (i = 0; i < numEmpleados; i++) {
        sprintf(empleados[i].apellidos,"%s %s",apellidos[random() % numApellidos],
                apellidos[random() % numApellidos]);
        sprintf(empleados[i].nombre,"%s",nombres[random() % numNombres]);
        sprintf(buffer,"%c%c%c%c",(char)('0' + random() % 10),
                (char)('0' + random() % 10),
                (char)('0' + random() % 10),
                (char)('0' + random() % 10));
        empleados[i].matricula = atoi(buffer);
    }
}

void cargarUnRegistro(tipoEmpleado * empleado)
{

  fgets(empleado->apellidos,29,stdin);
  fgets(empleado->nombre,14,stdin);
  scanf("%d",&empleado->matricula);
    
}

void mostrarRegistro(tipoEmpleado empleado)
{

  printf("%s, %s: %d\n", empleado.apellidos,empleado.nombre,empleado.matricula);

}

void mostrarRegistros(tipoEmpleado * empleados, int numEmpleados)
{

  int i;

  for(i=0;i<numEmpleados;i++)
  printf("%s, %s: %d\n", empleados[i].apellidos,empleados[i].nombre,empleados[i].matricula);

}

void mostrarRegistrosRef(tipoEmpleado ** refsEmpleados, int numEmpleados)
{

  int i;

  for(i=0;i<numEmpleados;i++)
     printf("%s, %s: %d\n",refsEmpleados[i]->apellidos,refsEmpleados[i]->nombre,refsEmpleados[i]->matricula);

}

void ordenarRegistrosApellido(tipoEmpleado * empleados, int numEmpleados)
{
    int i,j;
    tipoEmpleado temp;
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp(empleados[j].apellidos, empleados[j - 1].apellidos)) < 0) {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }
}

void ordenarRegistrosRefApellido(tipoEmpleado ** refsEmpleados, int numEmpleados)
{

  int i,j;
  tipoEmpleado *temp;

  for(i = 0; i < numEmpleados - 1 ; i++) {

    for(j = numEmpleados-1; j > i; j--) {

      if((strcmp(refsEmpleados[j]->apellidos,refsEmpleados[j-1]->apellidos))<0){
         temp=refsEmpleados[j];
         refsEmpleados[j]=refsEmpleados[j-1];
         refsEmpleados[j-1]=temp;
      }
    }
  }
}
