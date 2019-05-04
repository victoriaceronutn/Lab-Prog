#include <stdio.h>
#include <stdlib.h>

int pedirOpcionMenu(char[]); // texto q va a parecer en printf.

int main() // solo llamadas a funciones.
{
    int opcion;
    char seguir='s';

    do{
        //prompt mostraba un mensaje.
        opcion=pedirOpcionMenu("1. Alta\n2. Baja\n3. Modificacion\n4. Informes\n5. salir\nElija una opcion: ");

        //menu de opciones. pasa a abajo.
        /*printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Modificacion\n");
        printf("4. Informes\n");
        printf("5. salir\n");
        printf("Elija una opcion: ");
        scanf("%d",& opcion); */

        switch(opcion)
        {
        case 1:
            printf("estoy dando de alta\n");
            break;
        case 2:
            printf("estoy dando de baja\n");
            break;
        case 3:
            printf("estoy modificando\n");
            break;
        case 4:
            printf("estoy informado\n");
            break;
        case 5:
            seguir='n';
            break;
        default:
            printf("opcion incorrecta");
            break;
        }
        system("pause");
        system("cls"); //CLS, limpia la pantalla. "refresca la pantalla"

    }while(seguir=='s');
    return 0;
}

int pedirOpcionMenu(char texto[])
{
    int opcion; // paso todo a uno.

    printf("%s",texto);
    //printf("1. Alta\n2. Baja\n3. Modificacion\n4. Informes\n5. salir\nElija una opcion: ");

    // vuelven a "DO"
    scanf("%d",& opcion);

    return opcion;

}
