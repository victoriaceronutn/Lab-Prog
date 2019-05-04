#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////////////////////////////////////////////
#ifndef empleados_H_INCLUIDA
#define empleados_H_INCLUIDA

#include "empleados.h"

#endif

#include "input.h"

#define TAM 5



eLocalidad construirLocalidad()
{
    eLocalidad retornarLocalidad;

    printf("ingrese un id: ");
    scanf("%d",&retornarLocalidad.id);

    printf("ingrese una descripcion: ");
    fflush(stdin);
    gets(retornarLocalidad.descripcion);


    printf("\nAlta exitosa\n");

    return retornarLocalidad;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////
int cargarLocalidades(int tam,eLocalidad listado[])
{
    int i;
    for(i=0;i<tam;i++)
        {
            listado[i]=construirLocalidad();

        }
        return 1;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarLocalidad(eLocalidad localidad)
{
    printf("\n  ID: %d",localidad.id);
    printf("\n  Localidad: %s",localidad.descripcion);
}

/////////////////////////////////////////////////////////////////////////////////////

void mostrarLocalidades(int cantidadRegistros,eLocalidad lista[])
{
    int i;
    for(i=0;i<cantidadRegistros;i++)
        {
            mostrarLocalidad(lista[i]);
        }
}
//////////////////////////////////////////////////////////////////////
void inicializarListado(int tam,ePersona lista[])
{
    int i;
    for(i=0;i<tam;i++)
        {
            lista[i].estado=0;
        }
}

//////////////////////////////////////////////////////////////////////
int altaPersona(ePersona lista,int tam)
{
    ePersona retornarPersona;

    printf("\nIngrese el id de persona: ");
    scanf("%d",&retornarPersona.id);

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(retornarPersona.nombre);


    printf("\nIngrese apellido: ");
    fflush(stdin);
    gets(retornarPersona.apellido);


    printf("\nIngrese edad: ");
    scanf("%d",&retornarPersona.edad);

}
