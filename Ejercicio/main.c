#include <stdio.h>
#include <stdlib.h>

void saludar (void);
int dameNumero(void);
float sacarPromedio (int suma,int cantidad); //o se puede poner int suma, int cantidad
void esPrimo (int numero);

int main()
{

    int edad;
    float altura;
    int suma;
    float promedio;
    int limite;
    saludar ();
/*
    printf("\nIngrese su edad : ");
    scanf("%d", &edad);
    printf("\nIngrese su altura : ");
    scanf("%f", &altura);
    printf("Abril \t Palomares \n");
    printf(" Su edad: %d", edad);
    printf(" Su altura es: %f", altura);*/

    int numero;
    int contador;
    contador = 0;
    suma = 0;
    limite = dameNumero();

    for(;contador < limite; contador++)
    {
        printf("\n Ingrese un numero : ");
        scanf("%d", &numero);
        suma = suma + numero;
    }
   // promedio = (float)suma / contador;
    promedio = sacarPromedio(suma,contador);
    printf("El promedio es: %f", promedio);


    return 0;
}

    void saludar (void)
    {
        printf("Hola Mundo C");
    }

    int dameNumero(void)
    {
        int cantidad;
        printf("\nIngrese la cantidad de iteraciones : ");
        scanf("%d", &cantidad);
        return cantidad;
    }

    float sacarPromedio (int suma,int cantidad)
    {
        float promedio;
        int contador=0;
        promedio = (float)suma / contador;
        return promedio;
    }
