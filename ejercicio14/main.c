#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    tFecha f = {1,2,2009};

    esFechaValida(&f)
        ? printf("La fecha es valida.")
        : printf("La fecha es invalida.");

    return 0;
}

