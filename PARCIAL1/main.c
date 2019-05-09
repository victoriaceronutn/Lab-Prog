#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actor.h"
#include "peliculas.h"
#define T 6

int main()
{
    eActor listaActor[T];
    ePelicula listaPeliculas[T];

    inicializarActor(listaActor, T);
    harcodearActor(listaActor);

    inicializarPelicula(listaPeliculas, T);
    harcodearPelicula(listaPeliculas);

    mostrarPeliculasConActor(listaPeliculas,T,listaActor,T);

    return 0;
}
