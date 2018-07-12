#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "string.h"

typedef struct
{
    int id;
    char nombre[40];
    char direccion[40];
    int horas;
    int sueldo;
}eEmpleado;

eEmpleado* nuevoEmpleado();

//INICIO Gueters y seters
int setId(eEmpleado*, int);

int getId(eEmpleado*);

int setNombre(eEmpleado*, char*);

char* getNombre(eEmpleado*);

int setDireccion(eEmpleado*, char*);

char* getDireccion(eEmpleado*);

int setHoras(eEmpleado*, int);

int getHoras(eEmpleado*);

int setSueldo(eEmpleado*, int);

int getSueldo(eEmpleado*);
//FIN GETERS Y SETERS

//PUNTO UNO Y DOS
void printEmpleado(eEmpleado*);

int comparar(void*, void*);

//PUNTO TRES Y CUATRO
int calcularSueldo(void*);

int crearArchivo(ArrayList*,char*);

//Recuperatorio
int filtrar(void*);
