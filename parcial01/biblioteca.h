#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1

typedef struct
{
    int estado;
    int id;
    int codigo[50];
    char titulo[50];
    char fechaDePublicacion[50];
    char genero[50];
    char actor[50];
    int idActor;

} ePelicula;

typedef struct
{
    int id;
    int estado;
    char actor[50];
    char paisDeOrigen[50];
    int codigo[50];

} eActor;


ePelicula pedirPelicula();

void inicializarPelicula(ePelicula[],int);//OK

void mostrarPelicula(ePelicula);

void mostrarPelicula(ePelicula);

void cargarArray(ePelicula[], int);

void mostrarArray(ePelicula[], int);

void construirArray(ePelicula[], int);

int insertarProducto(ePelicula[], int );

int dameLugarLibre(ePelicula[],int);

int existePelicula(ePelicula,ePelicula[]);

int borrarPelicula(ePelicula[], int);

int editarPelicula(ePelicula [], int );

void inicializarActor(eActor[], int);

void mostrarArrayActorconSusPeliculas(ePelicula[],int,eActor[], int);

