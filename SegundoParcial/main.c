#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Funciones.h"

int main()
{
    ArrayList* lista;
    lista=al_newArrayList();
    eEmpleado* empleado;

    FILE* f;
    f= fopen("MOCK_DATA.csv","r");

    if(f==NULL){
        printf("Error al leer el archivo");
        system("pause");
        exit(1);
    }

    while(!feof(f)){
        char idAux[10],nombreAux[40],direccionAux[40],horasAux[10];
        int cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,direccionAux,horasAux);

        if(cant!=4){
            if(feof(f))
            {
                break;
            }
            else
            {
                printf("Problema para leer el archivo\n");
                break;
            }
        }
        empleado=nuevoEmpleado();

        //empleado->id=atoi(idAux);
        //strcpy(empleado->nombre, nombreAux);
        //strcpy(empleado->direccion, direccionAux);
        //empleado->horas=atoi(horasAux);

        setId(empleado,atoi(idAux));
        setNombre(empleado,nombreAux);
        setDireccion(empleado,direccionAux);
        setHoras(empleado,atoi(horasAux));

        lista->add(lista,empleado);
    }

    int tam= lista->len(lista);
    /*printf("ID       NOMBRE          DIRECCION                  HORAS    SUELDO\n");
    for(int i=0;i<tam;i++){
        empleado = al_get(lista, i);
        printEmpleado(empleado);
    }*/

    al_sort(lista,comparar,1);
    printf("\n");

    printf("ID       NOMBRE          DIRECCION                  HORAS    SUELDO\n");
    for(int i=0;i<tam;i++){
        empleado = al_get(lista, i);
        printEmpleado(empleado);
    }
    printf("\n");

    lista->map(lista,calcularSueldo);

    ArrayList* lista2;
    lista2=al_filter(lista,filtrar);

    /*printf("ID       NOMBRE          DIRECCION                  HORAS    SUELDO\n");
    for(int i=0;i<tam;i++){
        empleado = al_get(lista2,i);
        printEmpleado(empleado);
    }*/

    if(crearArchivo(lista2,"sueldos.csv")==0){
        printf("Archivo con sueldos filtrados creado!\n");
    }else{
        printf("Error al crear el archivo.\n");
    }

    return 0;
}
