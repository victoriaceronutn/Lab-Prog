#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"


ePelicula pedirPelicula()
{
    ePelicula peliculaParaRetornar;

    printf("Ingrese id: ");
    fflush(stdin);
    gets(peliculaParaRetornar.id);

    printf("Ingrese proveedor: ");
    fflush(stdin);
    gets(peliculaParaRetornar.actor);

    printf("Ingrese titulo: ");
    fflush(stdin);
    gets(peliculaParaRetornar.titulo);

    printf("Ingrese fecha de estreno: ");
    fflush(stdin);
    gets(peliculaParaRetornar.fechaDePublicacion);

    printf("Ingrese genero: ");
    fflush(stdin);
    gets(peliculaParaRetornar.genero);

    peliculaParaRetornar.estado = OCUPADO;

    return peliculaParaRetornar;
}


void mostrarPelicula(ePelicula unaPelicula)
{
    printf("%15d %15s %10s %10s %10s %5d\n", unaPelicula.idActor, unaPelicula.actor, unaPelicula.titulo, unaPelicula.fechaDePublicacion, unaPelicula.genero, unaPelicula.estado);
}

void mostrarActor(eActor unActor)
{
    printf("%15d\n", unActor.id);
}


void cargarArray(ePelicula listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        listado[i]= pedirPelicula();
    }
}


void mostrarArray(ePelicula listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            mostrarPelicula(listado[i]);
        }
    }
}


void construirArray(ePelicula listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        listado[i].estado= LIBRE;
        strcpy(listado[i].actor, "");
        strcpy(listado[i].titulo, "");
        strcpy(listado[i].fechaDePublicacion, "");
        strcpy(listado[i].genero, "");
    }
}


int insertarPelicula(ePelicula listado[], int tam)
{
    int indice;
    indice= dameLugarLibre(listado, tam);
    if(indice != -1)
    {
        listado[indice]= pedirPelicula();
    }
    return indice;
}


int dameLugarLibre(ePelicula listado[], int tam)
{
    int i;
    int index = -1;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}


int existePelicula(ePelicula unaPelicula,ePelicula lista[])
{
}


int borrarPelicula(ePelicula lista[], int tam)
{
    int i;
   char codigo[50];
   int loEncontro = 0;

   printf("Ingrese el codigo: ");
   fflush(stdin);
   gets(codigo);

   for(i=0; i<tam; i++)
   {
       if(strcmp(lista[i].codigoDeBarra, codigo)==0)
       {
          lista[i].estado = LIBRE;
            loEncontro = 1;
           break;
       }

   }

   if(loEncontro==0)
   {
      printf("Codigo inexistente!!");
   }

    return 0;
}

void inicializarPelicula(ePelicula listaPeliculas[],int tam)
{

    float precio[10]={42,43,44,40,41,42,35,36,37,38};
    char nombre[10][50]={"infinia","axion power","V-Power","infinia Diesel","axion Diesel","V-Power diesel","super","axion super","normal","kerosene"};
    int idProveedor[10]={1,2,3,1,2,3,1,2,3,1};
    char codigoDeBarra[10][50]={"122","222","322","422","522","622","722","822","922","962"};
    char fechaDeVencimiento[10][50]={"01/01/2020","01/02/2020","01/03/2020","01/04/2020","01/05/2020","01/06/2020","01/07/2020","01/08/2020","01/09/2020","01/10/2020",};

    int i;
    for(i=0;i<10;i++)
    {
        strcpy(listaPeliculas[i].codigoDeBarra,codigoDeBarra[i]);
        strcpy(listaPeliculas[i].nombre,nombre[i]);
        strcpy(listaPeliculas[i].fechaDeVencimiento, fechaDeVencimiento[i]);
        listaPeliculas[i].precio=precio[i];
        listaPeliculas[i].idProveedor = idProveedor[i];
        listaPeliculas[i].estado = OCUPADO;
    }



}

int editarProducto(ePelicula lista[], int tam)
{
   int i;
   char codigo[50];
   int loEncontro = 0;

   printf("Ingrese el codigo de barras: ");
   fflush(stdin);
   gets(codigo);

   for(i=0; i<tam; i++)
   {
       if(strcmp(lista[i].codigoDeBarra, codigo)==0)
       {
           printf("Ingrese el nuevo precio: ");
           scanf("%f", &lista[i].precio);
            loEncontro = 1;
           break;
       }

   }

   if(loEncontro==0)
   {
      printf("Codigo inexistente!!");
   }

   return 0;
}


void inicializarActor(eActor listaActor[],int tam)
{

    int id[5] ={1,2,3,4,5};
    char actor[5][50]={"","","","",""};
    char paisDeOrigen[3][50]={"avellaneda","bahia blanca","rio negro"};
    char cuit[3][50]={"444","555","666"};
    char duenio[3][50]={"ypf","axion","shell"};

    int i;

    for(i=0;i<3;i++)
    {
         listaActor[i].id=id[i];
        strcpy(listaActor[i].,[i]);
        strcpy(listaActor[i].,[i]);
        strcpy(listaActor[i].,[i]);
        strcpy(listaActor[i].,[i]);
    }
}

void mostrarArrayActorconSusPeliculas(ePelicula listaPeliculas[],int tamPel,eActor listaActores[], int tamActor)
{
    int i;
    int j;
    for(i=0; i<tamPel; i++)
    {
            mostrarPelicula(listaPeliculas[i]);

                for(j=0; j<tamActor; j++)
                {
                    if(listaPeliculas[j].idActor == listaActores[j].id)
                    {
                         mostrarActor(listaActores[j]);
                    }
                }
    }

}
