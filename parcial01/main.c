#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 10
#include "biblioteca.h"

int main()
{
    //definir array.
    //cargar array.
    //mostrar array.

    int opcion;

    //ePelicula unProducto;
    ePelicula listadoPeliculas[T];
    construirArray(listadoPeliculas,T);
    inicializarPelicula(listadoPeliculas,T);
    mostrarArray(listadoPeliculas,T);

    do
    {
        printf("1.ALTA\n2.BAJA\n3.MODIFICAR\n4.Mostrar\nElija opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
               insertarPelicula(listadoPeliculas, T);
            break;
            case 2:
                borrarPelicula(listadoPeliculas,T);
                break;
            case 3:
                editarPelicula(listadoPeliculas, T);
                break;

            case 4:
                mostrarArray(listadoPeliculas,T);
                break;
        }
    }while(opcion!=10);

    return 0;
}
