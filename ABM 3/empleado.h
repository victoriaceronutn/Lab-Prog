#ifndef empleado_H_INCLUIDA//Para evitar que el compilador tire error por incluir varias veces la misma biblioteca del usuario.
#define empleado_H_INCLUIDA
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;



typedef struct
{
    int legajo;
    char apellido[51];
    char nombre[51];
    char sexo;
    float sueldo;
    eFecha fechaIn;
    int idSector;
    int isEmpty;

} eEmpleado;

typedef struct // tipo de dato tipificado.
{
    int id;
    char desc[20];
} eSector;








typedef struct // tipo de dato tipificado.
{
    int id;
    int idMenu;
    int legajoEmp;
    eFecha fechaAlmuerzo;

    int isEmpty;
} eAlmuerzo;



typedef struct // tipo de dato tipificado.
{
    int id;
    char desc[51];
    float importe;
} eMenu;



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/** \brief Function: Muestra el menu por pantalla y captura la opcion seleccionada.
*   \param Request: NULL.
*   \return Returns: Opcion elegida.
*/
int menu();


/** \brief Function: Muestra el sub menu por pantalla y captura la opcion seleccionada.
*   \param Request: NULL.
*   \return Returns: Opcion elegida.
*/
int subMenu();

/** \brief Function: Muestra el sub menu de menues por pantalla.
 *
 * \param Request: NULL.
 * \return Returns: NULL.
 *
 */
void subMenuMenues();




/** \brief Function: Inicializa la estructura seleccionada en 0.
*   \param Request: Array vec de la estructura eEmpleado.
*   \param Request: Int tamaño maximo de la estructura eEmpleado.
*   \return Returns: NULL.
*/
void inicializarEmpleados(eEmpleado vec[], int tam);




/** \brief Function: Obtiene el primer indice libre del array vec de la estructura eEmpleado.
 *  \param Request: Array vec de la estructura eEmpleado.
 *  \param Request: Int tamaño maximo de la estructura eEmpleado.
 * \return Returns: Si no hay ocurrencia (-1) y si la hay, la posición de la misma.
 *
 */
int buscarLibre(eEmpleado vec[], int tam);


/** \brief Function: Obtiene el indice que coincide con el ID pasado por parametro.
 *  \param Request: Array vec de la estructura eEmpleado.
 *  \param Request: Int valor maximo de la estructura eEmpleado.
 *  \param Request: Int ID a ser buscado en el array de la estructura eEmpleado.
 *  \return Returns: el indice en donde se encuentra el elemento que coincide con el parametro ID o (-1) si no lo encuentra.
 */
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);




/** \brief Function: Asigna datos validados a un empleado incremental dentro del array vec
 *
 * \param Request: Array vec de la estructura eEmpleado.
 * \param Request: Int tam valor maximo de la estructura eEmpleado.
 * \param Request: Array sec de la estructura eSector.
 * \param Request: Int tamSectores valor maximo de la estructura eSector.
 * \param Request: Int legajoMain valor autoincremental de la funcion Main.
 * \return Returns: Int altaOk (1) si se logro hacer el alta o (0) si no se logro el alta.
 *
 */
int altaEmpleado(eEmpleado vec[], int tam,eSector sec[],int tamSectores, int legajoMain);

/** \brief Function: Asigna a un empleado incremental dentro del array vec.isEmpty(-1).
 *
 * \param Request: Array vec de la estructura eEmpleado.
 * \param Request: Int tam valor maximo de la estructura eEmpleado.
 * \return Returns: NULL.
 *
 */
void bajaEmpleado(eEmpleado vec[], int tam);
/** \brief Function: Modifica datos validados a un empleado elegido dentro del array vec
 *
 * \param Request: Array vec de la estructura eEmpleado.
 * \param Function: Int tam valor maximo de la estructura eEmpleado.
 * \param Request: Array sec de la estructura eSector.
 * \param Request: Int tamSectores valor maximo de la estructura eSector.
 * \return Returns: NULL.
 *
 */
void modificarEmpleado(eEmpleado vec[], int tam,eSector vecSec[],int tamSectores);

/** \brief Function: muestra un empleado si este esta dado de alta.
 *
 * \param Request: Array sectores de la estructura eSector.
 * \param Request: Int tamSectores valor maximo de laestructura eSector.
 * \param Request: Array emp de la estructura eEmpleado.
 * \param Request: Int i indice de la estructura eEmpleado.
 * \return Returns: NULL.
 *
 */
void mostrarEmpleado(eSector sectores[],int tamSectores,eEmpleado emp[], int i);

/** \brief Function: muestra todos los empleados que esten dados de alta.
 * \param Request: Array sectores de la estructura eSector.
 * \param Request: Int tamSectores valor maximo de laestructura eSector.
 * \param Request: Array vec de la estructura eEmpleado.
 * \param Request: Int tam tamaño maximo de la estructura eEmpleado.
 * \return Returns: NULL.
 *
 */

void mostrarEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);

/** \brief Function: Ordena los nombres de A-Z.
 *  \param  Request: Array vec de la estructura eEmpleado.
 *  \param  Request: Int tam el tamaño maximo de la estructura eEmpleado.
 *  \return Returns: NULL.
 */
void ordenarEmpleadosApellido(eEmpleado vec[], int tam);




/** \brief Function: Inicializa la estructura seleccionada en 0.
*   \param Request: Array vec de la estructura vec.
*   \param Request: Int tam el tamaño maximo de la estructura eEmpleado.
*   \return Returns: NULL.
*/
void inicializarAlmuerzos(eAlmuerzo vec[], int tamAlmuerzo);

/** \brief Function: Obtiene el indice que coincide con el ID pasado por parametro.
 *  \param Request: Array vec de la estructura eAlmuerzo.
 *  \param Request:  Int tamAlmuerzo tamaño maximo de la estructura eAlmuerzo.
 *  \param Request:  Int id numero a ser buscado en el array.
 *  \return Returns: Int indice, el indice en donde se encuentra el elemento que coincide con el parametro ID o (-1) si no lo encuentra.
 */

int buscarAlmuerzo(eAlmuerzo vec[], int tamAlmuerzo, int id);

/** \brief Function: Obtiene el primer indice libre del array vec.
 *  \param Request: Array de la estructura vec.
 *  \param Request: Int tamaño maximo de la estructura vec.
 * \return Returns: Int Si no hay ocurrencia (-1) y si la hay, la posición de la misma (indice).
 *
 */
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tamAlmuerzo);

/** \brief Function: Asigna datos validados a un empleado incremental dentro del array vec.
 *
 * \param Request: Array vecAlmuerzo de la estructura eAlmuerzo.
 * \param Request: Int tamAlmuerzo tamaño maximo de la estructura eAlmuerzo.
 * \param Request: Array vecEmpleado de la estructura eEmpleado.
 * \param Request: Int tam valor maximo de la estructura eEmpleado.
 * \param Request: Array sec de la estructura eSector.
 * \param Request: Int tamSectores valor maximo de la estructura eSector.
 * \param Request: Int legajoMain valor autoincremental de la funcion Main.
 * \return Returns: Int altaOk (1) si se logro hacer el alta o (0) si no se logro el alta.
 *
 */
int altaAlmuerzo(eAlmuerzo vecAlmuerzo[],int tamAlmuerzo,eEmpleado vecEmpleado[], int tam,eSector sec[],int tamSectores, int legajoMain);

/** \brief Function: muestra un almuerzo si este esta dado de alta.
 *
 * \param Request: Array alm de la estructura eAlmuerzo.
 * \param Request: Int i indice de la estructura eAlmuerzo.
 * \return Returns: NULL.
 *
 */
void mostrarAlmuerzo(eAlmuerzo alm[],int i);


/** \brief Function: muestra todos los almuerzos si estan dados de alta.
 *
 * \param Request: Array vecAlmuerzo de la estructura eAlmuerzo.
 * \param Request: Int tamAlmuerzo tamaño maximo de la estructura eAlmuerzo.
 * \return Returns: NULL.
 *
 */
void mostrarAlmuerzos(eAlmuerzo vecAlmuerzo[], int tamAlmuerzo);





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/** \brief Function: Copia una descripcion en un elemento seleccionado de la estructura en eSector.desc .
 *
 * \param Request: Array sectores de la estructura eSector.
 * \param Request: Int tamSectores tamaño maximo de la estructura eSectores.
 * \param Request: Int idSectorEmp numero de id del sector de la estructura eEmpleado.
 * \param Request: Array tpo Char descMostrar descripcion que sera mostrada.
 * \return Returns: NULL.
 *
 */

void obtenerSector(eSector sectores[], int tamSectores, int idSectorEmp, char descMostrar[]);

/** \brief Function: Muestra el sector de un empleado.
 *
 * \param Request: Array vec de la estructura eEmpleado.
 * \param Request: Int tam tamaño maximo de la estructura eEmpleado.
 * \param Request: Array sec de la estructura eSector.
 * \param Request: Int tamSec tamaño maximo de la estructura eSector.
 * \param Request: Array emp de la estructura eEmpleado.
 * \return Returns: NULL.
 *
 */

void mostrarSector (eEmpleado vec[], int tam, eSector sec[], int tamSec,eEmpleado emp[]);



void mostrarAlmuerzosDeUnEmpleado(eEmpleado vec[],int i,eSector vecSecttores[],int tamSectores,eAlmuerzo vecAlmuerzos[],int tamAlmuerzos);


#endif
