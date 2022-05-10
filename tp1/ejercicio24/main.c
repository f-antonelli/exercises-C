#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int tam = 10;
    int vec[] = {2, 145, 657, 213, 45, 543, 231, 435, 921, 9}, num;

    mostrarVector(vec, &tam);

    do {
        printf("\n\nIngrese el elemento que desea borrar: ");
        scanf("%d", &num);
    } while(!validarNum(vec, num, tam));

    eliminarElemento(vec, num, &tam);
    printf("\nEl elemento %d fue eliminado...\n\n", num);

    mostrarVector(vec, &tam);
    return 0;
}

