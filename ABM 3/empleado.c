#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "input.h"
#include "empleado.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////
int menu()
{


    int opcion;
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificar Empleado\n");
    printf("4- Listar empleados ordenados alfabeticamente\n");
    printf("5- Alta Almuerzos\n");
    printf("6- Listar Almuerzos Por Empleados\n");
    printf("7- salir\n");

    fflush(stdin);
    printf("\nIngrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;

}
//////////////////////////////////////////////////////////////////
int subMenu()
{
    int opcion;
    printf("1- Para modificar apellido\n");
    printf("2- Para modificar nombre\n");
    printf("3- Para modificar sexo\n");
    printf("4- Para modificar salario\n");
    printf("5- Para modificar fecha de ingreso\n");
    printf("6- Para modificar sector\n");
    printf("\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

////////////////////////////////////////////////////////////////
void subMenuMenues()
{

    printf("\n1- Pizza $100\n");
    printf("2- Arroz $30.25\n");
    printf("3- Pollo $60.25\n");
    printf("4- Panchos $25.50\n");
    printf("5- Milanesa $55.00\n");
    printf("6- Ravioles $40.30\n");
    printf("7- Pescado 55.00\n");
    printf("8- Empanadas $30.25\n");
    printf("9- Hamburgesa $25.55\n");
    printf("10- Ensalada $25.35\n");
    printf("11- Papas fritas $30.10\n");

}

/////////////////////////////////////////////////////////////////
void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].isEmpty = 0;
    }
}
///////////////////////////////////////////////////////////

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
///////////////////////////////////////////////////////////

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1 && vec[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
/////////////////////////////////////////////////////////////////////////////////

void obtenerSector(eSector sectores[], int tamSectores, int idSectorEmp, char descMostrar[])
{
    for(int i=0; i<tamSectores; i++)
    {
        if(idSectorEmp == sectores[i].id)
        {
            strcpy(descMostrar,sectores[i].desc);
            break;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int altaEmpleado(eEmpleado vec[], int tam,eSector sec[],int tamSectores, int legajoMain)
{

    int indice;
    int altaOk=0;

    indice = buscarLibre(vec,tam);



    if(indice ==-1)
        {
            printf("\nNo hay lugar en el sistema\n");

        }
        else
            {
                vec[indice].legajo=legajoMain++;

                getString(vec[indice].nombre,"Ingrese el nombre: ","Error,largo del nombre invalido",2,51);

                getString(vec[indice].apellido,"Ingrese el apellido: ","Error,Largo del apellido invalido",2,51);


                getCharGenre(&vec[indice].sexo,"Ingrese el sexo: ","Error, debe ingresar F o M");


                getFloat(&vec[indice].sueldo,"Ingrese sueldo: ","Error sueldo invalido",1,200000);

                getInt(&vec[indice].fechaIn.dia,"Ingrese el dia de ingreso","Error, dia invalido",1,31);

                getInt(&vec[indice].fechaIn.mes,"Ingrese el mes de ingreso","Error, mes invalido",1,12);


                getInt(&vec[indice].fechaIn.anio,"Ingrese el anio de ingreso","Error, anio invalido",1900,2019);

                printf("\n 1-Sistemas   2-RRHH   3-Compras   4-Ventas   5-Legales\n");

                getInt(&vec[indice].idSector,"Ingrese el numero de sector: ","Error, sector invalido",1,5);

                vec[indice].isEmpty =1;

                printf("\nALTA EXITOSA\n");

                altaOk=1;

            }

            return altaOk;



}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bajaEmpleado(eEmpleado vec[], int tam)
{
    int legajo;
    int indiceLeg;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("%d",&legajo);

    indiceLeg=buscarEmpleado(vec,tam,legajo);

    if(indiceLeg==-1)
        {
            printf("\nError, no se encuentra el legajo en el sistema\n");

        }
        else
            {
                do
                    {
                        printf("\nLegajo numero %d \n",vec[indiceLeg]);
                        printf("Esta seguro que quiere cuntinuar? s/n: ");
                        fflush(stdin);
                        confirma=getche();
                        printf("\n");
                        system("pause");
                        if(tolower(confirma)=='n')
                        {
                        printf ("Baja cancelada!\n");
                            break;
                        }
                        else
                            {
                                vec[indiceLeg].isEmpty=-1;
                                printf("\nBaja empleado exitosa\n");
                            }
                    }while(confirma!='s');
            }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificarEmpleado(eEmpleado vec[], int tam,eSector vecSec[],int tamSectores)
{

    int legajo;
    int indice;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("%d",&legajo);

    indice=buscarEmpleado(vec,tam,legajo);

    if(indice==-1)
        {
            printf("\nError, no se encuentra el legajo en el sistema\n");

        }else
            {
                do
                    {
                        printf("\nLegajo numero %d \n",vec[indice]);
                        printf("Esta seguro que quiere cuntinuar? s/n: ");
                        fflush(stdin);
                        confirma=getche();
                        printf("\n");
                        system("pause");
                        if(tolower(confirma)=='n')
                        {
                        printf ("Modificacion cancelada!\n");
                            break;
                        }
                        else
                            {
                                switch(subMenu())
                                {
                                    case 1:
                                        getString(vec[indice].apellido,"Ingrese el apellido: ","Error,Largo del apellido invalido",2,51);
                                            break;

                                    case 2:
                                        getString(vec[indice].nombre,"Ingrese el nombre: ","Error,largo del nombre invalido",2,51);
                                            break;
                                    case 3:
                                        getCharGenre(&vec[indice].sexo,"Ingrese el sexo: ","Error, debe ingresar F o M");
                                            break;
                                    case 4:
                                        getFloat(&vec[indice].sueldo,"Ingrese sueldo: ","Error sueldo invalido",1,200000);
                                            break;
                                    case 5:
                                        getInt(&vec[indice].fechaIn.dia,"Ingrese el dia de ingreso","Error, dia invalido",1,31);

                                        getInt(&vec[indice].fechaIn.mes,"Ingrese el mes de ingreso","Error, mes invalido",1,12);

                                        getInt(&vec[indice].fechaIn.anio,"Ingrese el anio de ingreso","Error, anio invalido",1900,2019);
                                            break;
                                    case 6:
                                        printf("\n 1-Sistemas   2-RRHH   3-Compras   4-Ventas   5-Legales\n");

                                        getInt(&vec[indice].idSector,"Ingrese el numero de sector: ","Error, sector invalido",1,5);

                                }
                                printf("\nModificacion exitosa!!!\n");
                            }
                    }while(confirma!='s');
            }


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarEmpleado(eSector sectores[],int tamSectores, eEmpleado emp[], int i)
{
    char nombreSector[20];

    obtenerSector(sectores, tamSectores, emp[i].idSector, nombreSector);

    printf("%03d\t%s\t%s\t%c\t%.2f\t%02d/%02d/%d\t%s\n", emp[i].legajo, emp[i].apellido, emp[i].nombre, emp[i].sexo, emp[i].sueldo,emp[i].fechaIn.dia,emp[i].fechaIn.mes,emp[i].fechaIn.anio,nombreSector);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tam)
{
    int contador=0;
   printf("\nLegajo\tApelli.\tNombre\tSexo\tSueldo\t\tIngreso\t\tSector\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {

            mostrarEmpleado(sectores,tamSectores,vec, i);
            contador++;
        }
    }
    if (contador==0)
    {
        printf ("No hay empleados que listar\n\n");
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenarEmpleadosApellido(eEmpleado vec[], int tam)
{
    eEmpleado auxEmp;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].apellido, vec[j].apellido)>0)//si las cadenas son iguales retornara 0, si la primera es mayor retornara un valor positivo y si es menor retornara un valor negativo.
            {
                auxEmp = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmp;
            }
        }
    }
    printf("\n-- Empleados ordenados exitosamente --\n\n");

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* int altaMenu(eMenu vec[], int tamMenu, int legajoMain)
{
    int indice;
    int altaOk=0;
    indice = buscarLibre(vec,tamMenu);
    if(indice ==-1)
        {
            printf("\nNo hay lugar para agregar otro menu\n");
        }
        else
            {
                vec[indice].id=legajoMain++;
                getString(vec[indice].desc,"Ingrese el nombre del menu: ","Error,largo del nombre invalido",2,51);
                getFloat(&vec[indice].importe,"Ingrese el precio del menu: ","Error precio invalido",1,1500);
                printf("\nALTA EXITOSA\n");
                altaOk;
            }
            return altaOk;
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarSector (eEmpleado vec[], int tam, eSector sec[], int tamSec,eEmpleado emp[])
{
    system("cls");

    for (int i=0;i<tamSec;i++)
    {
        printf ("Sector: %s\n\n", sec[i].desc);
        for (int j=0;j<tam;j++)
        {
            if((vec[j].idSector==sec[i].id) && vec[j].isEmpty==1)
            {
                mostrarEmpleado(sec,tamSec,vec, j);
            }

        }
    }

    printf ("\n\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void inicializarAlmuerzos(eAlmuerzo vec[], int tamAlmuerzo)
{
    for(int i=0; i < tamAlmuerzo; i++)
    {
        vec[i].isEmpty = 0;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tamAlmuerzo)
{

    int indice = -1;

    for(int i=0; i < tamAlmuerzo; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarAlmuerzo(eAlmuerzo vec[], int tamAlmuerzo, int id)
{

    int indice = -1;

    for(int i=0; i < tamAlmuerzo; i++)
    {
        if(vec[i].isEmpty == 1 && vec[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int altaAlmuerzo(eAlmuerzo vecAlmuerzo[],int tamAlmuerzo,eEmpleado vecEmpleado[], int tam,eSector sec[],int tamSectores, int legajoMain)
{


    int indice;
    int auxLegajo;
    int opcion;
    int altaOk=0;
    int indice2;

    indice=buscarLibreAlmuerzo(vecAlmuerzo,tamAlmuerzo);

    if(indice ==-1)
        {
            printf("\nNo hay lugar en el sistema\n");

        }
        else
            {

                vecAlmuerzo[indice].id=legajoMain++;

                mostrarEmpleados(sec,tamSectores,vecEmpleado,tam);
                getInt(&auxLegajo,"\nIngrese su legajo","Error, legajo invalido",1,200);
                indice2=buscarEmpleado(vecEmpleado,tam,auxLegajo);
                if(vecEmpleado[indice2].isEmpty!=1)
                    {
                        printf("\nError,No se encuentra su legajo\n");

                    }
                else{

                vecAlmuerzo[indice].legajoEmp=auxLegajo;


                subMenuMenues();
                getInt(&opcion,"Ingrese el ID de menu","Error, ID invalido",1,11);
                vecAlmuerzo[indice].idMenu=opcion;

                getInt(&vecAlmuerzo[indice].fechaAlmuerzo.dia,"Ingrese el dia: ","Error, dia invalido",1,31);

                getInt(&vecAlmuerzo[indice].fechaAlmuerzo.mes,"Ingrese el mes: ","Error, mes invalido",1,12);

                getInt(&vecAlmuerzo[indice].fechaAlmuerzo.anio,"Ingrese el anio: ","Error, anio invalido",1950,2050);

                 vecAlmuerzo[indice].isEmpty =1;


                printf("\nALTA EXITOSA\n");
                altaOk=1;



                }
            }



                return altaOk;


}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void mostrarAlmuerzo(eAlmuerzo alm[],int i)
{


    //obtenerSector(sectores, tamSectores, emp.idSector, descSector);
    //mostrarEmpleado(sectores,tamSectores,emp);

    printf("\n %d\t  %d\t  %d\t  %02d/%02d/%d\t\ ",alm[i].id,alm[i].idMenu,alm[i].legajoEmp,alm[i].fechaAlmuerzo.dia,alm[i].fechaAlmuerzo.mes,alm[i].fechaAlmuerzo.anio);
    printf("\n");
    //printf("\n %03d\t%s\t%s\t%c\t%.2f\t%02d/%02d/%d\t%s\n", emp.legajo, emp.apellido, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIn.dia, emp.fechaIn.mes, emp.fechaIn.anio, descSector);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAlmuerzos(eAlmuerzo vecAlmuerzo[], int tamAlmuerzo)
{
    int contador = 0;
     printf("\n ID ALM ID MENU LEGAJO EMP   FECHA\n");

    for(int i=0; i < tamAlmuerzo; i++)
    {
        if(vecAlmuerzo[i].isEmpty == 1)
        {
            mostrarAlmuerzo(vecAlmuerzo,i);
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\n(!) No hay almuerzos que mostrar (!)\n");
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAlmuerzosDeUnEmpleado(eEmpleado vec[],int i,eSector vecSecttores[],int tamSectores,eAlmuerzo vecAlmuerzos[],int tamAlmuerzos)
{
    int contador = 0;
    int auxLegajo;
    int indice;
                getInt(&auxLegajo,"\nIngrese su legajo","Error, legajo invalido",1,200);
                indice=buscarEmpleado(vec,i,auxLegajo);
                if(vec[indice].isEmpty!=1)
                    {
                        printf("\nError,No se encuentra su legajo\n");

                    }
                    else
                    {

                            printf("\n ID ALM ID MENU LEGAJO EMP   FECHA\n");

                            for(int i=0; i < tamAlmuerzos; i++)
                            {
                                if(vecAlmuerzos[i].isEmpty == 1 && vec[i].legajo ==auxLegajo)
                                {
                                    mostrarAlmuerzo(vecAlmuerzos,i);
                                    contador++;
                                }

                            }



                    }

}
