#include <stdio.h>
#include <stdlib.h>

//1er
void claseUnoRepaso(void);

/** \brief
 * pide un numero entre 1 y 10
 * \param void
 * no tiene parametro de entrada
 * \return int
 * es el numero que debe retornar
 */
int pedirNumero(void);



/** \brief
 * saca el promedio con
 * los datos que tiene como parametros
 * \param suma int
 * \param cantidad int
 * \return float
 * el promedio retornado
 */
float sacarPromedio(int suma, int cantidad);

/** \brief
 * retorna 1 si el alumno aprobo la materi
 * retorna 0 si el alumno no aprobo la materia
 * \param notaMinima int
 * es la nota minima para aprobar la materia
 * \param nota int
 * es la nota que se saco el alumno
 * \return int
 *  0 para no aprobo
 * 1 para aprobado
 */
int sacarAprobacion(int notaMinima, int nota);




/** \brief
 * ingrese la nota de 5 alumnos (entre 0 y 10)
 * informar cuantos aprobaron
 * el promedio de notas de todos
 * el promedio de notas de los que no aprobaron
 * \return int
 *
 */
int main()
{
   claseUnoRepaso();
/*
  int elNumeroIngresado;
  float promedio;
  int estaAprobado;
  elNumeroIngresado=pedirNumero();
  printf(" el numero ingresado fue :%d",elNumeroIngresado);
  promedio=sacarPromedio(94,5);//18.79999
  printf(" el promedio fue :%f",promedio);
    estaAprobado=sacarAprobacion(6,elNumeroIngresado);
   if(estaAprobado==1)
    {
        printf("aprobo");
    }
    else{
        printf("no aprobo");
    }
*/

}
void claseUnoRepaso()
{

     int notaIngresada;
    int sumaTotal;
    int sumaNoAprobados;
    int contadorAprobados;
     int contadorDeNoAprobados;
     float promedioTotal;
     float promedioDeNoAprobados;

    sumaTotal=0;
    sumaNoAprobados=0;
    contadorAprobados=0;
    contadorDeNoAprobados=0;
    for(int i =0;i<5;i++)
    {
        notaIngresada=pedirNumero();
        sumaTotal=sumaTotal+notaIngresada;
        if(sacarAprobacion(6,notaIngresada))
        {
            contadorAprobados++;
        }else
        {
            contadorDeNoAprobados++;
            sumaNoAprobados=sumaNoAprobados+ notaIngresada;
        }

    }//fin del for
    promedioTotal=sacarPromedio(sumaTotal,i);
    promedioDeNoAprobados=sacarPromedio(sumaNoAprobados,contadorDeNoAprobados);
    printf(" cuantos aprobaron %d",contadorAprobados );
    printf("promedio de notas de todos ",promedioTotal);
    printf("promedio de notas de los que no aprobaron",promedioDeNoAprobados);

}

int sacarAprobacion(int notaMinima, int nota)
{
    int retorno;
    if( nota>= notaMinima)
    {
        retorno=1;
    }
    else{
        retorno=0;
    }
    return retorno;
    /*
         if( nota>= notaMinima)
            return 1;
        return 0;
    */
}


float sacarPromedio(int suma, int cantidad)
{
    float retorno;
    retorno = (float)suma/cantidad;
    return  retorno;
}

int pedirNumero()
{
   int miNumero;
   // proceso
    //miNumero=10;
    do{
        printf("\n ingrese numero : ");
            scanf("%d",&miNumero);

    }while(miNumero<0 || miNumero>10);
    return miNumero;
}
