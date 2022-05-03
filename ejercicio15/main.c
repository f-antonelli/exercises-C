#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    tFecha f = {29,2,2009};

    esFechaValida(&f, diasMes)
        ? diaSiguiente(&f, diasMes)
        : printf("La fecha es invalida.");
    return 0;
}
