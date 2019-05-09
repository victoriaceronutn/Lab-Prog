#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    int estado;
    int codigo[5];
    char titulo[50];
    char fechaDePublicacion[13];
    char genero;
    char actor[50];
    int idActor;

} ePelicula;

typedef struct
{
    int id;
    int estado;
    char actor[50];
    char paisDeOrigen[50];
    int codigo[5];

} eActores;

#endif // PELICULAS_H_INCLUDED

void inicializarPelicula(ePelicula lista[], int tam);
void harcodearPelicula(ePelicula lista[]);
void mostrarListaPeliculas(ePelicula lista[], int tam);
void mostrarPelicula(ePelicula unaPelicula);
