#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    int estado;
    char actor[50];
    char paisDeOrigen[50];
    int codigo[5];

} eActor;

void cargarActor(eActor lista[], int tam);
int buscarLibre(eActor lista[], int tam);
void inicializarActor(eActor lista[], int tam);
void harcodearActor(eActor lista[]);
void mostrarListaActor(eActor lista[], int tam);
void mostrarActor(eActor unActor);
int mayorIdActor(eActor lista[], int tam);
void modificarActor(eActor lista[], int tam, int id);
void borrarActor(eActor lista[], int tam, int id);
//void mostrarActorConPeliculas(eActor listaActor[] , int tamAct, ePelicula listaPeliculas[], int tampeli);


#endif // ACTOR_H_INCLUDED
