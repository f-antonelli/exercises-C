#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int num, tam = 10, vec[] = {123, 23, 45, 23, 2, 23, 45, 50, 2, 123};

    mostrarVector(vec, &tam);

    do {
        printf("\n\nIngrese el numero que desea eliminar: ");
        scanf("%d", &num);
    } while(!validarNum(vec, num, tam));

    eliminarNumVector(vec, num, &tam);
    printf("\n\nEl numero %d fue eliminado del vector...\n\n", num);

    mostrarVector(vec, &tam);
    return 0;
}
