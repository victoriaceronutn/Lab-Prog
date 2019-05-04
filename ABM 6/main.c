#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "empleado.h"

#define TAM 2


int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam);


int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM];//={{1234, "Juan", 'm', 30000, 1},{2222, "Ana", 'f', 32000, 1}, {2211, "Jorge", 'm', 28000, 0}};
    inicializarEmpleados(lista, TAM);
    int auxLegajo;
    int i;
    eEmpleado emp[200];


    do
    {
        switch(menu())
        {

        case 1:
            //printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM);
            system("pause");
            break;

        case 2:
            printf("\nBaja empleado\n\n");
            system("pause");
            break;

        case 3:
            printf("\nModificacion empleado\n\n");



            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM);
            system("pause");
            break;

        case 6:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarEmpleado(eEmpleado emp){

    printf("   %d       %10s     %c    %.2f               %d        %d         %d\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo,emp.fechaNac.dia,emp.fechaNac.mes,emp.fechaNac.anio);
}

void mostrarEmpleados(eEmpleado vec[], int tam){
    int contador = 0;
    int i;
    printf(" Legajo   Nombre  Sexo  Sueldo Fecha nacimiendo Dia Mes Anio\n\n");
    for(i=0; i < tam; i++){
        if(vec[i].ocupado == 1){
            mostrarEmpleado(vec[i]);
            contador++;
        }
    }

    if( contador == 0){
        printf("\nNo hay empleados que mostrar\n");
    }
}

int buscarLibre(eEmpleado vec[], int tam){

    int indice = -1;
    int i;
     for(i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0){
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo){

    int indice = -1;
    int i;
     for(i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].legajo == legajo){
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam){

int indice;
int legajo;
int esta;
eEmpleado emp[200];


indice = buscarLibre(vec, tam);

if( indice == -1){

    printf("\nNo hay lugar en el sistema\n");
}
else{
     printf("Ingrese legajo: ");
     scanf("%d", &legajo);

     esta = buscarEmpleado(vec, tam, legajo);

     if( esta != -1){
        printf("Existe un empleado de legajo %d en el sistema\n", legajo);
        mostrarEmpleado(vec[esta]);
     }
     else{
        vec[indice].legajo = legajo;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(vec[indice].nombre);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &vec[indice].sexo );

        printf("Ingrese sueldo: ");
        scanf("%f", &vec[indice].sueldo );

        printf("\nIngrese fecha de nacimiento\n");
        printf("Dia: ");
        fflush(stdin);
        scanf("%d",&emp[indice].fechaNac.dia);

        printf("Mes: ");
        fflush(stdin);
        scanf("%d",&emp[indice].fechaNac.mes);

        printf("Anio: ");
        fflush(stdin);
        scanf("%d",&emp[indice].fechaNac.anio);

        vec[indice].ocupado = 1;

        printf("Alta empleado exitosa!!!\n\n");

     }

}

}
