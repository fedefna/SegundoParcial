#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

eEmpleado* nuevoEmpleado(){
    eEmpleado* retorno;

    retorno= (eEmpleado*) malloc(sizeof(eEmpleado));

    if(retorno!=NULL){
        strcpy(retorno->direccion," ");
        strcpy(retorno->nombre," ");
        retorno->id=-1;
        retorno->horas=0;
        retorno->sueldo=0;
    }

    return retorno;
}

int setId(eEmpleado* pEmpleado, int id){
    int retorno=-1;
    if(pEmpleado!=NULL){
        pEmpleado->id=id;
        retorno=0;
    }
    return retorno;
}

int getId(eEmpleado* pEmpleado){
    int retorno=-1;
    if(pEmpleado!=NULL){
        retorno=pEmpleado->id;
    }
    return retorno;
}

int setNombre(eEmpleado* pEmpleado, char* nombre){
    int retorno=-1;
    if(pEmpleado!=NULL){
        strcpy(pEmpleado->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

char* getNombre(eEmpleado* pEmpleado){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pEmpleado!=NULL && retorno!=NULL){
        strcpy(retorno,pEmpleado->nombre);
    }
    return retorno;
}

int setDireccion(eEmpleado* pEmpleado, char* direccion){
    int retorno=-1;
    if(pEmpleado!=NULL){
        strcpy(pEmpleado->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

char* getDireccion(eEmpleado* pEmpleado){
    char* retorno;
    retorno=(char*) malloc(sizeof(char)*40);
    if(pEmpleado!=NULL && retorno!=NULL){
        strcpy(retorno,pEmpleado->direccion);
    }
    return retorno;
}

int setHoras(eEmpleado* pEmpleado, int horas){
    int retorno=-1;
    if(pEmpleado!=NULL){
        pEmpleado->horas=horas;
    }
    return retorno;
}

int getHoras(eEmpleado* pEmpleado){
    int retorno;
    if(pEmpleado!=NULL){
        retorno=pEmpleado->horas;
    }
    return retorno;
}

int setSueldo(eEmpleado* pEmpleado, int sueldo){
    int retorno=-1;
    if(pEmpleado!=NULL){
        pEmpleado->sueldo=sueldo;
    }
    return retorno;
}

int getSueldo(eEmpleado* pEmpleado){
    int retorno=-1;
    if(pEmpleado!=NULL){
        retorno=pEmpleado->sueldo;
    }
    return retorno;
}

void printEmpleado(eEmpleado* empleado)
{
    if(empleado != NULL)
    {
        printf("%4d  %10s  %30s  %6d     %5d\n", getId(empleado), getNombre(empleado), getDireccion(empleado),getHoras(empleado),getSueldo(empleado));
    }
    else
    {
        printf("No se pudo leer el empleado\n");
    }
}

int comparar(void* empleado1, void* empleado2){
    int retorno = 0;

    if(strcmp(((eEmpleado*)empleado1)->nombre, ((eEmpleado*)empleado2)->nombre) < 0){
        retorno = 1;
    }
    if(strcmp(((eEmpleado*)empleado1)->nombre, ((eEmpleado*)empleado2)->nombre) > 0){
        retorno =  -1;
    }
}

int calcularSueldo(void* pEmpleado){
    int retorno=-1;
    int sueldo;
    int horas=getHoras(pEmpleado);
    if(horas>120){
        if(horas>160){
            int diferenciaHoras=horas-160;
            int diferenciaPlata=diferenciaHoras*350;
            sueldo=31200+diferenciaPlata;
            setSueldo(pEmpleado,sueldo);
            retorno=0;
        }else{
            int diferenciaHoras=horas-120;
            int diferenciaPlata=diferenciaHoras*240;
            sueldo=21600+diferenciaPlata;
            setSueldo(pEmpleado,sueldo);
            retorno=0;
        }
    }else{
        sueldo=horas*180;
        setSueldo(pEmpleado,sueldo);
        retorno=0;
    }
    return retorno;
}

int crearArchivo(ArrayList* lista,char* path){
   int retorno=-1;
   eEmpleado* aux;
   if(lista!=NULL){
        FILE* f;
        f=fopen(path,"w");

        if(f!=NULL){
            int tam=lista->len(lista);
            for(int i=0;i<tam;i++){
                aux=lista->get(lista,i);

                fprintf(f,"%d,",getId(aux));
                fprintf(f,"%s,",getNombre(aux));
                fprintf(f,"%s,",getDireccion(aux));
                fprintf(f,"%d,",getHoras(aux));
                fprintf(f,"%d\n",getSueldo(aux));
            }
            retorno=0;
        }
        fclose(f);
   }
   return retorno;
}

int filtrar(void* pEmpleado){
    int retorno=-1;
    if(getHoras(pEmpleado)>120){
        retorno=0;
    }
    return retorno;
}
