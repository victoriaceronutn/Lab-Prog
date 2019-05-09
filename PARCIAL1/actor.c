#include "actor.h"
#include "peliculas.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define T 6

void cargarActor(eActor lista[], int tam)
{
    int i;
    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        lista[i].id = mayorIdActor(lista, T) + 1;
        gets(lista[i].id);
        printf("Ingrese el id: ");
        fflush(stdin);

        gets(lista[i].actor);
        printf("Ingrese el nombre del actor: ");
        fflush(stdin);

        gets(lista[i].paisDeOrigen);
        printf("Ingrese el pais de origen: ");
        fflush(stdin);

        lista[i].estado = OCUPADO;
    }
    else
    {
        printf("No hay espacio");
    }
}

int buscarLibre(eActor lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}


void inicializarActor(eActor lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].id = 0;
        lista[i].estado = LIBRE;
    }
}

void harcodearActor(eActor lista[])
{
    int i;
    int tam = 5;
    char actor[][50]= {"julieta roberto","roberto deniro","richar darin","tita merelo","sandro"};
    char paisDeOrigen[][50]= {"eeuu","eeuu","argentina","argentina","argentina"};

    for(i=0; i<tam; i++)
    {
        lista[i].id = i + 1;
        strcpy(lista[i].actor, actor[i]);
        strcpy(lista[i].paisDeOrigen, paisDeOrigen[i]);
        lista[i].estado = OCUPADO;
    }
}

void mostrarListaActor(eActor lista[], int tam)
{
    int i;
    printf("------------------------------\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarActor(lista[i]);
        }
    }
    printf("------------------------------\n");
}
void mostrarActor(eActor unActor)
{
    printf("%d  %15s  %15s  %d\n", unActor.id, unActor.id, unActor.actor, unActor.paisDeOrigen);
}

int mayorIdActor(eActor lista[], int tam)
{
    int i;
    int flag = 0;
    int aux = 0;
    for(i=0; i<tam; i++)
    {
        if(flag==0 || lista[i].id>aux)
        {
            aux = lista[i].id;
            flag = 1;
        }
    }
    return aux;
}

void modificarActor(eActor lista[], int tam, int id)
{

    int i;
    int loEncontro = 0;
    printf("Ingrese id a modificar: ");
    scanf("%d", &id);

    for(i=0; i<tam; i++)
    {
        if(id == lista[i].id && lista[i].estado == OCUPADO)
        {
            printf("Ingrese un nuevo nombre: ");
            fflush(stdin);
            gets(lista[i].actor);
            loEncontro = 1;
            break;
        }
    }
    if(loEncontro==0)
    {
        printf("El dato no existe");
    }
}

void borrarActor(eActor lista[], int tam, int id)
{
    int i;
    int loEncontro = 0;
    printf("Ingrese id a borrar: ");
    scanf("%d", &id);

    for(i=0; i<tam; i++)
    {
        if(id == lista[i].id)
        {
            lista[i].estado = LIBRE;
            loEncontro = 1;
            break;
        }
    }
    if(loEncontro==0)
    {
        printf("El dato no existe");
    }
}

void mostrarActorConPeliculas(eActor listaActor[] , int tamAct, ePelicula listaPeliculas[], int tampeli)
{
    int i;
    int j;
    for(i=0; i<tamAct; i++)//SE HACE PARA MOSTAR LAS PELICULAS LOS DOS FOR Y LOS DOS IF SE HACE PARA QUE LIMITE
    {
        if(listaActor[i].estado!=LIBRE) {
            mostrarActor(listaActor[i]);

            for(j=0; j<tampeli; j++)
            {
                if( listaActor[i].id == listaPeliculas[j].idActor && listaPeliculas[j].estado != LIBRE)
                {
                    mostrarPelicula(listaPeliculas[j]);
                }
            }
        }
    }
}

