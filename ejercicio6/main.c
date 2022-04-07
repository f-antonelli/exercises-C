#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    float tol, num;
    double result;

    printf("Ingrese un numero: ");
    scanf("%f", &num);

    printf("Ingrese una tolerancia: ");
    scanf("%f", &tol);

    result = obtenerSeno(num, tol);

    printf("El seno de %.0f es: %lf", num, result);

    return 0;
}
