#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int num, tol;
    double result;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("Ingrese una tolerancia: ");
    scanf("%d", &tol);

    result = obtenerSeno(num, tol);

    printf("El seno de %d es: %lf", num, result);

    return 0;
}
