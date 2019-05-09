#include "peliculas.h"
#include "actor.h"

void inicializarPelicula(ePelicula lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].id = 0;
        lista[i].estado = LIBRE;
    }
}

void harcodearPelicula(ePelicula lista[])
{
    int i;
    int tam = 5;
    int id[0][5]= {"12345","65789","98764","12348","85613"};
    char titulo[][50]= {"titan","locos","fantasma","mas alla","rosas"};
    char fechaDePublicacion[][6]={"12/05/2007","15/08/2016","12/11/2013","06/02/2000","09/12/2006"};
    char genero[][50] = {"accion","comedia","terror","suspenso","drama"};
    char actor[][50]= {"julieta roberto","roberto deniro","richar darin","tita merelo","sandro"};

    for(i=0; i<tam; i++)
    {
        lista[i].id = i + 1;
        strcpy(lista[i].titulo, titulo[i]);
        strcpy(lista[i].fechaDePublicacion, fechaDePublicacion[i]);
        strcpy(lista[i].genero, genero[i]);
        strcpy(lista[i].actor, actor[i]);
        lista[i].idActor = actor[i];
        lista[i].estado = OCUPADO;
    }
}

void mostrarListaPeliculas(ePelicula lista[], int tam)
{
    int i;
    printf("------------------------------\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarPelicula(lista[i]);
        }
    }
    printf("------------------------------\n");
}

void mostrarPelicula(ePelicula unaPelicula)
{
    printf("%d %15s %15s %d %f\n", unaPelicula.id, unaPelicula.titulo, unaPelicula.fechaDePublicacion, unaPelicula.genero, unaPelicula.actor);
}

void mostrarPeliculasConActor(ePelicula listaPeliculas[], int tampeli,eActor listaActor[] , int tamAct)
{
    int i;
    int j;
    for(i=0; i<tampeli; i++)//SE HACE PARA MOSTAR LAS PELICULAS LOS DOS FOR Y LOS DOS IF SE HACE PARA QUE LIMITE
    {
        if(listaPeliculas[i].estado!=LIBRE) {//SI ESTA LIBRE MUESTRA ESTUDIO DE LA LISTA DE ESTUDIO
            mostrarPelicula(listaPeliculas[i]);

            for(j=0; j<tamAct; j++)
            {
                if( listaPeliculas[i].idActor == listaActor[j].id && listaActor[j].estado != LIBRE)
                {
                    mostrarActor(listaActor[j]);
                }
            }
        }
    }
}
