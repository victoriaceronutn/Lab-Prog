#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "empleados.h"

#define TAM 5

int main()
{
        eLocalidad localidades[3];
        ePersona personas[3];

        cargarLocalidades(3,localidades);
        mostrarLocalidades(3,localidades);

        altaPersona(personas,3);

    return 0;
}
