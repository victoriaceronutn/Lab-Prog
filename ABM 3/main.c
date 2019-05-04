#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "input.h"
#include "empleado.h"

#define TAM_EMP 20
#define TAM_SEC 5
#define TAM_MENU 100
#define TAM_ALMUERZOS 200




int main()
{

        eAlmuerzo vecAlmuerzo[TAM_ALMUERZOS]=
            {{1,5,1,12,12,1999,1},
            {2,4,2,3,3,2000,1}};





    char seguir = 's';
    char confirma;
    int banderaAlta;
    int legajoIncremental=11;

    int banderaAlta2;
    int legajoIncremental2=3;

    int auxLegajo;






    eEmpleado listaEmp[TAM_EMP]=
        {{1, "Frias","Brenda", 'f', 30000, 24,12,1997,2, 1},
        {2, "Frias", "Aaa",'m', 22000,5,6,2018,2, 1},
        {3, "Paoli","Elia", 'f', 12000,9,12,2013,4, 1},
        {4, "Marquez","Juan", 'm', 34000,16,3,2002,1, 1},
        {5, "Barry","Allen", 'm', 15000,15,8,2011,4, 1},
        {6, "Watson","Ema", 'f', 22000,1,12,2008,3, 1},
        {7, "Gardel","Carlos", 'm', 33000,21,6,2015,3, 1},
        {8, "Frias","Raul", 'm', 32000,12,7,2016,3, 1},
        {9, "Diaz","Alejo", 'm', 30000,7,3,2004,5, 1},
        {10, "Perry","Carla", 'f', 12000,1,11,2005,3, 1},
        {11, "Franco","Carla", 'f', 12000,1,11,2005,3, 0}};

    eSector listaSectores[]= {{1, "Sistemas"},{2, "RR HH"},{3,"Compras"},{4,"Ventas"},{5, "Legales"}};

    eMenu listaMenues[]= {{1, "Pizza", 100.00},{2, "Arroz", 30.25},{3, "Pollo", 60.25},{4, "Panchos", 25.50},{5, "Milanesa", 55.00},{6, "Ravioles", 40.30},{7, "Pescado", 55.00},{8, "Empanadas", 30.25},{9, "Hamburgesa", 25.55},{9, "Ensalada", 25.35},{10, "Papas fritas", 30.10}};




        //inicializarEmpleados(listaEmp, TAM_EMP);
        //inicializarAlmuerzos(vecAlmuerzo,TAM_ALMUERZOS);



     do
    {
        switch(menu())
        {

        case 1:

            banderaAlta=(altaEmpleado(listaEmp, TAM_EMP, listaSectores, TAM_SEC, legajoIncremental));
           // altaEmpleado(listaEmp, TAM_EMP,listaSectores,TAM_SEC, legajoIncremental);
            system("pause");

            if(banderaAlta==1){
                legajoIncremental++;
            }

            break;

        case 2:
            bajaEmpleado(listaEmp,TAM_EMP);
            system("pause");
            break;

        case 3:
            modificarEmpleado(listaEmp,TAM_EMP,listaSectores,TAM_SEC);
            system("pause");
            break;

        case 4:
            printf("listar empleados ordenados alfabeticamente");
            ordenarEmpleadosApellido(listaEmp,TAM_EMP);
            mostrarEmpleados(listaSectores,TAM_SEC,listaEmp,TAM_EMP);
            system("pause");
            break;

        case 5:

            printf("ALTA ALMUERZO \n");
            banderaAlta2=altaAlmuerzo(vecAlmuerzo,TAM_ALMUERZOS,listaEmp,TAM_EMP,listaSectores,TAM_SEC,legajoIncremental2);


            if(banderaAlta2==1){
                legajoIncremental2++;
            }

            break;


        case 6:
            printf("mostrar almuerzos");

            mostrarAlmuerzos(vecAlmuerzo,TAM_ALMUERZOS);


            system("pause");
            break;


        case 7:
            printf("\nConfirma la salida del programa s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                printf("\n\n-- Programa finalizado --\n");
                seguir = 'n';
            }
            break;

        case 8:
            printf("\nMuestra todos los almuerzos de un empleado\n");
            int i;
            int auxLegajo;
                getInt(&auxLegajo,"\nIngrese su legajo","Error, legajo invalido",1,200);
                i=buscarEmpleado(listaEmp,TAM_EMP,auxLegajo);
                if(listaEmp[i].isEmpty!=1)
                    {
                        printf("\nError,No se encuentra su legajo\n");

                    }

                mostrarAlmuerzosDeUnEmpleado(listaEmp,i,listaSectores,TAM_SEC,vecAlmuerzo,TAM_ALMUERZOS);


        default:
            printf("\n Opcion invalida\n\n");
            system("pause");
        }
    }
    while(seguir == 's');

    return 0;

}
